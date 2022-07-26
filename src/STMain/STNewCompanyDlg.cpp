// STNewCompanyDlg.cpp: 实现文件
//

#include "pch.h"
#include "STMain.h"
#include "STNewCompanyDlg.h"
#include "afxdialogex.h"
#include "STData/st_data_schema_manager.h"

// STNewCompanyDlg 对话框

IMPLEMENT_DYNAMIC(STNewCompanyDlg, CDialogEx)

STNewCompanyDlg::STNewCompanyDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_CP, pParent)
{

}

STNewCompanyDlg::~STNewCompanyDlg()
{
}

void STNewCompanyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_NAME, m_editName);
	DDX_Control(pDX, IDC_EDIT_POSITION, m_editPos);
}


BEGIN_MESSAGE_MAP(STNewCompanyDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_OK, &STNewCompanyDlg::OnBnClickedButtonOk)
END_MESSAGE_MAP()


// STNewCompanyDlg 消息处理程序


void STNewCompanyDlg::OnBnClickedButtonOk()
{
	st::STCOMPANY cp;
	ZeroMemory(&cp,sizeof(cp));
	CStringW csName,csPostion;
	m_editName.GetWindowTextW(csName);
	m_editPos.GetWindowTextW(csPostion);
	if (csName.IsEmpty())
	{
		MessageBoxW(L"Name is Empty!");
		return;
	}
	cp.strName = csName;
	cp.strPosition = csPostion;
	if (0 != st::CSchemaManager::GetInstance()->AddCompany(cp))
	{
		CString szMsg(st::CSchemaManager::GetInstance()->GetErrorMsg().c_str());
		MessageBoxW(szMsg);
		return;
	}
}
