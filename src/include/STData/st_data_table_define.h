#pragma once
#include <string>
#include <list>
namespace st
{
    struct STVERSION
    {
        int iId;
        std::wstring strName;
        std::wstring strTime;
    };
    typedef std::list<STVERSION> LISTVERSION;

    struct STCOMPANY
    {
        int iId;
        std::wstring strName;
        std::wstring strPosition;
    };
    typedef std::list<STCOMPANY> LISTCOMPANY;

    struct STPRODUCT
    {
        int iId;
        int iVerId;
        std::wstring strName;       
        double d_defaule_off_Percent;       
    };
    typedef std::list<STPRODUCT> LISTPRODUCT;

    struct STSERVICE
    {
        int iId;
        int iProductId;
        std::wstring strName;
        std::wstring strDescribe;
        double dPrice;
        double default_off_Percent;
        std::wstring strLock;

        double dOffPercent;
        int iNumber;
    };

    typedef std::list<STSERVICE> LISTSERVICE;

    struct STSTRATEGY
    {
        int iId;
        std::wstring strName;
        std::wstring strDescribe;
        int iCompanyId;
        std::wstring strCreateTime;
        LISTSERVICE lstService;
        bool bTotalOff;
        double dOffPercent;
        double dFinalPrice;
    };
    typedef std::list<STSTRATEGY> LISTSTSTRATEGY;

    const std::string ST_DBFILE = "../data/STData/DB/stSale.db";
}
