#pragma once
#include "STData/st_data_os_type.h"
#include "STData/st_data_table_define.h"

namespace st_data
{
    class STDATA_EXPORT CSTExcelOperator
    {
    public:
        static bool CreateSalesList(const std::string& sPath);

        static bool ReadProductList(const std::string& sPath, st_data::LISTPRODUCT& pd);
    };


}
