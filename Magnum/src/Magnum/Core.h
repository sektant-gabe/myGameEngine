#pragma once


#ifdef MAGNUM_PLATFORM_WINDOWS
    #ifdef MAGNUM_BUILD_DLL
        #define MAGNUM_API __declspec(dllexport)
    #else
		#define MAGNUM_API __declspec(dllimport)
    #endif
#else
	#error This Engine only supports Windows!
#endif
