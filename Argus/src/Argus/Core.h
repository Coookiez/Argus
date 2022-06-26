#pragma once

#ifdef AS_PLATFORM_WINDOWS
	#ifdef AS_BUILD_DLL
		#define ARGUS_API __declspec(dllexport)
	#else
		#define ARGUS_API __declspec(dllimport)
	#endif
#else
	#error Argus only supports Windows!
#endif