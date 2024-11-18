#pragma once
#include <stdlib.h>

// Define KL_API based on the platform and whether the library is being built or used.
// This should only be necessary only if the platform is windows otherwise the other
// function (__attribute__((visiblity("default")))) can work as well for other unix-like systems.
#ifdef KL_PLATFORM_WINDOWS
	#ifdef KL_ENGINE_EXPORT
		#define KL_API __declspec(dllexport)
	#else
		#define KL_API __declspec(dllimport)
	#endif
#else
	#define KL_API __attribute__((visibility("default")))
#endif

//#ifdef KL_ENABLE_ASSERTS
//	#define KL_ASSERT(x, ...) {if (!(x)) {KL_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
//	#define KL_CLIENT_ASSERT(x, ...) {if (!(x)) {KL_CLIENT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
//#else
//	#define KL_ASSERT(x, ...)
//	#define KL_CLIENT_ASSERT(x, ...)
//#endif


// This is a bitshift operator where if someone puts a value here, it'll be shifted by one.
// This apparently allows the events to have multiple categories.
#define BIT(x) (1 << x)