#pragma once


// STStrategyDlg 对话框

class STStrategyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(STStrategyDlg)

public:
	STStrategyDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~STStrategyDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

	void RefreshCompany(std::wstring csName = L"");
public:
	BOOL m_bTotal;
	afx_msg void OnBnClickedButtonOk();
	CEdit m_editName;
	CComboBox m_cbCP;
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnCbnEditchangeComboCp();
	afx_msg void OnCbnDropdownComboCp();
};
