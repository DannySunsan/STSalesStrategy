
// STMainDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "STMain.h"
#include "STMainDlg.h"
#include "afxdialogex.h"
#include "resource.h"
#include "STImportDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

const wchar_t* PRODUCT_TABLE[] = { L"名称",L"价格" ,L"折扣" ,L"优惠价" ,L"描述" };
const int PRODUCT_TABLE_SIZE[] = { 30,100,50,50,50,150 };


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
//    afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
//    ON_WM_KEYDOWN()
END_MESSAGE_MAP()


// CSTMainDlg 对话框



CSTMainDlg::CSTMainDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_STMAIN_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSTMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_MAIN, m_lstMain);
	DDX_Control(pDX, IDC_BUTTON_EXPORT, m_btnExport);
	DDX_Control(pDX, IDC_COMBO_PRODUCT, m_cmbProduct);
	DDX_Control(pDX, IDC_COMBO_VERSION, m_cbVersion);
	DDX_Control(pDX, IDC_COMBO_COMPANY, m_cbCompany);
	DDX_Control(pDX, IDC_COMBO_ST, m_cbStrategy);
	DDX_Control(pDX, IDC_LIST_STRATAGE, m_listSt);
}

BEGIN_MESSAGE_MAP(CSTMainDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BUTTON_EXPORT, &CSTMainDlg::OnBnClickedButtonExport)
    ON_CBN_SELCHANGE(IDC_COMBO_PRODUCT, &CSTMainDlg::OnCbnSelchangeComboProduct)
	ON_BN_CLICKED(IDC_BUTTON_N_PRODUCT, &CSTMainDlg::OnBnClickedButtonNProduct)
	ON_BN_CLICKED(IDC_BUTTON_N_STG, &CSTMainDlg::OnBnClickedButtonNStg)
    ON_CBN_SELCHANGE(IDC_COMBO_VERSION, &CSTMainDlg::OnCbnSelchangeComboVersion)
    ON_CBN_SELCHANGE(IDC_COMBO_COMPANY, &CSTMainDlg::OnCbnSelchangeComboCompany)
    ON_CBN_SELCHANGE(IDC_COMBO_ST, &CSTMainDlg::OnCbnSelchangeComboSt)
    ON_BN_CLICKED(IDC_BUTTON_RIGHT, &CSTMainDlg::OnBnClickedButtonRight)
    ON_BN_CLICKED(IDC_BUTTON_LEFT, &CSTMainDlg::OnBnClickedButtonLeft)
    ON_BN_CLICKED(IDC_BUTTON_TS, &CSTMainDlg::OnBnClickedButtonTs)
    ON_BN_CLICKED(IDC_BUTTON_COMMIT, &CSTMainDlg::OnBnClickedButtonCommit)
    ON_COMMAND(ID_MAINME_PROJECT_SAVE, &CSTMainDlg::OnMainmeProjectSave)
    ON_COMMAND(ID_MAINME_PROJECT_EXIT, &CSTMainDlg::OnMainmeProjectExit)
    ON_WM_KEYDOWN()
    ON_WM_CLOSE()
END_MESSAGE_MAP()


// CSTMainDlg 数据处理程序
void CSTMainDlg::InitList()
{
    m_lstMain.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_CHECKBOXES);

    for (int i = 0; i < sizeof(PRODUCT_TABLE); i++)
    {
        m_lstMain.InsertColumn(i, PRODUCT_TABLE[i]);
        m_lstMain.SetColumnWidth(i, PRODUCT_TABLE_SIZE[i]);
    }
}

void CSTMainDlg::InitListStService()
{
    m_lstMain.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_CHECKBOXES);

    for (int i = 0; i < sizeof(PRODUCT_TABLE); i++)
    {
        m_lstMain.InsertColumn(i, PRODUCT_TABLE[i]);
        m_lstMain.SetColumnWidth(i, PRODUCT_TABLE_SIZE[i]);
    }
}

void CSTMainDlg::LoadMyMenu()
{
    m_Menu.LoadMenuW(IDR_MENU_MAIN);
    SetMenu(&m_Menu);
}

void CSTMainDlg::ChangeVersion(int iVerId)
{
    m_iCurVersion = iVerId;
    RefreshProduct();
}

void CSTMainDlg::ChangeProduct(int iProductId)
{
    m_iCurProduct = iProductId;
    RefreshProductList();
}

void CSTMainDlg::ChangeCompany(int iCompanyId)
{
    m_iCurCompany = iCompanyId;

}

void CSTMainDlg::ChangeStrategy(int iStrategyId)
{
    iStrategyId = m_iCurStrategy;

}

void CSTMainDlg::RefreshVersion()
{
    m_cbVersion.Clear();
    if (0 == st_data::CSchemaManager::GetInstance()->GetVersion(m_lstVer))
    {
        for (int i = 0; i < m_lstVer.size(); ++i)
        {
            m_cmbProduct.InsertString(i, m_lstVer[i].strName.c_str());
        }
    }
    m_cbVersion.SetCurSel(0);
}

void CSTMainDlg::RefreshProduct()
{
    m_cmbProduct.Clear();
    if (0 == st_data::CSchemaManager::GetInstance()->GetProduct(m_iCurVersion, m_lstProduct))
    {
        for (int i = 0;i< m_lstProduct.size();++i)
        {
            m_cmbProduct.InsertString(i, m_lstProduct[i].strName.c_str());
        }
    }
    m_cmbProduct.SetCurSel(0);
}

void CSTMainDlg::RefreshCompany()
{
    m_cbCompany.Clear();
    if (0 == st_data::CSchemaManager::GetInstance()->GetCompany(m_lstCompany))
    {
        for (int i = 0; i < m_lstCompany.size(); ++i)
        {
            m_cbCompany.InsertString(i, m_lstCompany[i].strName.c_str());
        }
    }
    m_cbCompany.SetCurSel(0);
}

void CSTMainDlg::RefreshStrategy()
{
    m_cbStrategy.Clear();
    if (0 == st_data::CSchemaManager::GetInstance()->GetStrategy(m_iCurVersion, m_lstSt))
    {
        for (int i = 0; i < m_lstSt.size(); ++i)
        {
            m_cbStrategy.InsertString(i, m_lstSt[i].strName.c_str());
        }
    }
    m_cbStrategy.SetCurSel(0);
}

void CSTMainDlg::RefreshProductList()
{
    m_lstMain.DeleteAllItems();
    InitList();
    if (0 == st_data::CSchemaManager::GetInstance()->GetService(m_iCurProduct, m_lstServ))
    {
        for (int i = 0; i < m_lstServ.size(); ++i)
        {
            int nCol = 1;
            m_lstMain.InsertItem(i,L"");
            m_lstMain.SetItemText(i, nCol++, m_lstServ[i].strName.c_str());
            m_lstMain.SetItemText(i, nCol++, L"");
            m_lstMain.SetItemText(i, nCol++, L"");
            m_lstMain.SetItemText(i, nCol++, L"");
        }
    }
    m_cbStrategy.SetCurSel(0);
}

void CSTMainDlg::RefreshStrategyServiceList()
{
    m_listSt.DeleteAllItems();
    InitListStService();
    if (0 == st_data::CSchemaManager::GetInstance()->GetStrategyService(m_iCurStrategy, m_lstStService))
    {
        for (int i = 0; i < m_lstServ.size(); ++i)
        {
            int nCol = 1;
            m_listSt.InsertItem(i, L"");
            m_listSt.SetItemText(i, nCol++, GetServiceNameById(m_lstStService[i].iServiceId).c_str());
            m_listSt.SetItemText(i, nCol++, L"");
            m_listSt.SetItemText(i, nCol++, L"");
            m_listSt.SetItemText(i, nCol++, L"");
        }
    }
    m_cbStrategy.SetCurSel(0);

}

std::wstring CSTMainDlg::GetServiceNameById(int iId)
{
    for (int i = 0; i < m_lstServ.size(); ++i)
    {
        if (m_lstServ[i].iId == iId) 
        {
            return m_lstServ[i].strName;
        }
    }
    return L"Null";
}

// CSTMainDlg 消息处理程序

BOOL CSTMainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
    LoadMyMenu();
    RefreshVersion();
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CSTMainDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSTMainDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CSTMainDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CSTMainDlg::OnBnClickedButtonExport()
{
    // TODO: 在此添加控件通知处理程序代码
}

void CSTMainDlg::OnBnClickedButtonNProduct()
{
    STImportDlg dlg;
    dlg.DoModal();
}

void CSTMainDlg::OnBnClickedButtonNStg()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CSTMainDlg::OnCbnSelchangeComboProduct()
{
    if (m_lstProduct.size() == 0)
    {
        return;
    }
    ChangeProduct(m_lstProduct[m_cmbProduct.GetCurSel()].iId);
    RefreshProductList();
}

void CSTMainDlg::OnCbnSelchangeComboVersion()
{
    if (m_lstVer.size() == 0)
    {
        return;
    }
    ChangeVersion(m_lstVer[m_cbVersion.GetCurSel()].iId);
    RefreshProduct();
}


void CSTMainDlg::OnCbnSelchangeComboCompany()
{
    if (m_lstCompany.size() == 0)
    {
        return;
    }
    ChangeCompany(m_lstCompany[m_cbCompany.GetCurSel()].iId);
    RefreshStrategy();
}


void CSTMainDlg::OnCbnSelchangeComboSt()
{
    if (m_lstSt.size() == 0)
    {
        return;
    }
    ChangeStrategy(m_lstSt[m_cbStrategy.GetCurSel()].iId);
    RefreshStrategyServiceList();
}


void CSTMainDlg::OnBnClickedButtonRight()
{
    // TODO: 在此添加控件通知处理程序代码
}


void CSTMainDlg::OnBnClickedButtonLeft()
{
    // TODO: 在此添加控件通知处理程序代码
}


void CSTMainDlg::OnBnClickedButtonTs()
{
    // TODO: 在此添加控件通知处理程序代码
}


void CSTMainDlg::OnBnClickedButtonCommit()
{
    OnMainmeProjectSave();
}

void CSTMainDlg::OnMainmeProjectSave()
{
    // TODO: 在此添加命令处理程序代码
}


void CSTMainDlg::OnMainmeProjectExit()
{
    OnClose();
}

void CSTMainDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    // TODO: 在此添加消息处理程序代码和/或调用默认值
    if (GetKeyState(VK_CONTROL))
    {
        switch (nChar)
        {
        case 'S':
        case 's':
            OnMainmeProjectSave();
            break;
        case 'X':
        case 'x':
            OnMainmeProjectExit();
            break;
        default:
            break;
        }
    }
   
    CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}


BOOL CSTMainDlg::PreTranslateMessage(MSG* pMsg)
{
    // TODO: 在此添加专用代码和/或调用基类
    SHORT key = GetKeyState(VK_CONTROL);
   if ((key >> 8)& 0x01)
   {
       switch ((char)pMsg->wParam)
       {
       case 'S':
       case 's':
           OnMainmeProjectSave();
           break;
       case 'X':
       case 'x':
           OnMainmeProjectExit();
           break;
       default:
           break;
       }
   }
    return CDialogEx::PreTranslateMessage(pMsg);
}


void CSTMainDlg::OnClose()
{
    int iRet = MessageBoxW(L"是否保存更改？", L"提示", MB_YESNOCANCEL | MB_ICONWARNING);
    switch (iRet)
    {
    case IDYES:
        OnMainmeProjectSave();
        break;
    case IDCANCEL:
        return;
    default:
        break;
    }
    CDialogEx::OnClose();
}
