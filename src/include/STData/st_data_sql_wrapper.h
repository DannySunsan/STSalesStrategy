#pragma once
#include <string>
#include "STCore/st_core_mutex.h"
#include "STData/st_data_os_type.h"
#include "sqlite/sqlite3.h"
#include "st_data_statement.h"

namespace st_data
{
    class STDATA_EXPORT CSqlWrapper
    {
    public:
        CSqlWrapper();
        ~CSqlWrapper();

        int OpenDB(std::string sPath);
        int Execute(std::string sSql);
        std::string GetLastErrMsg();
        int GetValue(char** argv);
        
        int Begin();
        int Commit();
        int RollBack();
    private:
        sqlite3* m_pDb;
        sqlite3_stmt* m_pStmt;
        bool m_bIsOK;
        char m_sErrMsg[255] ;
    };
}
