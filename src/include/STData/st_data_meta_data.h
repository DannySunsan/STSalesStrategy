#pragma once
#include <string>

namespace st_data
{
    typedef enum
    {
        NONE,
        BOOL,
        INT,
        FLOAT,
        DOUBLE,
        STRING
    } EValueType;
    class CSTMetaData
    {
    private:
        typedef struct 
        {
            bool bValue;
            int iValue;
            float fValue;
            double dValue;
            std::string sValue;
        } STValue;
    public:
        CSTMetaData();
        ~CSTMetaData();

        void SetBool(bool bValue);
        void SetInt(int iValue);
        void SetFloat(float fValue);
        void SetDouble(double dValue);
        void SetString(const std::string& sValue);

        bool GetBool();
        int GetInt();
        float GetFloat();
        double GetDouble();
        std::string GetString();

        EValueType GetType();
    private:
        STValue& Value(EValueType eType);
        void Reset();
    private:
        EValueType m_eType;
        STValue m_Value;
    };

}