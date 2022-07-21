#pragma once
#include <string>

namespace st
{
    struct STPRODUCTTABLE
    {
        std::wstring strName;
        std::wstring strDescribe;
        double dPrice;
        double lowest_off_Percent;
        double off_Percent;
        double off_Price;
        unsigned int uiQuantity;
        std::wstring strDomain;
        std::wstring strVersion;
    };
}
