#pragma once
#ifndef __ST_CORE_CONVERT_H__
#define __ST_CORE_CONVERT_H__

#include "STCore/st_core_os_type.h"


namespace st_core {

    class STCORE_EXPORT CConvert
    {
    public:
        static std::wstring UTF8ToWString(const std::string& str);
        static std::string WStringToUTF8(const std::wstring& str);

        static std::wstring StringToWString(const std::string& str);
        static std::string WStringToString(const std::wstring& str);
    };

}

#endif