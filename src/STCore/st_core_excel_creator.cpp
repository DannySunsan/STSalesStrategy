#include "STCore/st_core_excel_creator.h"
#include "STCore/st_core_excel.h"

namespace st_core
{

    bool CSTExcelCreator::CreateSalesList(const std::string& sPath)
    {
        CSTExcel excel;







        excel.Save(sPath);

    }

}
