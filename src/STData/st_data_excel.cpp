#include "STData/st_data_excel.h"

namespace st_data
{
    CSTExcel::CSTExcel():m_pSelSheet(NULL), m_pBook(NULL)
    {
        InitBook();
    }

    CSTExcel::~CSTExcel()
    {
        m_pBook->release();
    }

    void CSTExcel::InitBook()
    {
        m_pBook = xlCreateBook();
        m_pBook->setKey("Halil Kural", "windows-2723210a07c4e90162b26966a8jcdboe");
        STFONTFORMAT fontDefault;
        AddFont("default", fontDefault);
        STCELLFORMAT formatDefault;
        AddFormat("default", formatDefault);

       SelectSheet(0);
    }

    libxl::Format* CSTExcel::GetFormat(const std::string& sFormatName)
    {
        return m_mapFormat[sFormatName];
    }

    void CSTExcel::AddSheet(const std::string& sName)
    {
        m_pSelSheet = m_pBook->addSheet(sName.c_str());
    }

    void CSTExcel::AddFont(const std::string& sName, const STFONTFORMAT& stFont)
    {
        libxl::Font* pFont = m_pBook->addFont();
        int i = pFont->size();

        pFont->setSize(stFont.size);
        pFont->setItalic(stFont.italic);
        pFont->setStrikeOut(stFont.strikeOut);
        pFont->setColor(stFont.color);
        pFont->setBold(stFont.bold);
        pFont->setScript(stFont.script);
        pFont->setUnderline(stFont.underline);
        pFont->setName(sName.c_str());

        m_mapFont[sName] = pFont;
    }

    void CSTExcel::AddFormat(const std::string& sName, const STCELLFORMAT& stFont)
    {
        libxl::Format* pFormat = m_pBook->addFormat();

        libxl::Font* font = m_mapFont[stFont.font];
        if (NULL == font)
        {
            font = m_mapFont["default"];
        }
        pFormat->setFont(font);
        pFormat->setNumFormat(stFont.numForamt);
        pFormat->setAlignH(stFont.alignH);
        pFormat->setAlignV(stFont.alignV);
        pFormat->setWrap(stFont.wrap);
        pFormat->setIndent(stFont.indent);
        pFormat->setShrinkToFit(stFont.shrinkToFit);
        pFormat->setBorderColor(stFont.color);
        pFormat->setBorder(stFont.style);
        pFormat->setBorderLeft(stFont.styleLeft);
        pFormat->setBorderRight(stFont.styleRight);
        pFormat->setBorderTop(stFont.styleUp);
        pFormat->setBorderBottom(stFont.styleDown);
        pFormat->setBorderLeftColor(stFont.colorLeft);
        pFormat->setBorderRightColor(stFont.colorRight);
        pFormat->setBorderTopColor(stFont.colorUp);
        pFormat->setBorderBottomColor(stFont.colorDown);
        pFormat->setBorderDiagonal(stFont.border);
        pFormat->setBorderDiagonalStyle(stFont.styleDiagonal);
        pFormat->setBorderDiagonalColor(stFont.colorDiagonal);
        pFormat->setFillPattern(stFont.pattern);
        pFormat->setPatternForegroundColor(stFont.colorForeground);
        pFormat->setPatternBackgroundColor(stFont.colorBackground);
        pFormat->setLocked(stFont.bLock);
        pFormat->setHidden(stFont.bHidden);
    }

    bool CSTExcel::Merge(int rowFirst, int rowLast, int colFirst, int colLast)
    {
        return m_pSelSheet->setMerge(rowFirst, rowLast, colFirst, colLast);
    }

    void CSTExcel::SelectFormat(const std::string& sFormatName)
    {
        m_pSelFormat = GetFormat(sFormatName);

        if (NULL == m_pSelFormat)
        {
            m_pSelFormat = m_mapFormat["default"];
        }
    }

    bool CSTExcel::WriteNum(int row,int col,double num)
    {
        m_pSelSheet->setCellFormat(row, col, m_pSelFormat);
        return m_pSelSheet->writeNum(row, col, num);
    }

    bool CSTExcel::WriteString(int row, int col, const std::string& sValue)
    {
        m_pSelSheet->setCellFormat(row, col, m_pSelFormat);
        return m_pSelSheet->writeStr(row, col, sValue.c_str());
    }

    bool CSTExcel::WriteFormula(int row, int col, const std::string& sValue)
    {
        m_pSelSheet->setCellFormat(row, col, m_pSelFormat);
        return m_pSelSheet->writeFormula(row, col, sValue.c_str());
    }

    bool CSTExcel::InsertPic(const std::string& sPath)
    {
        return true;
    }

    double CSTExcel::ReadNum(int row, int col, libxl::Format** format)
    {
        return m_pSelSheet->readNum(row, col, format);
    }

    std::string CSTExcel::ReadString(int row, int col, libxl::Format** format)
    {
        return m_pSelSheet->readStr(row, col, format);
    }

    bool CSTExcel::Save(const std::string& sPath)
    {
        return m_pBook->save(sPath.c_str());
    }

    bool CSTExcel::Load(const std::string& sPath)
    {
        bool bRet = m_pBook->load(sPath.c_str());
        if (bRet)
        {
            m_pSelSheet = m_pBook->getSheet(0);
            return true;
        }
        return false;
    }

    bool CSTExcel::SelectSheet(int iNum)
    {
        libxl::Sheet* pSelSheet = m_pBook->getSheet(iNum);
        if (pSelSheet != nullptr)
        {
            m_pSelSheet = pSelSheet;
            return true;
        }
        return false;
    }

    void CSTExcel::GetCellRange(int& firstRow, int& lastRow, int& firstCol, int& lastCol)
    {
        firstRow = m_pSelSheet->firstRow();
        lastRow = m_pSelSheet->lastRow();
        firstCol = m_pSelSheet->firstCol();
        lastCol = m_pSelSheet->lastCol();
    }

    bool CSTExcel::GetCellMerge(int row, int col, int& firstRow, int& lastRow, int& firstCol, int& lastCol)
    {
        return m_pSelSheet->getMerge(row, col, &firstRow, &lastRow, &firstCol, &lastCol);
    }
}