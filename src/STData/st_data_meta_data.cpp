#include "STData/st_data_meta_data.h"

namespace st_data
{

    CSTMetaData::CSTMetaData()
    {
        Reset();
    }

    CSTMetaData::~CSTMetaData()
    {

    }

    void CSTMetaData::SetBool(bool bValue)
    {
        Reset();
        m_Value.iValue = bValue;
        m_eType = BOOL;
    }

    void CSTMetaData::SetInt(int iValue)
    {
        Reset();
        m_Value.iValue = iValue;
        m_eType = INT;
    }

    void CSTMetaData::SetFloat(float fValue)
    {
        Reset();
        m_Value.fValue = fValue;
        m_eType = FLOAT;
    }

    void CSTMetaData::SetDouble(double dValue)
    {
        Reset();
        m_Value.dValue = dValue;
        m_eType = DOUBLE;
    }

    void CSTMetaData::SetString(const std::string& sValue)
    {
        Reset();
        m_Value.sValue = sValue;
        m_eType = STRING;
    }

    bool CSTMetaData::GetBool()
    {
        return m_Value.bValue;
    }

    int CSTMetaData::GetInt()
    {
        return m_Value.iValue;
    }

    float CSTMetaData::GetFloat()
    {
        return m_Value.fValue;
    }

    double CSTMetaData::GetDouble()
    {
        return m_Value.dValue;
    }

    std::string CSTMetaData::GetString()
    {
        return m_Value.sValue;
    }

    EValueType CSTMetaData::GetType()
    {
        return m_eType;
    }

    void CSTMetaData::Reset()
    {
        m_eType = NONE;
        memset(&m_Value,0,sizeof(m_Value));
    }
}
