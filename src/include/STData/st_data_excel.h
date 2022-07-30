#pragma once
#include "libxl/libxl.h"
#include <string>
#include <unordered_map>
#include "st_data_os_type.h"
#include "st_data_meta_data.h"
namespace st_data
{
    enum EFILETYPE
    {
        XLS,
        XLSX
    };
    struct STFONTFORMAT
    {
        int size;
        bool italic;
        bool strikeOut;
        libxl::Color color;
        bool bold;
        libxl::Script script;
        libxl::Underline underline;
        STFONTFORMAT()
        {
            size = 12;
            italic = false;
            strikeOut = false;
            color = libxl::COLOR_BLACK;
            bold = false;
            script = libxl::SCRIPT_NORMAL;
            underline = libxl::UNDERLINE_NONE;
        }
    };

    struct STCELLFORMAT
    {
        //libxl::Font* font;
        std::string font;
        libxl::NumFormat numForamt;
        libxl::AlignH alignH;
        libxl::AlignV alignV;
        bool wrap;
        int totation;
        int indent;
        bool shrinkToFit;
        libxl::BorderStyle style;
        libxl::Color color;
        libxl::BorderStyle styleLeft;
        libxl::BorderStyle styleRight;
        libxl::BorderStyle styleUp;
        libxl::BorderStyle styleDown;

        libxl::Color colorLeft;
        libxl::Color colorRight;
        libxl::Color colorUp;
        libxl::Color colorDown;

        libxl::BorderDiagonal border;
        libxl::BorderStyle styleDiagonal;
        libxl::Color colorDiagonal;

        libxl::FillPattern pattern;
        libxl::Color colorForeground;
        libxl::Color colorBackground;

        bool bLock;
        bool bHidden;

        STCELLFORMAT()
        {
            font = "default";
            wrap = false;
            totation = 0;
            indent = 0;
            shrinkToFit = false;
            bLock = true;
            bHidden = false;
        }
    };

    class STDATA_EXPORT CSTExcel
    {
    public:
        CSTExcel(EFILETYPE eType = XLS);
        ~CSTExcel();
        void AddSheet(const std::string& sName);
        void AddFont(const std::string& sName, const STFONTFORMAT& stFont);
        void AddFormat(const std::string& sName, const STCELLFORMAT& stFont);

        bool Merge(int rowFirst, int rowLast, int colFirst, int colLast);

        bool WriteBool(int row, int col, bool bValue);
        bool WriteNum(int row, int col, double num);
        bool WriteString(int row, int col, const std::string& sValue);
        bool WriteFormula(int row, int col, const std::string& sExpr);
        bool InsertPic(const std::string& sPath);

        bool ReadBool(int row, int col, libxl::Format** format = 0);
        double ReadNum(int row, int col, libxl::Format** format= 0);
        std::string ReadString(int row, int col, libxl::Format** format = 0);

        bool Load(const std::string& sPath);
        bool Save(const std::string& sPath);
        bool SelectSheet(int iNum);
        void SelectFormat(const std::string& sFormatName = "default");

        void GetCellRange(int& firstRow,int& lastRow,int& firstCol,int& lastCol);

        bool GetCellMerge(int row,int col,int& firstRow, int& lastRow, int& firstCol, int& lastCol);

        std::string GetErrorMsg();

        CSTMetaData GetCellData(int row, int col, libxl::Format** format = 0);
    private:
        void InitBook(EFILETYPE eType = XLS);
        libxl::Format* GetFormat(const std::string& sFormatName);
    private:
        libxl::Book* m_pBook;
        libxl::Sheet* m_pSelSheet;
        libxl::Format* m_pSelFormat;

        std::unordered_map<std::string, libxl::Font*> m_mapFont;
        std::unordered_map<std::string, libxl::Format*> m_mapFormat;
    };


}