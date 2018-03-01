// CalculatorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include <iostream>

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCalculatorDlg dialog

CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCalculatorDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCalculatorDlg)
	m_sNumber = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCalculatorDlg)
	DDX_Text(pDX, IDC_STATIC_NUMBERSHOW, m_sNumber);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialog)
	//{{AFX_MSG_MAP(CCalculatorDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_BACK, OnButtonBack)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, OnButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_NUMBER9, OnButtonNumber9)
	ON_BN_CLICKED(IDC_BUTTON_NUMBER8, OnButtonNumber8)
	ON_BN_CLICKED(IDC_BUTTON_NUMBER7, OnButtonNumber7)
	ON_BN_CLICKED(IDC_BUTTON_NUMBER6, OnButtonNumber6)
	ON_BN_CLICKED(IDC_BUTTON_NUMBER5, OnButtonNumber5)
	ON_BN_CLICKED(IDC_BUTTON_NUMBER4, OnButtonNumber4)
	ON_BN_CLICKED(IDC_BUTTON_NUMBER3, OnButtonNumber3)
	ON_BN_CLICKED(IDC_BUTTON_NUMBER2, OnButtonNumber2)
	ON_BN_CLICKED(IDC_BUTTON_NUMBER1, OnButtonNumber1)
	ON_BN_CLICKED(IDC_BUTTON_NUMBER0, OnButtonNumber0)
	ON_BN_CLICKED(IDC_BUTTON_NUMBERPOINT, OnButtonNumberpoint)
	ON_BN_CLICKED(IDC_BUTTON_OPERATOR_PLUS, OnButtonOperatorPlus)
	ON_BN_CLICKED(IDC_BUTTON_OPERATOR_MINUS, OnButtonOperatorMinus)
	ON_BN_CLICKED(IDC_BUTTON_OPERATOR_MULTIPLY, OnButtonOperatorMultiply)
	ON_BN_CLICKED(IDC_BUTTON_OPERATOR_OVER, OnButtonOperatorOver)
	ON_BN_CLICKED(IDC_BUTTON_OPERATOR_MOD, OnButtonOperatorMod)
	ON_BN_CLICKED(IDC_BUTTON_ONEOVERX, OnButtonOneoverx)
	ON_BN_CLICKED(IDC_BUTTON_OPERATOR_EQUAL, OnButtonOperatorEqual)
	ON_BN_CLICKED(IDC_STATIC_NUMBERSHOW, OnStaticNumbershow)
	ON_BN_CLICKED(IDC_BUTTON_ABOUT, OnButtonAbout)
	ON_BN_CLICKED(IDC_BUTTON_PLUSANDMINUS, OnButtonPlusandminus)
	ON_BN_CLICKED(IDC_BUTTON_ALL_CLEAR, OnButtonAllClear)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCalculatorDlg message handlers

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_sNumber = "";
	iflag = 0;
	bflag = TRUE;
	
//	(CButton*) GetDlgItem(IDC_RADIO_STANDARD_TYPE)->GetCheck(TRUE);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCalculatorDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCalculatorDlg::OnButtonBack() 
{
	// TODO: Add your control notification handler code here
	if(m_sNumber.IsEmpty() != TRUE)
	{
		int length = m_sNumber.GetLength() - 1;
		m_sNumber = m_sNumber.Left(length);
		GetDlgItem(IDC_STATIC_NUMBERSHOW)->SetWindowText(m_sNumber);
	}
}

void CCalculatorDlg::OnButtonClear() 
{
	// TODO: Add your control notification handler code here
	if(m_sNumber.IsEmpty() != TRUE)
	{
		m_sNumber = "";
		GetDlgItem(IDC_STATIC_NUMBERSHOW)->SetWindowText(m_sNumber);
	}		
}

void CCalculatorDlg::OnButtonNumber9() 
{
	// TODO: Add your control notification handler code here
	m_sNumber += '9';
	GetDlgItem(IDC_STATIC_NUMBERSHOW)->SetWindowText(m_sNumber);
}

void CCalculatorDlg::OnButtonNumber8() 
{
	// TODO: Add your control notification handler code here
	m_sNumber += '8';
	GetDlgItem(IDC_STATIC_NUMBERSHOW)->SetWindowText(m_sNumber);
}

void CCalculatorDlg::OnButtonNumber7() 
{
	// TODO: Add your control notification handler code here
	m_sNumber += '7';
	GetDlgItem(IDC_STATIC_NUMBERSHOW)->SetWindowText(m_sNumber);
}

void CCalculatorDlg::OnButtonNumber6() 
{
	// TODO: Add your control notification handler code here
	m_sNumber += '6';
	GetDlgItem(IDC_STATIC_NUMBERSHOW)->SetWindowText(m_sNumber);
}

void CCalculatorDlg::OnButtonNumber5() 
{
	// TODO: Add your control notification handler code here
	m_sNumber += '5';
	GetDlgItem(IDC_STATIC_NUMBERSHOW)->SetWindowText(m_sNumber);
}

void CCalculatorDlg::OnButtonNumber4() 
{
	// TODO: Add your control notification handler code here
	m_sNumber += '4';
	GetDlgItem(IDC_STATIC_NUMBERSHOW)->SetWindowText(m_sNumber);
}

void CCalculatorDlg::OnButtonNumber3() 
{
	// TODO: Add your control notification handler code here
	m_sNumber += '3';
	GetDlgItem(IDC_STATIC_NUMBERSHOW)->SetWindowText(m_sNumber); 
}

void CCalculatorDlg::OnButtonNumber2() 
{
	// TODO: Add your control notification handler code here
	m_sNumber += '2';
	GetDlgItem(IDC_STATIC_NUMBERSHOW)->SetWindowText(m_sNumber);
}

void CCalculatorDlg::OnButtonNumber1() 
{
	// TODO: Add your control notification handler code here
	m_sNumber += '1';
	GetDlgItem(IDC_STATIC_NUMBERSHOW)->SetWindowText(m_sNumber);
}

void CCalculatorDlg::OnButtonNumber0() 
{
	// TODO: Add your control notification handler code here
	m_sNumber += '0';
	GetDlgItem(IDC_STATIC_NUMBERSHOW)->SetWindowText(m_sNumber);

}

void CCalculatorDlg::OnButtonNumberpoint() 
{
	// TODO: Add your control notification handler code here
	if(m_sNumber.IsEmpty() != TRUE)
	{
		if(m_sNumber.Find(".") == -1)
		{
			m_sNumber += '.';
			GetDlgItem(IDC_STATIC_NUMBERSHOW)->SetWindowText(m_sNumber);
		}
	}
}

void CCalculatorDlg::OnButtonOperatorPlus() 
{
	// TODO: Add your control notification handler code here
	if(m_sNumber.IsEmpty() != TRUE)
	{
		fnNumberSave();
		GetDlgItem(IDC_STATIC_NUMBERSHOW)->SetWindowText(m_sNumber);
		iflag = 1;
	}
}

void CCalculatorDlg::OnButtonOperatorMinus() 
{
	// TODO: Add your control notification handler code here
	if(m_sNumber.IsEmpty() != TRUE)
	{
		fnNumberSave();
		GetDlgItem(IDC_STATIC_NUMBERSHOW)->SetWindowText(m_sNumber);	
		iflag = 2;
	}
}

void CCalculatorDlg::OnButtonOperatorMultiply() 
{
	// TODO: Add your control notification handler code here
	if(m_sNumber.IsEmpty() != TRUE)
	{
		fnNumberSave();
		GetDlgItem(IDC_STATIC_NUMBERSHOW)->SetWindowText(m_sNumber);
		iflag = 3;
	}
}

void CCalculatorDlg::OnButtonOperatorOver() 
{
	// TODO: Add your control notification handler code here
	if(m_sNumber.IsEmpty() != TRUE)
	{
		fnNumberSave();
		GetDlgItem(IDC_STATIC_NUMBERSHOW)->SetWindowText(m_sNumber);
		iflag = 4;
	}
}

void CCalculatorDlg::OnButtonOperatorMod() 
{
	// TODO: Add your control notification handler code here
	if(m_sNumber.IsEmpty() != TRUE)
	{
		fnNumberSave();
		GetDlgItem(IDC_STATIC_NUMBERSHOW)->SetWindowText(m_sNumber);	
		iflag = 5;
	}
}

void CCalculatorDlg::OnButtonOneoverx() 
{
	// TODO: Add your control notification handler code here
	if(m_sNumber.IsEmpty() != TRUE)
	{
		float fNumber = atof(m_sNumber);
		fNumber = 1 / fNumber;
		m_sNumber.Format("%g",fNumber);
		GetDlgItem(IDC_STATIC_NUMBERSHOW)->SetWindowText(m_sNumber);		
	}
}

void CCalculatorDlg::OnButtonOperatorEqual() 
{
	// TODO: Add your control notification handler code here
	float fNumber;
	fNumber = atof(m_sNumber);
	switch(iflag)
	{
		case 1:	m_sNumber.Format("%g", fNumber + m_fSaveNumber);break;
		case 2:	m_sNumber.Format("%g", m_fSaveNumber - fNumber);break;
		case 3: m_sNumber.Format("%g", fNumber * m_fSaveNumber);break;
		case 4: m_sNumber.Format("%g", m_fSaveNumber / fNumber);break;
		case 5: m_sNumber.Format("%d", (int)m_fSaveNumber % (int)fNumber);
	}
	iflag = 0;
	GetDlgItem(IDC_STATIC_NUMBERSHOW)->SetWindowText(m_sNumber);
}

void CCalculatorDlg::OnStaticNumbershow() 
{

}

void CCalculatorDlg::fnNumberSave()
{
	m_fSaveNumber = atof(m_sNumber);
	m_sNumber = "";
}

void CCalculatorDlg::OnButtonAbout() 
{
	// TODO: Add your control notification handler code here
	MessageBox("\n    Calculator is made of LTB    \n");	
}

void CCalculatorDlg::OnButtonPlusandminus() 
{
	// TODO: Add your control notification handler code here
	if(bflag == TRUE)
	{

		m_sNumber.Insert(0,'-');
		bflag = FALSE;
	}
	else
	{
		m_sNumber.Delete(0,1);
		bflag = TRUE;
	}
		
	m_fSaveNumber = atof(m_sNumber);
	GetDlgItem(IDC_STATIC_NUMBERSHOW)->SetWindowText(m_sNumber);	
	
}

void CCalculatorDlg::OnButtonAllClear() 
{
	// TODO: Add your control notification handler code here
	if(m_sNumber.IsEmpty() != TRUE)
	{
		m_fSaveNumber = 0;
		m_sNumber = "";
		iflag = 0;
		bflag = TRUE;
		GetDlgItem(IDC_STATIC_NUMBERSHOW)->SetWindowText(m_sNumber);	
	}
}
