#pragma once
#include <string>
#include "STCore/st_core_mutex.h"
#include "STData/st_data_os_type.h"
#include "sqlite/sqlite3.h"

namespace st_data
{
    class STDATA_EXPORT CStatement
    {
    public:
        CStatement(sqlite3* pDb);
        ~CStatement();

        int PrepareStmt(const std::string& sSql);
        int Bind_Text(const std::string& sText);
        int Bind_Int(int iValue);
        int Bind_Double(double dValue);
        int Step();
        int Reset();
        int Finalize();
    private:
        sqlite3_stmt* m_pStmt;
        sqlite3* m_pDb;
        int m_iCol;
    };
}