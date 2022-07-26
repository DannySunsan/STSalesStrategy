// STStrategyDlg.cpp: 实现文件
//

#include "pch.h"
#include "STMain.h"
#include "STStrategyDlg.h"
#include "afxdialogex.h"
#include "STData/st_data_schema_manager.h"
#include "STNewCompanyDlg.h"

// STStrategyDlg 对话框

IMPLEMENT_DYNAMIC(STStrategyDlg, CDialogEx)

STStrategyDlg::STStrategyDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ST, pParent)
	, m_bTotal(FALSE)
{

}

STStrategyDlg::~STStrategyDlg()
{
}

void STStrategyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, m_bTotal);
	DDX_Control(pDX, IDC_EDIT_NAME, m_editName);
	DDX_Control(pDX, IDC_COMBO_CP, m_cbCP);
}


BEGIN_MESSAGE_MAP(STStrategyDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_OK, &STStrategyDlg::OnBnClickedButtonOk)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &STStrategyDlg::OnBnClickedButtonAdd)
	ON_CBN_EDITCHANGE(IDC_COMBO_CP, &STStrategyDlg::OnCbnEditchangeComboCp)
	ON_CBN_DROPDOWN(IDC_COMBO_CP, &STStrategyDlg::OnCbnDropdownComboCp)
END_MESSAGE_MAP()


// STStrategyDlg 消息处理程序


void STStrategyDlg::OnBnClickedButtonOk()
{
	
}


void STStrategyDlg::OnBnClickedButtonAdd()
{
	STNewCompanyDlg dlg;
	dlg.DoModal();
	RefreshCompany();
}

void STStrategyDlg::RefreshCompany(std::wstring csName)
{
	m_cbCP.Clear();
	st::LISTCOMPANY lstCo;
	if (0 != st::CSchemaManager::GetInstance()->GetCompany(csName, lstCo))
	{
		CString szMsg(st::CSchemaManager::GetInstance()->GetErrorMsg().c_str());
		MessageBoxW(szMsg);
		return;
	}
	int iIndex = 0;
	for (st::LISTCOMPANY::iterator it = lstCo.begin();
		it != lstCo.end();++it)
	{
		m_cbCP.InsertString(iIndex,it->strName.c_str());
	}
}

void STStrategyDlg::OnCbnEditchangeComboCp()
{
	CStringW csName;
	m_cbCP.GetWindowTextW(csName);
	RefreshCompany(csName.GetString());
}


void STStrategyDlg::OnCbnDropdownComboCp()
{
	RefreshCompany(L"");
}
