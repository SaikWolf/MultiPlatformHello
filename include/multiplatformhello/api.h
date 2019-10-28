
#ifndef INCLUDED_MULTIPLATFORMHELLO_H
#define INCLUDED_MULTIPLATFORMHELLO_H

#include <string>

#if defined(__clang__)
	/* Clang/LLVM. ---------------------------------------------- */
#define COMPILER_NAME "clang"
#define COMPILER 3
#elif defined(__ICC) || defined(__INTEL_COMPILER)
	/* Intel ICC/ICPC. ------------------------------------------ */
#define COMPILER_NAME "intel"
#define COMPILER 4
#elif defined(__GNUC__) || defined(__GNUG__)
	/* GNU GCC/G++. --------------------------------------------- */
#define COMPILER_NAME "gnu"
#define COMPILER 1
#elif defined(__HP_cc) || defined(__HP_aCC)
	/* Hewlett-Packard C/aC++. ---------------------------------- */
#define COMPILER_NAME "hp"
#define COMPILER 5
#elif defined(__IBMC__) || defined(__IBMCPP__)
	/* IBM XL C/C++. -------------------------------------------- */
#define COMPILER_NAME "ibm"
#define COMPILER 6
#elif defined(_MSC_VER)
	/* Microsoft Visual Studio. --------------------------------- */
#define COMPILER_NAME "msvc"
#define COMPILER 2
#pragma warning(disable: 4251) // class 'A<T>' needs to have dll-interface to be used by clients of class 'B' 
#elif defined(__PGI)
	/* Portland Group PGCC/PGCPP. ------------------------------- */
#define COMPILER_NAME "portland"
#define COMPILER 7
#elif defined(__SUNPRO_C) || defined(__SUNPRO_CC)
	/* Oracle Solaris Studio. ----------------------------------- */
#define COMPILER_NAME "oracle"
#define COMPILER 8
#else
#define COMPILER_NAME ""
#define COMPILER 0
#endif

#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
#define PLATFORM_NAME "windows"
#define PLATFORM 2
#elif defined(__ANDROID__)
#define PLATFORM_NAME "android"
#define PLATFORM 4
#elif defined(__linux__)
#define PLATFORM_NAME "linux"
#define PLATFORM 1
#elif defined(__unix__) || !defined(__APPLE__) && defined(__MACH__)
#include <sys/param.h>
#if defined(BSD)
#define PLATFORM_NAME "bsd" // FreeBSD, NetBSD, OpenBSD, DragonFly BSD
#define PLATFORM 5
#endif
#elif defined(__APPLE__) && defined(__MACH__) // Apple OSX and iOS (Darwin)
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR == 1
#define PLATFORM_NAME "ios" // Apple iOS
#define PLATFORM 6
#elif TARGET_OS_IPHONE == 1
#define PLATFORM_NAME "ios" // Apple iOS
#define PLATFORM 6
#elif TARGET_OS_MAC == 1
#define PLATFORM_NAME "osx" // Apple OSX
#define PLATFORM 3
#endif
#elif defined(__sun) && defined(__SVR4)
#define PLATFORM_NAME "solaris" // Oracle Solaris, Open Indiana
#define PLATFORM 7
#else
#define PLATFORM_NAME NULL
#define PLATFORM 0
#endif

// Return a name of platform, if determined, otherwise - an empty string
inline std::string get_platform() {
    return std::string(PLATFORM_NAME);
}

// Return a name of compiler, if determined, otherwise - an empty string
inline std::string get_compiler() {
    return std::string(COMPILER_NAME);
}


#if COMPILER == 1
#if __GNUC__ >= 4
#define MULTIPLATFORMHELLO_API __attribute__((visibility("default")))
#else
#define MULTIPLATFORMHELLO_API
#endif
#elif COMPILER == 2
#ifdef MULTIPLATFORMHELLO_EXPORT
#define MULTIPLATFORMHELLO_API __declspec(dllexport)
#else
#define MULTIPLATFORMHELLO_API __declspec(dllimport)
#endif
#elif COMPILER == 3
#define MULTIPLATFORMHELLO_API __attribute__((visibility("default")))
#else
#define MULTIPLATFORMHELLO_API
#endif





#endif /* INCLUDED_MULTIPLATFORMHELLO_H */