
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

    afx_msg void OnBnClickedButtonRight();
    afx_msg void OnBnClickedButtonLeft();
    afx_msg void OnMainmeProjectExit();
    afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg void OnClose();
private:
    void InitList();
    void LoadMyMenu();

    void ChangeStrategy(int iStrategyId);
    void RefreshStrategyServiceList();
public:
    CListCtrl m_lstMain;
    CMenu m_Menu;
private:
    int m_iCurStrategy;
    st_data::LISTPRODUCT m_lstProduct;
public:
    afx_msg void OnProjectOpen();
    afx_msg void OnProjectImport();
    afx_msg void OnProjectNew();
    afx_msg void OnMainmeProjectSave();
};
