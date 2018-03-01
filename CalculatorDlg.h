// CalculatorDlg.h : header file
//

#if !defined(AFX_CALCULATORDLG_H__B4379DD4_EFC0_4416_A525_C4423F342719__INCLUDED_)
#define AFX_CALCULATORDLG_H__B4379DD4_EFC0_4416_A525_C4423F342719__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCalculatorDlg dialog

class CCalculatorDlg : public CDialog
{
// Construction
public:
	bool bflag;
	
	float m_fSaveNumber;
	int iflag;
	void fnNumberSave();
	CCalculatorDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCalculatorDlg)
	enum { IDD = IDD_CALCULATOR_DIALOG };
	CString	m_sNumber;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCalculatorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCalculatorDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonBack();
	afx_msg void OnButtonClear();
	afx_msg void OnButtonNumber9();
	afx_msg void OnButtonNumber8();
	afx_msg void OnButtonNumber7();
	afx_msg void OnButtonNumber6();
	afx_msg void OnButtonNumber5();
	afx_msg void OnButtonNumber4();
	afx_msg void OnButtonNumber3();
	afx_msg void OnButtonNumber2();
	afx_msg void OnButtonNumber1();
	afx_msg void OnButtonNumber0();
	afx_msg void OnButtonNumberpoint();
	afx_msg void OnButtonOperatorPlus();
	afx_msg void OnButtonOperatorMinus();
	afx_msg void OnButtonOperatorMultiply();
	afx_msg void OnButtonOperatorOver();
	afx_msg void OnButtonOperatorMod();
	afx_msg void OnButtonOneoverx();
	afx_msg void OnButtonOperatorEqual();
	afx_msg void OnStaticNumbershow();
	afx_msg void OnButtonAbout();
	afx_msg void OnButtonPlusandminus();
	afx_msg void OnButtonAllClear();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALCULATORDLG_H__B4379DD4_EFC0_4416_A525_C4423F342719__INCLUDED_)
