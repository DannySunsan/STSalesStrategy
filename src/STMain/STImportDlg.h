#pragma once
#include "STData/st_data_table_define.h"

// STImportDlg 对话框

class STImportDlg : public CDialogEx
{
	DECLARE_DYNAMIC(STImportDlg)

public:
	STImportDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~STImportDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_IMPORT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
    virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButtonAddVer();
    afx_msg void OnBnClickedButtonAddProduct();
    afx_msg void OnBnClickedButtonUpdate();
    afx_msg void OnCbnSelchangeComboVersion();
    afx_msg void OnCbnSelchangeComboProduct();
    afx_msg void OnBnClickedButtonSelectexcel();

    void RefreshVersion();
    void RefreshProduct();

    void ChangeVersion(int iVerId);
    void ChangeProduct(int iProductId);
private:
    int m_iCurVersion;
    int m_iCurProduct;
    st_data::LISTVERSION m_lstVer;
    st_data::LISTPRODUCT m_lstProduct;
public:
    CComboBox m_cbVersion;
    CComboBox m_cbProduct;
    CEdit m_editName;
    CEdit m_editPrice;
    CComboBox m_cbLock;
    CEdit m_editOff;
    CListCtrl m_lstImport;
    afx_msg void OnClose();
};
