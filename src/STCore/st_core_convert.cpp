#include "STCore/st_core_convert.h"
#ifdef _STCORE_OS_WIN_
#include <Windows.h>
#include <ctype.h>
#else
#include <iconv.h>
#include <wctype.h>
#include <wchar.h>
#include <errno.h>
#endif
namespace st_core {

    int CConvert::WCharToUTF8(const wchar_t* wsSrc, int iSizeSrc, char* sDest, int iSizeDest)
    {
#ifdef _STCORE_OS_WIN_
        return WideCharToMultiByte(CP_UTF8,0, wsSrc,-1, sDest, iSizeDest,NULL,NULL);
#else
        size_t result;
        iconv_t env;
        env = iconv_open("UTF-8","WCHAR_T");
        if (env == (iconv_t)-1)
        {
            return -1;
        }
        result = iconv(env, (char**)&wsSrc, (size_t*)&iSizeSrc, (char**)&sDest, (size_t*)&iSizeDest);
        if (result == (size_t)-1)
        {
            return -1;
        }
        iconv_close(env);
        return (int)result;
#endif // _STCORE_OS_WIN_

    }

    int CConvert::UTF8ToWChar(const char* sSrc, int iSizeSrc, wchar_t* sDest, int iSizeDest)
    {
#ifdef _STCORE_OS_WIN_
        return MultiByteToWideChar(CP_UTF8,0, sSrc,-1, sDest, iSizeDest);
#else
        size_t result;
        iconv_t env;
        int size = strlen(sSrc) + 1;
        env = iconv_open("WCHAR_T","UTF-8");
        if (env == (iconv_t)-1)
        {
            return -1;
        }
        result = iconv(env,(char**)&sSrc, (size_t*)&iSizeSrc, (char**)&sDest, (size_t*)&iSizeDest);
        if (result == (size_t)-1)
        {
            return -1;
        }
        iconv_close(env);
        return (int)result;
#endif
    }
}