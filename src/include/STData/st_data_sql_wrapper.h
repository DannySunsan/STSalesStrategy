#pragma once
#include <string>
#include "STCore/st_core_mutex.h"
#include "STData/st_data_os_type.h"
#include "sqlite/sqlite3.h"

namespace st
{
    class STDATA_EXPORT CSqlWrapper
    {
    public:
        int OpenDB(std::string sPath);
        int Execute(std::string sSql);
        std::string GetLastErrMsg();
        int GetValue(char** argv);
    protected:
        CSqlWrapper();
        ~CSqlWrapper();
    private:
        sqlite3* m_pDb;
        bool m_bIsOK;
        char m_sErrMsg[255] ;
    };
}
