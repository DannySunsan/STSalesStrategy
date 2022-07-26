
#include "STData/st_data_schema_manager.h"
#include "STCore/st_core_convert.h"

namespace st
{
    CSchemaManager::CSchemaManager():m_sql(NULL)
    {

    }

    int CSchemaManager::InitSchema()
    {
        int iRet = m_sql->OpenDB(ST_DBFILE);
        if (iRet)
        {
            return iRet;
        }
    }

    const std::string& CSchemaManager::GetErrorMsg()
    {
        return m_sql->GetLastErrMsg();
    }

    int CSchemaManager::AddCompany(const st::STCOMPANY& cp)
    {
        m_Mutex.Lock();
        int iRet = 0;
        wchar_t wSql[255];
        swprintf_s(wSql, L"INSERT INTO stSale.sale_company \
            [(name, position)] \
            VALUES(%s,%s)",cp.strName.c_str(),cp.strPosition.c_str());
        char sSql[255];
        st_core::CConvert::WCharToUTF8(wSql,255, sSql,255);
        m_sql->Execute(sSql);
        m_Mutex.UnLock();
        return iRet;
    }

    int CSchemaManager::AddStrategy(const st::STSTRATEGY st)
    {
        m_Mutex.Lock();
        int iRet = 0;
        wchar_t wSql[255];
        
        swprintf_s(wSql, L"INSERT INTO stSale.sale_strategy \
            [(name, describe,company_id,off_type,off_percent)] \
            VALUES(%s,%s,%d,%d,%lf)", st.strName.c_str(), st.strDescribe.c_str(),st.iCompanyId, (int)st.bTotalOff, st.dOffPercent);
        char sSql[255];
        st_core::CConvert::WCharToUTF8(wSql, 255, sSql, 255);
        iRet = m_sql->Execute(sSql);
        m_Mutex.UnLock();
        return iRet;
    }

    int CSchemaManager::AddProduct(const st::STPRODUCT pd)
    {
        m_Mutex.Lock();
        int iRet = 0;
        wchar_t wSql[255];

        swprintf_s(wSql, L"INSERT INTO stSale.sale_product \
            [(name, version_id)] \
            VALUES(%s,%d)", pd.strName.c_str(), pd.iVerId);
        char sSql[255];
        st_core::CConvert::WCharToUTF8(wSql, 255, sSql, 255);
        iRet = m_sql->Execute(sSql);
        m_Mutex.UnLock();
        return iRet;
    }

    int CSchemaManager::AddService(const st::STSERVICE sv)
    {
        m_Mutex.Lock();
        int iRet = 0;
        wchar_t wSql[255];

        swprintf_s(wSql, L"INSERT INTO stSale.sale_product_service \
            [(product_id,name, describe,price,default_off_percent,lock)] \
            VALUES(%d,%s,%s,%lf,%lf,%s)", sv.iProductId, sv.strName.c_str(), sv.strDescribe.c_str(), sv.dPrice, sv.default_off_Percent, sv.strLock.c_str());
        char sSql[255];
        st_core::CConvert::WCharToUTF8(wSql, 255, sSql, 255);
        iRet = m_sql->Execute(sSql);
        m_Mutex.UnLock();
        return iRet;
    }

    int CSchemaManager::AddVersion(const st::STVERSION ver)
    {
        m_Mutex.Lock();
        int iRet = 0;
        wchar_t wSql[255];

        swprintf_s(wSql, L"INSERT INTO stSale.sale_version \
            [(name)] \
            VALUES(%s)", ver.strName.c_str());
        char sSql[255];
        st_core::CConvert::WCharToUTF8(wSql, 255, sSql, 255);
        iRet = m_sql->Execute(sSql);
        m_Mutex.UnLock();
        return iRet;
    }

    int CSchemaManager::GetCompany(std::wstring csName, LISTCOMPANY& lstCo)
    {
        m_Mutex.Lock();
        int iRet = 0;
        wchar_t wSql[255];
        swprintf_s(wSql, L"SELECT * FROM stSale.sale_company \
           where name like '%%%s%%' OR position like '%%%s%%'", csName.c_str(), csName.c_str());
        char sSql[255];
        st_core::CConvert::WCharToUTF8(wSql, 255, sSql, 255);
        iRet = m_sql->Execute(sSql);

        m_Mutex.UnLock();
        return iRet;
    }

    int CSchemaManager::GetStrategy(int iCoID, LISTSTSTRATEGY& lstSt)
    {
        m_Mutex.Lock();
        int iRet = 0;
        wchar_t wSql[255];
        swprintf_s(wSql, L"SELECT * FROM stSale.sale_strategy \
           where company_id = '%d'", iCoID);
        char sSql[255];
        st_core::CConvert::WCharToUTF8(wSql, 255, sSql, 255);
        iRet = m_sql->Execute(sSql);

        m_Mutex.UnLock();
        return iRet;
    }

    int CSchemaManager::GetProduct(int iVerID, LISTPRODUCT& lstProduct)
    {
        m_Mutex.Lock();
        int iRet = 0;
        wchar_t wSql[255];
        swprintf_s(wSql, L"SELECT * FROM stSale.sale_product \
           where version_id = '%d'", iVerID);
        char sSql[255];
        st_core::CConvert::WCharToUTF8(wSql, 255, sSql, 255);
        iRet = m_sql->Execute(sSql);

        m_Mutex.UnLock();
        return iRet;
    }

    int CSchemaManager::GetService(int iProductID, LISTSERVICE& lstServ)
    {
        m_Mutex.Lock();
        int iRet = 0;
        wchar_t wSql[255];
        swprintf_s(wSql, L"SELECT * FROM stSale.sale_product_service \
           where product_id = '%d'", iProductID);
        char sSql[255];
        st_core::CConvert::WCharToUTF8(wSql, 255, sSql, 255);
        iRet = m_sql->Execute(sSql);
        if (0 == iRet)
        {

        }


        m_Mutex.UnLock();
        return iRet;
    }

    int CSchemaManager::GetVersion(LISTVERSION& lstVer)
    {
        m_Mutex.Lock();
        int iRet = 0;
        char sSql[255] = "SELECT * FROM stSale.sale_version";
        iRet = m_sql->Execute(sSql);

        m_Mutex.UnLock();
        return iRet;
    }
}