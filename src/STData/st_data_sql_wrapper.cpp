#include "STData/st_data_sql_wrapper.h"
#include "STData/st_data_table_define.h"

namespace st_data
{
    char** g_sql_argv = NULL;
    int g_sql_argc = 0;

    static int callback(void* NotUsed, int argc, char** argv, char** azColName) 
    {
        g_sql_argv = argv;
        g_sql_argc = argc;
        return 0;
    }

    int CSqlWrapper::GetValue(char** argv)
    {
        argv = g_sql_argv;
        return g_sql_argc;
    }

    CSqlWrapper::CSqlWrapper() :
        m_pDb(NULL), m_bIsOK(false),
        m_sErrMsg(), m_pStmt(NULL)
    {
    }

    CSqlWrapper::~CSqlWrapper()
    {
        if (nullptr != m_pDb)
        {
            sqlite3_close(m_pDb);
        }
    }

    int CSqlWrapper::OpenDB(std::string sPath)
    {
        int iRt = sqlite3_open16(sPath.c_str(), &m_pDb);
        if (SQLITE_OK != iRt) {
            fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(m_pDb));
            return iRt;
        }
        else {
            m_bIsOK = true;
            fprintf(stderr, "Opened database successfully\n");
        }
        return iRt;
    }

    int CSqlWrapper::Execute(std::string sSql)
    {
        /* Execute SQL statement */
        char* zErrMsg = 0;
        int iRt = sqlite3_exec(m_pDb, sSql.c_str(), callback, 0, &zErrMsg);
        if (iRt != SQLITE_OK) {
            memset(m_sErrMsg,0,255);
            sprintf_s(m_sErrMsg, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }
        else {
            fprintf(stdout, "Records Excute successfully\n");
        }
        return iRt;
    }

    std::string CSqlWrapper::GetLastErrMsg()
    {
        return m_sErrMsg;
    }

    int CSqlWrapper::Begin()
    {
        return Execute("begin transaction");
    }

    int CSqlWrapper::Commit()
    {
        return Execute("commit transaction");
    }

    int CSqlWrapper::RollBack()
    {
        return Execute("rollback transaction");
    }
}