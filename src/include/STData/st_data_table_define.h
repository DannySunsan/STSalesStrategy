#pragma once
#include <string>
#include <vector>
namespace st_data
{
    struct STVERSION
    {
        int iId;
        std::wstring strName;
        std::wstring strTime;
    };
    typedef std::vector<STVERSION> LISTVERSION;

    struct STCOMPANY
    {
        int iId;
        std::wstring strName;
        std::wstring strPosition;
    };
    typedef std::vector<STCOMPANY> LISTCOMPANY;

    struct STPRODUCT
    {
        int iId;
        int iVerId;
        std::wstring strName;       
        double d_defaut_off_Percent;       
    };
    typedef std::vector<STPRODUCT> LISTPRODUCT;

    struct STSERVICE//module
    {
        int iId;
        int iProductId;
        std::wstring strName;
        std::wstring strDescribe;
        double dPrice;
        double default_off_Percent;
        std::wstring strLock;
    };

    typedef std::vector<STSERVICE> LISTSERVICE;

    struct STSTRATEGY
    {
        int iId;
        std::wstring strName;
        std::wstring strDescribe;
        int iCompanyId;
        std::wstring strCreateTime;
        LISTSERVICE lstService;
        double dOffPercent;
        double dFinalPrice;
    };
    typedef std::vector<STSTRATEGY> LISTSTRATEGY;

    struct STSTRATEGYSERVICE
    {
        int iId;
        int iStrateguId;
        int iServiceId;
        int iNumber;
        double dOffPercent;
    };
    typedef std::vector<STSTRATEGYSERVICE> LISTSTRATEGYSERVICE;

    const std::string ST_DBFILE = "../../data/STData/DB/stSale.db";

}
