﻿#pragma once


// STNewCompanyDlg 对话框

class STNewCompanyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(STNewCompanyDlg)

public:
	STNewCompanyDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~STNewCompanyDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonOk();
	CEdit m_editName;
	CEdit m_editPos;
};
