
#ifndef __ST_DATA_OS_TYPE_H__
#define __ST_DATA_OS_TYPE_H__

#include <stdint.h>
#include <stdlib.h>
#include <string>

// recognize the OS
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined( WIN64 )
#if !defined(_STDATA_OS_WIN_)
#define _STDATA_OS_WIN_
#endif

#elif defined(__linux__) || defined(__linux) || defined(_STDATA_OS_LINUX_)
#if !defined(_STDATA_OS_UNIX_)
#define _STDATA_OS_UNIX_
#endif
#if !defined(_STDATA_OS_LINUX_)
#define _STDATA_OS_LINUX_
#endif

#else
#error "Unsupported OS!"
#endif

// Dll Export
#if defined(__lint)
#define STDATA_EXPORT      __export(UTILSBOXFoundation)
#elif defined(_STDATA_OS_WIN_)
#define  STDATA_EXPORT    __declspec(dllexport)
#elif __GNUC__ >= 4
#define STDATA_EXPORT      __attribute__ ((visibility("default")))
#else
#define STDATA_EXPORT
#endif

#endif // __STDATA_OS_TYPE_H__

