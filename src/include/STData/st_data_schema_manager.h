#pragma once
#include "STData/st_data_table_define.h"
#include "STData/st_data_sql_wrapper.h"
#include "STCore/st_core_sigleton_template.h"
#include "STCore/st_core_mutex.h"

namespace st_data
{
    class STDATA_EXPORT CSchemaManager:
        public st_core::CSigleton<CSchemaManager>
    {
    public:
        int InitSchema();
        //add
        int AddCompany(const st_data::STCOMPANY& cp);
        int AddStrategy(const st_data::STSTRATEGY& st);
        int AddProduct(const st_data::STPRODUCT& pd);
        int AddService(const st_data::STSERVICE& pd);
        int AddVersion(const st_data::STVERSION& ver);
        int AddStrategyService(const st_data::LISTSTRATEGYSERVICE& m_lstStService);
        //edit
        int GetCompany(LISTCOMPANY& lstCo);
        int GetStrategy(int iCoID, LISTSTRATEGY& lstSt);
        int GetProduct(int iVerID, LISTPRODUCT& lstProduct);
        int GetService(int iProductID, LISTSERVICE& lstServ);
        int GetVersion(LISTVERSION& lstVer);
        int GetStrategyService(int iStrategy, st_data::LISTSTRATEGYSERVICE& m_lstStService);

        const std::string& GetErrorMsg();
        //delete

        int Begin();
        int Commit();
        int RollBack();

        CSchemaManager();
        ~CSchemaManager() {};
    private:
        CSqlWrapper* m_sql;
        st_core::CMutex m_Mutex;
    };
}