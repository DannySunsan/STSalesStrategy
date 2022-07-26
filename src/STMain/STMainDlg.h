
// STMainDlg.h: 头文件
//

#pragma once
#include <string>

// CSTMainDlg 对话框
class CSTMainDlg : public CDialogEx
{
// 构造
public:
	CSTMainDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STMAIN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

    afx_msg void OnBnClickedButtonResearch();
    afx_msg void OnBnClickedButtonExport();
    afx_msg void OnCbnSelchangeComboProduct();
	afx_msg void OnBnClickedButtonNProduct();
	afx_msg void OnBnClickedButtonNStg();
private:
    void InitList();
    void InitCmbProduct();
    void RefreshList(std::wstring strProduct);
public:
    CListCtrl m_lstMain;

    CButton m_btnResearch;
    CButton m_btnExport;
    CComboBox m_cmbProduct;
	CComboBox m_cbVersion;
	CComboBox m_cbCompany;
	CComboBox m_cbStrategy;
	CListCtrl m_listSt;
	CListBox m_lsDesc;
};
