// STNewProductDlg.cpp: 实现文件
//

#include "pch.h"
#include "STMain.h"
#include "STNewProductDlg.h"
#include "afxdialogex.h"


// STNewProductDlg 对话框

IMPLEMENT_DYNAMIC(STNewProductDlg, CDialogEx)

STNewProductDlg::STNewProductDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_N_PRODUCT, pParent)
{

}

STNewProductDlg::~STNewProductDlg()
{
}

void STNewProductDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(STNewProductDlg, CDialogEx)
    ON_BN_CLICKED(IDC_BUTTON_CONFIRM, &STNewProductDlg::OnBnClickedButtonConfirm)
END_MESSAGE_MAP()


// STNewProductDlg 消息处理程序


void STNewProductDlg::OnBnClickedButtonConfirm()
{
    CDialogEx::OnOK();
}

void STNewProductDlg::SetVersion(const std::wstring& wsVersion)
{

}
