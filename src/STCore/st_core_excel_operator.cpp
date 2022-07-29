#include "STCore/st_core_excel_operator.h"
#include "STCore/st_core_excel.h"

namespace st_core
{
    bool CSTExcelOperator::CreateSalesList(const std::string& sPath)
    {
        CSTExcel excel;







        return excel.Save(sPath);

    }

    bool CSTExcelOperator::ReadProductList(const std::string& sPath)
    {
        CSTExcel excel;
        excel.Load(sPath);

    }

}
