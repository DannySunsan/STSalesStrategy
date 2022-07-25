#pragma once

#include "STData/st_data_sql_wrapper.h"
#include "STCore/st_core_sigleton_template.h"

namespace st
{
    class STDATA_EXPORT CSchemaManager:
        public st_core::CSigleton<CSchemaManager>
    {
    public:
        int InitSchema();
 /*   protected:*/
        CSchemaManager() {};
        ~CSchemaManager() {};
    private:
        CSqlWrapper* m_sql;
    };
}