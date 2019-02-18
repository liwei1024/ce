
// KernelCheatEngineTestDlg.h: 头文件
//

#pragma once


// CKernelCheatEngineTestDlg 对话框
class CKernelCheatEngineTestDlg : public CDialogEx
{
// 构造
public:
	CKernelCheatEngineTestDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_KERNELCHEATENGINETEST_DIALOG };
#endif

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
	afx_msg void OnBnClickedButton1();
	CEdit edit2;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	CEdit edit1;
	CEdit edit3;
	afx_msg void OnBnClickedButton6();
	CEdit edit_address;
	CEdit edit_byte;
	CEdit edit_short;
	CEdit edit_integer;
	CEdit edit_long;
	CEdit edit_float;
	CEdit edit_double;
	CEdit edit_string;
	CEdit edit_string_length;
	CEdit edit_wstring;
	CEdit edit_wstring_length;
	CEdit edit_bytes;
	CEdit edit_bytes_length;
};
