#pragma once
#ifndef __ST_CORE_CONVERT_H__
#define __ST_CORE_CONVERT_H__

#include "STCore/st_core_os_type.h"


namespace st_core {

    class STCORE_EXPORT CConvert
    {
    public:
        static int WCharToUTF8(const wchar_t* wsSrc, int iSizeSrc, char* sDest, int iSizeDest);
        static int UTF8ToWChar(const char* sSrc, int iSizeSrc, wchar_t* sDest, int iSizeDest);

        static std::wstring StringToWString(std::string str);
        static std::string WStringToString(std::wstring str);
    };

}

#endif