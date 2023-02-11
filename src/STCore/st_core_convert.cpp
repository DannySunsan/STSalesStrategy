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

    std::wstring MByteToWChar(const std::string& str , UINT codePage)
    {
        std::wstring result;
        uint64_t len = MultiByteToWideChar(codePage, 0, str.c_str(), str.size(), NULL, 0);
        wchar_t* buffer = new wchar_t[len + 1];
        MultiByteToWideChar(codePage, 0, str.c_str(), str.size(), buffer, len);
        buffer[len] = '\0';
        result.append(buffer);
        delete[] buffer;
        return result;
    }
    
    std::string WCharToMByte(const std::wstring& str, UINT codePage)
    {
        std::string result;
        uint64_t len = WideCharToMultiByte(codePage, 0, str.c_str(), str.size(), NULL, 0, NULL, NULL);
        char* buffer = new char[len + 1];
        WideCharToMultiByte(codePage, 0, str.c_str(), str.size(), buffer, len, NULL, NULL);
        buffer[len] = '\0';
        result.append(buffer);
        delete[] buffer;
        return result;
    }

    std::wstring CConvert::UTF8ToWString(const std::string& str)
    {
        return MByteToWChar(str, CP_UTF8);       
    }

    std::string CConvert::WStringToUTF8(const std::wstring& str)
    {
        return WCharToMByte(str, CP_UTF8);
    }

    std::wstring CConvert::StringToWString(const std::string& str)
    {
        return MByteToWChar(str, CP_ACP);
    }

    std::string CConvert::WStringToString(const std::wstring& str)
    {
        return WCharToMByte(str, CP_ACP);
    }
}