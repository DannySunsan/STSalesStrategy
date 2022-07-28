
// STMainDlg.h: 头文件
//

#pragma once
#include <string>
#include "STData/st_data_schema_manager.h"
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
    virtual BOOL PreTranslateMessage(MSG* pMsg);

	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

    afx_msg void OnBnClickedButtonExport();
    afx_msg void OnCbnSelchangeComboProduct();
	afx_msg void OnBnClickedButtonNProduct();
	afx_msg void OnBnClickedButtonNStg();
    afx_msg void OnCbnSelchangeComboVersion();
    afx_msg void OnCbnSelchangeComboCompany();
    afx_msg void OnCbnSelchangeComboSt();
    afx_msg void OnBnClickedButtonRight();
    afx_msg void OnBnClickedButtonLeft();
    afx_msg void OnBnClickedButtonTs();
    afx_msg void OnBnClickedButtonCommit();
    afx_msg void OnMainmeProjectSave();
    afx_msg void OnMainmeProjectExit();
    afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg void OnClose();
private:
    void InitList();
    void InitListStService();
    void LoadMyMenu();


    void ChangeVersion(int iVerId);
    void ChangeProduct(int iProductId);
    void ChangeCompany(int iCompanyId);
    void ChangeStrategy(int iStrategyId);

    void RefreshVersion();
    void RefreshProduct();
    void RefreshCompany();
    void RefreshStrategy();
    void RefreshProductList();
    void RefreshStrategyServiceList();

    std::wstring GetServiceNameById(int iId);
public:
    CListCtrl m_lstMain;
    CButton m_btnResearch;
    CButton m_btnExport;
    CComboBox m_cmbProduct;
	CComboBox m_cbVersion;
	CComboBox m_cbCompany;
	CComboBox m_cbStrategy;
	CListCtrl m_listSt;
    CMenu m_Menu;
private:
    int m_iCurVersion;
    int m_iCurProduct;
    int m_iCurCompany;
    int m_iCurStrategy;

    st_data::LISTVERSION m_lstVer;
    st_data::LISTPRODUCT m_lstProduct;
    st_data::LISTCOMPANY m_lstCompany;
    st_data::LISTSTRATEGY m_lstSt;
    st_data::LISTSERVICE m_lstServ;
    st_data::LISTSTRATEGYSERVICE m_lstStService;
};
