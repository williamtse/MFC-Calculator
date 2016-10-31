// CalculatorDlg.h : 头文件
//

#pragma once

// CCalculatorDlg 对话框
class CCalculatorDlg : public CDialog
{
// 构造
public:
	CCalculatorDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CALCULATOR_DIALOG };

	int _operator;
	float result;
	float num;
	bool _isNewNum;

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton9();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButtonN1();
	afx_msg void OnBnClickedButtonN2();
	afx_msg void OnBnClickedButtonN3();
	void TypeNumber(LPCTSTR number);
	afx_msg void OnBnClickedButtonN4();
	afx_msg void OnBnClickedButtonN05();
	afx_msg void OnBnClickedButtonN6();
	afx_msg void OnBnClickedButtonN7();
	afx_msg void OnBnClickedButtonN8();
	afx_msg void OnBnClickedButtonN9();
	afx_msg void OnBnClickedButtonPlus();
	afx_msg void OnBnClickedButtonN0();
	void SetOperator(int nID);
	afx_msg void OnBnClickedButtonEqual();
	afx_msg void OnBnClickedButtonMinus();
	afx_msg void OnBnClickedButtonMul();
	afx_msg void OnBnClickedButtonDiv();
	afx_msg void OnBnClickedButtonNd();
	afx_msg void OnBnClickedButtonMr();
	void Reset();
	float n_mInput;
};
