#pragma once


#ifdef MAGNUM_PLATFORM_WINDOWS

extern Magnum::Application* Magnum::CreateApplication();

int main(int argc, char** argv)
{
	Magnum::Log::Init();
	MAGNUM_CORE_WARN("Initialized Log!");
	int a = 5;
	MAGNUM_INFO("Hello! Var={0}", a);

	auto app = Magnum::CreateApplication();
	app->Run();
	delete app;
}

#endif