
#pragma once

#if defined(_WIN32)
	#if defined(EXPORT_API)
		#define API __declspec(dllexport)
	#else
		#define API __declspec(dllimport)
	#endif
#else
	#define API
#endif
