#include <Argus.h>

class Sandbox : public Argus::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Argus::Application* Argus::CreateApplication()
{
	return new Sandbox();
}