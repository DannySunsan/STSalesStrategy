// STNewVersionDlg.cpp: 实现文件
//

#include "pch.h"
#include "STMain.h"
#include "STNewVersionDlg.h"
#include "afxdialogex.h"


// STNewVersionDlg 对话框

IMPLEMENT_DYNAMIC(STNewVersionDlg, CDialogEx)

STNewVersionDlg::STNewVersionDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_N_VERSION, pParent)
{

}

STNewVersionDlg::~STNewVersionDlg()
{
}

void STNewVersionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(STNewVersionDlg, CDialogEx)
END_MESSAGE_MAP()


// STNewVersionDlg 消息处理程序
