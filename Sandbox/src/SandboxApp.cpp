#include <Argus.h>

class ExampleLayer : public Argus::Layer
{
public:
	ExampleLayer()
		: Layer("Example") {}


	void OnUpdate() override
	{
		AS_INFO("ExampleLayer::Update");
	}

	void OnEvent(Argus::Event& event) override
	{
		AS_TRACE("{0}", event);
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