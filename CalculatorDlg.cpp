// CalculatorDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Calculator.h"
#include "CalculatorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif




// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CCalculatorDlg 对话框




CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCalculatorDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	Reset();
}

void CCalculatorDlg::Reset(){
	
	num = 0;
	result=0;
	_isNewNum = FALSE;
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_EN_CHANGE(IDC_EDIT1, &CCalculatorDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON_N1, &CCalculatorDlg::OnBnClickedButtonN1)
	ON_BN_CLICKED(IDC_BUTTON_N2, &CCalculatorDlg::OnBnClickedButtonN2)
	ON_BN_CLICKED(IDC_BUTTON_N3, &CCalculatorDlg::OnBnClickedButtonN3)
	ON_BN_CLICKED(IDC_BUTTON_N4, &CCalculatorDlg::OnBnClickedButtonN4)
	ON_BN_CLICKED(IDC_BUTTON_N05, &CCalculatorDlg::OnBnClickedButtonN05)
	ON_BN_CLICKED(IDC_BUTTON_N6, &CCalculatorDlg::OnBnClickedButtonN6)
	ON_BN_CLICKED(IDC_BUTTON_N7, &CCalculatorDlg::OnBnClickedButtonN7)
	ON_BN_CLICKED(IDC_BUTTON_N8, &CCalculatorDlg::OnBnClickedButtonN8)
	ON_BN_CLICKED(IDC_BUTTON_N9, &CCalculatorDlg::OnBnClickedButtonN9)
	ON_BN_CLICKED(IDC_BUTTON_PLUS, &CCalculatorDlg::OnBnClickedButtonPlus)
	ON_BN_CLICKED(IDC_BUTTON_N0, &CCalculatorDlg::OnBnClickedButtonN0)
	ON_BN_CLICKED(IDC_BUTTON_EQUAL, &CCalculatorDlg::OnBnClickedButtonEqual)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &CCalculatorDlg::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_MUL, &CCalculatorDlg::OnBnClickedButtonMul)
	ON_BN_CLICKED(IDC_BUTTON_DIV, &CCalculatorDlg::OnBnClickedButtonDiv)
	ON_BN_CLICKED(IDC_BUTTON_ND, &CCalculatorDlg::OnBnClickedButtonNd)
	ON_BN_CLICKED(IDC_BUTTON_MR, &CCalculatorDlg::OnBnClickedButtonMr)
END_MESSAGE_MAP()


// CCalculatorDlg 消息处理程序

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	
	GetDlgItem(IDC_EDIT1)->SetWindowText(L"0");
	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCalculatorDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalculatorDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void CCalculatorDlg::TypeNumber(LPCTSTR number){
	if(_isNewNum){
		GetDlgItem(IDC_EDIT1)->SetWindowTextW(L"");
		_isNewNum = FALSE;
	}
	CString csr;
	GetDlgItem(IDC_EDIT1)->GetWindowText(csr);
	if(csr==L"0"){
		GetDlgItem(IDC_EDIT1)->SetWindowTextW(number);
	}else{
		GetDlgItem(IDC_EDIT1)->SetWindowTextW(csr+number);
	}
}

void CCalculatorDlg::SetOperator(int nID){
	CString csr;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(csr);
	num = (float) _wtof(csr);
	result = num;
	_operator = nID;
	_isNewNum = TRUE;
}


void CCalculatorDlg::OnBnClickedButtonN1()
{
	TypeNumber(L"1");
}

void CCalculatorDlg::OnBnClickedButtonN2()
{
	TypeNumber(L"2");
}



void CCalculatorDlg::OnBnClickedButtonN3()
{
	TypeNumber(L"3");
}


void CCalculatorDlg::OnBnClickedButtonN4()
{
	TypeNumber(L"4");
}

void CCalculatorDlg::OnBnClickedButtonN05()
{
	TypeNumber(L"5");
}

void CCalculatorDlg::OnBnClickedButtonN6()
{
	TypeNumber(L"6");
}

void CCalculatorDlg::OnBnClickedButtonN7()
{
	TypeNumber(L"7");
}

void CCalculatorDlg::OnBnClickedButtonN8()
{
	TypeNumber(L"8");
}

void CCalculatorDlg::OnBnClickedButtonN9()
{
	TypeNumber(L"9");
}

void CCalculatorDlg::OnBnClickedButtonPlus()
{
	SetOperator(IDC_BUTTON_PLUS);
}

void CCalculatorDlg::OnBnClickedButtonN0()
{
	TypeNumber(L"0");
}

void CCalculatorDlg::OnBnClickedButtonEqual()
{
	//当前文本框中的数
	CString csr;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(csr);
	num = (float) _wtof(csr);
	//计算
	switch(_operator){
		case IDC_BUTTON_PLUS:
			result = num+result;
			break;
		case IDC_BUTTON_MINUS:
			result = result-num;
			break;
		case IDC_BUTTON_MUL:
			result = result*num;
			break;
		case IDC_BUTTON_DIV:
			result = result/num;
			break;
	}
	CString szA;
	szA.Format(_T("%1.2f"),result);
	GetDlgItem(IDC_EDIT1)->SetWindowText(szA);
	_isNewNum = TRUE;
}

void CCalculatorDlg::OnBnClickedButtonMinus()
{
	SetOperator(IDC_BUTTON_MINUS);
}

void CCalculatorDlg::OnBnClickedButtonMul()
{
	SetOperator(IDC_BUTTON_MUL);
}

void CCalculatorDlg::OnBnClickedButtonDiv()
{
	SetOperator(IDC_BUTTON_DIV);
}

void CCalculatorDlg::OnBnClickedButtonNd()
{
	TypeNumber(L".");
}


void CCalculatorDlg::OnBnClickedButtonMr()
{
	Reset();
	GetDlgItem(IDC_EDIT1)->SetWindowText(L"0");
}
