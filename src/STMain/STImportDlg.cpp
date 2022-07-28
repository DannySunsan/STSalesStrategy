// STImportDlg.cpp: 实现文件
//

#include "pch.h"
#include "STMain.h"
#include "STImportDlg.h"
#include "afxdialogex.h"
#include "STNewProductDlg.h"
#include "STNewVersionDlg.h"
#include "STData/st_data_schema_manager.h"
// STImportDlg 对话框

IMPLEMENT_DYNAMIC(STImportDlg, CDialogEx)

STImportDlg::STImportDlg(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_DIALOG_IMPORT, pParent)
{

}

STImportDlg::~STImportDlg()
{
}

void STImportDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_COMBO_VERSION, m_cbVersion);
    DDX_Control(pDX, IDC_COMBO_PRODUCT, m_cbProduct);
    DDX_Control(pDX, IDC_EDIT_NAME, m_editName);
    DDX_Control(pDX, IDC_EDIT_PRICE, m_editPrice);
    DDX_Control(pDX, IDC_COMBO_LOCK, m_cbLock);
    DDX_Control(pDX, IDC_EDIT_OFF, m_editOff);
    DDX_Control(pDX, IDC_LIST_IMPORT, m_lstImport);
}


BEGIN_MESSAGE_MAP(STImportDlg, CDialogEx)
    ON_BN_CLICKED(IDC_BUTTON_ADD_VER, &STImportDlg::OnBnClickedButtonAddVer)
    ON_BN_CLICKED(IDC_BUTTON_ADD_PRODUCT, &STImportDlg::OnBnClickedButtonAddProduct)
    ON_BN_CLICKED(IDC_BUTTON_UPDATE, &STImportDlg::OnBnClickedButtonUpdate)
    ON_CBN_SELCHANGE(IDC_COMBO_VERSION, &STImportDlg::OnCbnSelchangeComboVersion)
    ON_CBN_SELCHANGE(IDC_COMBO_PRODUCT, &STImportDlg::OnCbnSelchangeComboProduct)
    ON_BN_CLICKED(IDC_BUTTON_SELECTEXCEL, &STImportDlg::OnBnClickedButtonSelectexcel)
    ON_WM_CLOSE()
END_MESSAGE_MAP()

BOOL STImportDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();
    RefreshVersion();

    return TRUE;
}

void STImportDlg::RefreshVersion()
{
    m_cbVersion.Clear();
    if (0 == st_data::CSchemaManager::GetInstance()->GetVersion(m_lstVer))
    {
        for (int i = 0; i < m_lstVer.size(); ++i)
        {
            m_cbVersion.InsertString(i, m_lstVer[i].strName.c_str());
        }
    }     
    m_cbVersion.SetCurSel(0);
}

void STImportDlg::RefreshProduct()
{
    m_cbProduct.Clear();
    if (0 == st_data::CSchemaManager::GetInstance()->GetProduct(m_iCurVersion, m_lstProduct))
    {
        for (int i = 0; i < m_lstProduct.size(); ++i)
        {
            m_cbProduct.InsertString(i, m_lstProduct[i].strName.c_str());
        }
    }
    m_cbProduct.SetCurSel(0);
}

void STImportDlg::ChangeVersion(int iVerId)
{
    m_iCurVersion = iVerId;
    RefreshProduct();
}

void STImportDlg::ChangeProduct(int iProductId)
{
    m_iCurProduct = iProductId;
}

// STImportDlg 消息处理程序


void STImportDlg::OnBnClickedButtonAddVer()
{
    STNewVersionDlg dlg;
    dlg.DoModal();
}


void STImportDlg::OnBnClickedButtonAddProduct()
{
    if (m_lstVer.empty())
    {
        MessageBox(L"Please create a version for product!");
        return;
    }
    STNewProductDlg dlg;
    dlg.SetVersion(m_lstVer[m_cbVersion.GetCurSel()].strName);
    dlg.DoModal();
}


void STImportDlg::OnBnClickedButtonUpdate()
{
    // TODO: 在此添加控件通知处理程序代码
}


void STImportDlg::OnCbnSelchangeComboVersion()
{
    if (m_lstVer.size() == 0)
    {
        return;
    }
    ChangeVersion(m_lstVer[m_cbVersion.GetCurSel()].iId);
    RefreshProduct();
}


void STImportDlg::OnCbnSelchangeComboProduct()
{
    if (m_lstProduct.size() == 0)
    {
        return;
    }
    ChangeProduct(m_lstProduct[m_cbProduct.GetCurSel()].iId);
}


void STImportDlg::OnBnClickedButtonSelectexcel()
{
   
}


void STImportDlg::OnClose()
{
    // TODO: 在此添加消息处理程序代码和/或调用默认值

    CDialogEx::OnClose();
}
