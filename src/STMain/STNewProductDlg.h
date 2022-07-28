#pragma once
#include <string>

// STNewProductDlg 对话框

class STNewProductDlg : public CDialogEx
{
	DECLARE_DYNAMIC(STNewProductDlg)

public:
	STNewProductDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~STNewProductDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_N_PRODUCT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButtonConfirm();


    void SetVersion(const std::wstring& wsVersion);
private:
    std::wstring m_wsVersion;
};
