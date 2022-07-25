#pragma once
#include <string>
#include <list>
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
    typedef std::list<STPRODUCTTABLE> LISTPRODUCT;

    const std::string ST_DBFILE = "../data/STData/DB/stSale.db";
}
