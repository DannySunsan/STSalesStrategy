#include "STCore/st_core_excel.h"

namespace st_core
{
    CSTExcel::CSTExcel():m_pSelSheet(NULL)
    {
        m_pBook = xlCreateBook();
        STFONTFORMAT fontDefault;
        AddFont("default", fontDefault);
        STCELLFORMAT formatDefault;
        AddFormat("default", formatDefault);
    }

    CSTExcel::~CSTExcel()
    {
        m_pBook->release();
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

    void CSTExcel::SetCellFormat(int row, int col, const std::string& sFormatName)
    {
        libxl::Format* pFormat = m_mapFormat[sFormatName];

        if (NULL == pFormat)
        {
            pFormat = m_mapFormat["default"];
        }

        m_pSelSheet->setCellFormat(row, col, pFormat);
    }

    bool CSTExcel::WriteNum(int row,int col,double num)
    {
        return m_pSelSheet->writeNum(row, col, num);
    }

    bool CSTExcel::WriteString(int row, int col, const std::string& sValue)
    {
        return m_pSelSheet->writeStr(row, col, sValue.c_str());
    }

    bool CSTExcel::InsertPic(const std::string& sPath)
    {
        return true;
    }

    bool CSTExcel::Save(const std::string& sPath)
    {
        m_pBook->save(sPath.c_str());
    }
}