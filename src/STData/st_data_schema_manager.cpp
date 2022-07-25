
#include "STData/st_data_schema_manager.h"
#include "STData/st_data_table_define.h"

namespace st
{
    int CSchemaManager::InitSchema()
    {
        return m_sql->OpenDB(ST_DBFILE);
    }
}