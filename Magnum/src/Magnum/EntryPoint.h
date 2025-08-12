#pragma once


#ifdef MAGNUM_PLATFORM_WINDOWS

extern Magnum::Application* Magnum::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Magnum::CreateApplication();
	app->Run();
	delete app;
}

#endif