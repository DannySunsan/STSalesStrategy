
#include "STData/st_data_schema_manager.h"
#include "STCore/st_core_convert.h"

namespace st_data
{
    CSchemaManager::CSchemaManager():m_sql(NULL)
    {
        m_sql = new CSqlWrapper();
        InitSchema();
    }

    int CSchemaManager::InitSchema()
    {
        return m_sql->OpenDB(ST_DBFILE);
    }

    const std::string& CSchemaManager::GetErrorMsg()
    {
        return m_sql->GetLastErrMsg();
    }

    int CSchemaManager::AddCompany(const st_data::STCOMPANY& cp)
    {
        m_Mutex.Lock();
        int iRet = 0;
        wchar_t wSql[255];
        swprintf_s(wSql, L"INSERT INTO stSale.sale_company \
            [(name, position)] \
            VALUES(%s,%s)",cp.strName.c_str(),cp.strPosition.c_str());
        std::string sSql = st_core::CConvert::WStringToUTF8(wSql);
        m_sql->Execute(sSql);
        m_Mutex.UnLock();
        return iRet;
    }

    int CSchemaManager::AddStrategy(const st_data::STSTRATEGY& st)
    {
        m_Mutex.Lock();
        int iRet = 0;
        wchar_t wSql[255];
        
        swprintf_s(wSql, L"INSERT INTO stSale.sale_strategy \
            [(name, describe,company_id,off_percent)] \
            VALUES(%s,%s,%d,%d,%lf)", st.strName.c_str(), st.strDescribe.c_str(),st.iCompanyId, st.dOffPercent);
        char sSql[255];
        st_core::CConvert::WCharToUTF8(wSql, 255, sSql, 255);
        iRet = m_sql->Execute(sSql);
        m_Mutex.UnLock();
        return iRet;
    }

    int CSchemaManager::AddProduct(const st_data::STPRODUCT& pd)
    {
        m_Mutex.Lock();
        int iRet = 0;
        wchar_t wSql[255];

        swprintf_s(wSql, L"INSERT INTO stSale.sale_product \
            [(name, version_id)] \
            VALUES(%s,%d)", pd.strName.c_str(), pd.iVerId);
        std::string sSql = st_core::CConvert::WStringToUTF8(wSql);
        iRet = m_sql->Execute(sSql);
        m_Mutex.UnLock();
        return iRet;
    }

    int CSchemaManager::AddService(const st_data::STSERVICE& sv)
    {
        m_Mutex.Lock();
        int iRet = 0;
        wchar_t wSql[255];

        swprintf_s(wSql, L"INSERT INTO stSale.sale_product_service \
            [(product_id,name, describe,price,default_off_percent,lock)] \
            VALUES(%d,%s,%s,%lf,%lf,%s)", sv.iProductId, sv.strName.c_str(), sv.strDescribe.c_str(), sv.dPrice, sv.default_off_Percent, sv.strLock.c_str());
        std::string sSql = st_core::CConvert::WStringToUTF8(wSql);
        iRet = m_sql->Execute(sSql);
        m_Mutex.UnLock();
        return iRet;
    }

    int CSchemaManager::AddVersion(const st_data::STVERSION& ver)
    {
        m_Mutex.Lock();
        int iRet = 0;
        wchar_t wSql[255];

        swprintf_s(wSql, L"INSERT INTO stSale.sale_version \
            [(name)] \
            VALUES(%s)", ver.strName.c_str());
        std::string sSql = st_core::CConvert::WStringToUTF8(wSql);
        iRet = m_sql->Execute(sSql);
        m_Mutex.UnLock();
        return iRet;
    }

    int CSchemaManager::AddStrategyService(const st_data::LISTSTRATEGYSERVICE& m_lstStService)
    {
        m_Mutex.Lock();
        int iRet = 0;
        wchar_t wSql[255];

        /*swprintf_s(wSql, L"INSERT INTO stSale.sale_version \
            [(name)] \
            VALUES(%s)", ver.strName.c_str());*/
        std::string sSql = st_core::CConvert::WStringToUTF8(wSql);
        iRet = m_sql->Execute(sSql);
        m_Mutex.UnLock();
        return iRet;
    }

    int CSchemaManager::GetCompany(LISTCOMPANY& lstCo)
    {
        m_Mutex.Lock();
        int iRet = 0;
        char sSql[255];
        sprintf_s(sSql, "SELECT * FROM stSale.sale_company");
        iRet = m_sql->Execute(sSql);

        m_Mutex.UnLock();
        return iRet;
    }

    int CSchemaManager::GetStrategy(int iCoID, LISTSTRATEGY& lstSt)
    {
        m_Mutex.Lock();
        int iRet = 0;

        char sSql[255];
        sprintf_s(sSql, "SELECT * FROM stSale.sale_strategy \
           where company_id = '%d'", iCoID);
        iRet = m_sql->Execute(sSql);

        m_Mutex.UnLock();
        return iRet;
    }

    int CSchemaManager::GetProduct(int iVerID, LISTPRODUCT& lstProduct)
    {
        m_Mutex.Lock();
        int iRet = 0;

        char sSql[255];
        sprintf_s(sSql, "SELECT * FROM stSale.sale_product \
           where version_id = '%d'", iVerID);
        iRet = m_sql->Execute(sSql);

        m_Mutex.UnLock();
        return iRet;
    }

    int CSchemaManager::GetService(int iProductID, LISTSERVICE& lstServ)
    {
        m_Mutex.Lock();
        int iRet = 0;

        char sSql[255];
        sprintf_s(sSql, "SELECT * FROM stSale.sale_product_service \
           where product_id = '%d'", iProductID);
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

    int CSchemaManager::GetStrategyService(int iStrategy, st_data::LISTSTRATEGYSERVICE& m_lstStService)
    {
        m_Mutex.Lock();
        int iRet = 0;
        char sSql[255] = "SELECT * FROM stSale.sale_strategy_service";
        iRet = m_sql->Execute(sSql);

        m_Mutex.UnLock();
        return iRet;
    }

    int CSchemaManager::Begin()
    {
        return m_sql->Begin();
    }

    int CSchemaManager::Commit()
    {
        return m_sql->Commit();
    }

    int CSchemaManager::RollBack()
    {
        return m_sql->RollBack();
    }
}