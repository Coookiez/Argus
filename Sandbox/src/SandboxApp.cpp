#include <Argus.h>

class ExampleLayer : public Argus::Layer
{
public:
	ExampleLayer()
		: Layer("Example") {}


	void OnUpdate() override
	{
		if (Argus::Input::IsKeyPressed(AS_KEY_TAB))
			AS_TRACE("Tab key is pressed (poll)!");
	}

	void OnEvent(Argus::Event& event) override
	{
		if (event.GetEventType() == Argus::EventType::KeyPressed)
		{
			Argus::KeyPressedEvent& e = (Argus::KeyPressedEvent&)event;
			if (e.GetKeyCode() == AS_KEY_TAB)
				AS_TRACE("Tab key is pressed (event)!");

			AS_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class Sandbox : public Argus::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Argus::Application* Argus::CreateApplication()
{
	return new Sandbox();
}