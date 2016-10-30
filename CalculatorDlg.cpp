// CalculatorDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Calculator.h"
#include "CalculatorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif




// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CCalculatorDlg �Ի���




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


// CCalculatorDlg ��Ϣ�������

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
	
	GetDlgItem(IDC_EDIT1)->SetWindowText(L"0");
	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalculatorDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	//��ǰ�ı����е���
	CString csr;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(csr);
	num = (float) _wtof(csr);
	//����
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
