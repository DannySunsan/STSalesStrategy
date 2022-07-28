#include "STData/st_data_statement.h"

namespace st_data
{
    CStatement::CStatement(sqlite3* pDb) :
        m_pDb(pDb),m_pStmt(NULL), m_iCol(1)
    {

    }

    CStatement::~CStatement()
    {

    }

    int CStatement::PrepareStmt(const std::string& sSql)
    {
        return sqlite3_prepare_v2(m_pDb, sSql.c_str(), sSql.length(), &m_pStmt, NULL);
    }

    int CStatement::Bind_Text(const std::string& sText)
    {
        return sqlite3_bind_text(m_pStmt, m_iCol++, sText.c_str(), sText.length(),NULL);
    }

    int CStatement::Bind_Int(int iValue)
    {
        return sqlite3_bind_int(m_pStmt, m_iCol++, iValue);
    }

    int CStatement::Bind_Double(double dValue)
    {
        return sqlite3_bind_double(m_pStmt, m_iCol++, dValue);
    }

    int CStatement::Step()
    {
        return sqlite3_step(m_pStmt);
    }

    int CStatement::Reset()
    {
        return sqlite3_reset(m_pStmt);
    }

    int CStatement::Finalize()
    {
        return sqlite3_finalize(m_pStmt);
    }
}
