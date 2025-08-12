#include <Magnum.h>

class Sandbox : public Magnum::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Magnum::Application* Magnum::CreateApplication() 
{
	return new Sandbox();
}

