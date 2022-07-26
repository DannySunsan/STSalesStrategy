
// STMainDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "STMain.h"
#include "STMainDlg.h"
#include "afxdialogex.h"
#include "resource.h"
#include "STData/st_data_table_define.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
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
	DDX_Control(pDX, IDC_BUTTON_RESEARCH, m_btnResearch);
	DDX_Control(pDX, IDC_BUTTON_EXPORT, m_btnExport);
	DDX_Control(pDX, IDC_COMBO_PRODUCT, m_cmbProduct);
	DDX_Control(pDX, IDC_COMBO_VERSION, m_cbVersion);
	DDX_Control(pDX, IDC_COMBO_COMPANY, m_cbCompany);
	DDX_Control(pDX, IDC_COMBO_ST, m_cbStrategy);
	DDX_Control(pDX, IDC_LIST_STRATAGE, m_listSt);
	DDX_Control(pDX, IDC_LIST_DESC, m_lsDesc);
}

BEGIN_MESSAGE_MAP(CSTMainDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BUTTON_RESEARCH, &CSTMainDlg::OnBnClickedButtonResearch)
    ON_BN_CLICKED(IDC_BUTTON_EXPORT, &CSTMainDlg::OnBnClickedButtonExport)
    ON_CBN_SELCHANGE(IDC_COMBO_PRODUCT, &CSTMainDlg::OnCbnSelchangeComboProduct)
	ON_BN_CLICKED(IDC_BUTTON_N_PRODUCT, &CSTMainDlg::OnBnClickedButtonNProduct)
	ON_BN_CLICKED(IDC_BUTTON_N_STG, &CSTMainDlg::OnBnClickedButtonNStg)
END_MESSAGE_MAP()


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
    InitCmbProduct();
    InitList();
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

void CSTMainDlg::InitList()
{
    m_lstMain.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_CHECKBOXES);
    m_lstMain.InsertColumn(0,L"选择");
    m_lstMain.InsertColumn(1, L"产品");
    m_lstMain.InsertColumn(2, L"描述");
    m_lstMain.InsertColumn(3, L"价格");
    m_lstMain.InsertColumn(4, L"最低折扣");
    m_lstMain.InsertColumn(5, L"采用折扣");
    m_lstMain.InsertColumn(6, L"折后价格");
    m_lstMain.InsertColumn(7, L"购买数量");

    m_lstMain.SetColumnWidth(0, 30);
    m_lstMain.SetColumnWidth(1, 100);
    m_lstMain.SetColumnWidth(2, 100);
    m_lstMain.SetColumnWidth(3, 80);
    m_lstMain.SetColumnWidth(4, 80);
    m_lstMain.SetColumnWidth(5, 100);
    m_lstMain.SetColumnWidth(6, 100);
    m_lstMain.SetColumnWidth(7, 80);
}

void CSTMainDlg::InitCmbProduct()
{
    m_cmbProduct.InsertString(0,L"绿建");
    m_cmbProduct.InsertString(1, L"结构");
    m_cmbProduct.SetCurSel(0);
}

void CSTMainDlg::OnBnClickedButtonResearch()
{
    // TODO: 在此添加控件通知处理程序代码
}


void CSTMainDlg::OnBnClickedButtonExport()
{
    // TODO: 在此添加控件通知处理程序代码
}


void CSTMainDlg::OnCbnSelchangeComboProduct()
{
    CStringW strProduct;
    m_lstMain.GetWindowTextW(strProduct);
    RefreshList(strProduct.GetString());
}

void CSTMainDlg::RefreshList(std::wstring strProduct)
{
    st::LISTPRODUCT lists;
    st::STPRODUCTTABLE product;
    product.strName = L"asd";
    product.strDescribe = L"erwer";
    product.dPrice = 0.0;
    product.lowest_off_Percent = 1.0;
    product.off_Percent = 2.0;
    product.off_Price = 3.0;
    product.uiQuantity = 100;
    product.strDomain = L"Green";
    product.strVersion = L"1.0.0";

    m_lstMain.InsertItem(0,L"");
    m_lstMain.SetItemText(0,1,L"546");
}


void CSTMainDlg::OnBnClickedButtonNProduct()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CSTMainDlg::OnBnClickedButtonNStg()
{
	// TODO: 在此添加控件通知处理程序代码
}
