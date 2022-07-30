#include "STData/st_data_excel_operator.h"
#include "STData/st_data_excel.h"


namespace st_data
{
    bool CSTExcelOperator::CreateSalesList(const std::string& sPath)
    {
        CSTExcel excel;







        return excel.Save(sPath);

    }

    bool CSTExcelOperator::ReadProductList(const std::string& sPath, st_data::LISTPRODUCT& pd)
    {
        CSTExcel excel(XLSX);
        if (!excel.Load(sPath))
        {
            std::string Error = excel.GetErrorMsg();
            return false;
        }
        int firstRow;
        int lastRow;
        int firstCol;
        int lastCol;
        excel.GetCellRange(firstRow, lastRow, firstCol, lastCol);

        for (int r = firstRow; r < lastRow; ++r)
        {
            for (int c = firstCol; c < lastCol; ++c)
            {
                STPRODUCT product;
                std::string sService = excel.ReadString(r,c);

                std::string Error = excel.GetErrorMsg();
            }
        }

        return true;
    }

}
