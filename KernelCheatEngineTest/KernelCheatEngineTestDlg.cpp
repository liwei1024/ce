
// KernelCheatEngineTestDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "winioctl.h"
#include "KernelCheatEngineTest.h"
#include "KernelCheatEngineTestDlg.h"
#include "afxdialogex.h"
#include "../KernelCheatEngine/kce_api.h"

#include "../DriverControl/DriverControl.h"
#pragma comment(lib,"DriverControl.lib")

DriverControl drictl;

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


// CKernelCheatEngineTestDlg 对话框



CKernelCheatEngineTestDlg::CKernelCheatEngineTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_KERNELCHEATENGINETEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CKernelCheatEngineTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, edit2);
	DDX_Control(pDX, IDC_EDIT1, edit1);
	DDX_Control(pDX, IDC_EDIT3, edit3);
	DDX_Control(pDX, IDC_EDIT5, edit_address);
	DDX_Control(pDX, IDC_EDIT6, edit_byte);
	DDX_Control(pDX, IDC_EDIT7, edit_short);
	DDX_Control(pDX, IDC_EDIT8, edit_integer);
	DDX_Control(pDX, IDC_EDIT9, edit_long);
	DDX_Control(pDX, IDC_EDIT10, edit_float);
	DDX_Control(pDX, IDC_EDIT11, edit_double);
	DDX_Control(pDX, IDC_EDIT12, edit_string);
	DDX_Control(pDX, IDC_EDIT15, edit_string_length);
	DDX_Control(pDX, IDC_EDIT13, edit_wstring);
	DDX_Control(pDX, IDC_EDIT16, edit_wstring_length);
	DDX_Control(pDX, IDC_EDIT14, edit_bytes);
	DDX_Control(pDX, IDC_EDIT17, edit_bytes_length);
}

BEGIN_MESSAGE_MAP(CKernelCheatEngineTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CKernelCheatEngineTestDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CKernelCheatEngineTestDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CKernelCheatEngineTestDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CKernelCheatEngineTestDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CKernelCheatEngineTestDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CKernelCheatEngineTestDlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// CKernelCheatEngineTestDlg 消息处理程序

BOOL CKernelCheatEngineTestDlg::OnInitDialog()
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
	edit3.SetWindowTextW(L"By丶顿号");

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CKernelCheatEngineTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CKernelCheatEngineTestDlg::OnPaint()
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
HCURSOR CKernelCheatEngineTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// 选择驱动路径
void CKernelCheatEngineTestDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString m_strFilePath = _T("");

	//打开图像文件，获取文件路径名
	LPCTSTR szFilter = _T("SYS(*.sys)|*.sys|BMP(*.bmp)|*.bmp|ALLSUPORTFILE(*.*)|*.*||");
	CFileDialog dlgFileOpenImg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, NULL);
	//打开图像
	if (dlgFileOpenImg.DoModal() == IDOK)
	{
		//读取文件文件名
		m_strFilePath = dlgFileOpenImg.GetPathName();
		OutputDebugString(m_strFilePath);
		edit2.SetWindowTextW(m_strFilePath);
	}
	else
	{
		return;
	}
}

// 安装驱动
void CKernelCheatEngineTestDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	edit2.GetWindowTextW(str);
	OutputDebugString(str);
	drictl.insert(str);
	edit1.SetWindowTextW(drictl.getMessage());
}

// 启动驱动
void CKernelCheatEngineTestDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	drictl.start();
	edit1.SetWindowTextW(drictl.getMessage());
}

// 停止驱动
void CKernelCheatEngineTestDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	drictl.stop();
	edit1.SetWindowTextW(drictl.getMessage());
}

// 卸载驱动
void CKernelCheatEngineTestDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	drictl.unload();
	edit1.SetWindowTextW(drictl.getMessage());
}

//读内存
void CKernelCheatEngineTestDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	CString address_str;
	edit_address.GetWindowTextW(address_str);

	byte m_byte;
	short m_short;
	int m_int;
	LONGLONG m_long;

	KCE_READ_VIRTUAL_MEMORY_STRUCT rvms;

	rvms.Response = &m_byte;
	rvms.Address = _wtoi(address_str);
	rvms.Size = sizeof(m_byte);
	drictl.control(L"\\\\.\\" SYMBOLIC_LINK_SHORT_NAME, KCE_READ_VIRTUAL_MEMORY, &rvms, sizeof(rvms), &rvms, sizeof(rvms));
	str.Format(L"%d", m_byte);
	edit_byte.SetWindowTextW(str);

	rvms.Response = &m_short;
	rvms.Address = _wtoi(address_str);
	rvms.Size = sizeof(m_short);
	drictl.control(L"\\\\.\\" SYMBOLIC_LINK_SHORT_NAME, KCE_READ_VIRTUAL_MEMORY, &rvms, sizeof(rvms), &rvms, sizeof(rvms));
	str.Format(L"%d", m_short);
	edit_short.SetWindowTextW(str);

	rvms.Response = &m_int;
	rvms.Address = _wtoi(address_str);
	rvms.Size = sizeof(m_int);
	drictl.control(L"\\\\.\\" SYMBOLIC_LINK_SHORT_NAME, KCE_READ_VIRTUAL_MEMORY, &rvms, sizeof(rvms), &rvms, sizeof(rvms));
	str.Format(L"%d", m_int);
	edit_integer.SetWindowTextW(str);

	rvms.Response = &m_long;
	rvms.Address = _wtoi(address_str);
	rvms.Size = sizeof(m_long);
	drictl.control(L"\\\\.\\" SYMBOLIC_LINK_SHORT_NAME, KCE_READ_VIRTUAL_MEMORY, &rvms, sizeof(rvms), &rvms, sizeof(rvms));
	str.Format(L"%d", m_long);
	edit_long.SetWindowTextW(str);

}
