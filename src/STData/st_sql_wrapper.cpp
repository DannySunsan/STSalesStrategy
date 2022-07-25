#include "STData/st_data_sql_wrapper.h"
#include "STData/st_data_table_define.h"
namespace st
{
    static int callback(void* NotUsed, int argc, char** argv, char** azColName) {
        int i;
        for (i = 0; i < argc; i++) {
            printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
        }
        printf("\n");
        return 0;
    }

    CSqlWrapper::CSqlWrapper() :m_pDb(nullptr), m_bIsOK(false)
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
        int iRt = sqlite3_open(sPath.c_str(), &m_pDb);
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
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }
        else {
            fprintf(stdout, "Records Excute successfully\n");
        }
        return iRt;
    }
}