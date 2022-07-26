#pragma once
#include "STData/st_data_table_define.h"
#include "STData/st_data_sql_wrapper.h"
#include "STCore/st_core_sigleton_template.h"
#include "STCore/st_core_mutex.h"

namespace st
{
    class STDATA_EXPORT CSchemaManager:
        public st_core::CSigleton<CSchemaManager>
    {
    public:
        int InitSchema();
        //add
        int AddCompany(const st::STCOMPANY& cp);
        int AddStrategy(const st::STSTRATEGY st);
        int AddProduct(const st::STPRODUCT pd);
        int AddService(const st::STSERVICE pd);
        int AddVersion(const st::STVERSION ver);
        //edit
        int GetCompany(std::wstring csName, LISTCOMPANY& lstCo);
        int GetStrategy(int iCoID, LISTSTSTRATEGY& lstSt);
        int GetProduct(int iVerID, LISTPRODUCT& lstProduct);
        int GetService(int iProductID, LISTSERVICE& lstServ);
        int GetVersion(LISTVERSION& lstVer);

        const std::string& GetErrorMsg();
        //delete

        CSchemaManager();
        ~CSchemaManager() {};
    private:
        CSqlWrapper* m_sql;
        st_core::CMutex m_Mutex;
    };
}