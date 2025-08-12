#pragma once
#include "Core.h"

namespace Magnum {

	class MAGNUM_API Application
	{
	public:
		Application();
		virtual ~Application();  //its virtual because it will be inherited while subclassed by the sandbox application

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}