#pragma once
#include <string>

namespace st_data
{
    typedef enum
    {
        INT,
        FLOAT,
        DOUBLE,
        STRING
    } EValueType;

    class CSTMetaData
    {
    private:
        typedef union
        {
            int iValue;
            float fValue;
            double dValue;
            std::string sValue;
        } Value;
    public:
        CSTMetaData();
        ~CSTMetaData();

        void SetInt(int iValue);
        void SetFloat(float fValue);
        void SetDouble(double dValue);
        void SetString(const std::string& sValue);

        int GetInt();
        float GetFloat();
        double GetDouble();
        std::string GetString();

        EValueType GetType();
    private:
        EValueType m_eType;
        Value m_Value;
    };

}