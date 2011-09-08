// SubTitleShifterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SubTitleShifter.h"
#include "SubTitleShifterDlg.h"

#include <highgui.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CSubTitleShifterDlg dialog




CSubTitleShifterDlg::CSubTitleShifterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSubTitleShifterDlg::IDD, pParent)
	, s_InputFileName(_T(""))
	, s_OutpuFileName(_T(""))
	, s_ST_Start_Hour(_T("00"))
	, s_ST_Start_Minute(_T("00"))
	, s_ST_Start_Second(_T("00"))
	, s_ST_Start_MiliSecond(_T("000"))
	, s_ST_End_Hour(_T("00"))
	, s_ST_End_Minute(_T("00"))
	, s_ST_End_Second(_T("00"))
	, s_ST_End_MiliSecond(_T("000"))
	, s_RT_Start_Hour(_T("00"))
	, s_RT_Start_Minute(_T("00"))
	, s_RT_Start_Second(_T("00"))
	, s_RT_Start_MiliSecond(_T("000"))
	, s_RT_End_Hour(_T("00"))
	, s_RT_End_Minute(_T("00"))
	, s_RT_End_Second(_T("00"))
	, s_RT_End_MiliSecond(_T("000"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSubTitleShifterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATIC_INPUT, s_InputFileName);
	DDX_Text(pDX, IDC_STATIC_OUTPUT, s_OutpuFileName);
	DDX_Text(pDX, IDC_EDIT_ST_START_HR, s_ST_Start_Hour);
	DDX_Text(pDX, IDC_EDIT_ST_START_MIN, s_ST_Start_Minute);
	DDX_Text(pDX, IDC_EDIT_ST_START_SEC, s_ST_Start_Second);
	DDX_Text(pDX, IDC_EDIT_ST_START_MSEC, s_ST_Start_MiliSecond);
	DDX_Text(pDX, IDC_EDIT_ST_END_HR, s_ST_End_Hour);
	DDX_Text(pDX, IDC_EDIT_ST_END_MIN, s_ST_End_Minute);
	DDX_Text(pDX, IDC_EDIT_ST_END_SEC, s_ST_End_Second);
	DDX_Text(pDX, IDC_EDIT_ST_END_MSEC, s_ST_End_MiliSecond);
	DDX_Text(pDX, IDC_EDIT_RT_START_HR, s_RT_Start_Hour);
	DDX_Text(pDX, IDC_EDIT_RT_START_MIN, s_RT_Start_Minute);
	DDX_Text(pDX, IDC_EDIT_RT_START_SEC, s_RT_Start_Second);
	DDX_Text(pDX, IDC_EDIT_RT_START_MSEC, s_RT_Start_MiliSecond);
	DDX_Text(pDX, IDC_EDIT_RT_END_HR, s_RT_End_Hour);
	DDX_Text(pDX, IDC_EDIT_RT_END_MIN, s_RT_End_Minute);
	DDX_Text(pDX, IDC_EDIT_RT_END_SEC, s_RT_End_Second);
	DDX_Text(pDX, IDC_EDIT_RT_END_MSEC, s_RT_End_MiliSecond);
}

BEGIN_MESSAGE_MAP(CSubTitleShifterDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CSubTitleShifterDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_SELECT_INPUT, &CSubTitleShifterDlg::OnBnClickedButtonSelectInput)
	ON_BN_CLICKED(IDC_BUTTON_SELECT_OUTPUT, &CSubTitleShifterDlg::OnBnClickedButtonSelectOutput)
	ON_BN_CLICKED(IDC_BUTTON_GEN, &CSubTitleShifterDlg::OnBnClickedButtonGen)
	ON_EN_VSCROLL(IDC_EDIT_RT_START_HR, &CSubTitleShifterDlg::OnEnVscrollEditRtStartHr)
	ON_WM_MOUSEWHEEL()
END_MESSAGE_MAP()


// CSubTitleShifterDlg message handlers

BOOL CSubTitleShifterDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	LoadFromRegistry();

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

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSubTitleShifterDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSubTitleShifterDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSubTitleShifterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CSubTitleShifterDlg::OnBnClickedOk()
{
	OnOK();
}

void CSubTitleShifterDlg::GenAdjustedSrt()
{
	UpdateData();

	CString sSubStt = s_ST_Start_Hour + ":" + s_ST_Start_Minute + ":" + s_ST_Start_Second + "," + s_ST_Start_MiliSecond;
	CString sSubEnd = s_ST_End_Hour + ":" + s_ST_End_Minute + ":" + s_ST_End_Second + "," + s_ST_End_MiliSecond;
	CString sRealStt = s_RT_Start_Hour + ":" + s_RT_Start_Minute + ":" + s_RT_Start_Second + "," + s_RT_Start_MiliSecond;
	CString sRealEnd = s_RT_End_Hour + ":" + s_RT_End_Minute + ":" + s_RT_End_Second + "," + s_RT_End_MiliSecond;

	int iSubStt = GetTimeVal(sSubStt);
	int iSubEnd = GetTimeVal(sSubEnd);
	int iRealStt = GetTimeVal(sRealStt);
	int iRealEnd = GetTimeVal(sRealEnd);

	double dRatio = ((double)(iRealEnd - iRealStt))/((double)(iSubEnd - iSubStt));

	CString sInputFileName = s_InputFileName;
	CString sOutputFileName = s_OutpuFileName;

	if (sInputFileName == sOutputFileName)
	{
		AfxMessageBox("Input and Output files cannot be same");
		return;
	}

	CStdioFile sInputFile;
	CStdioFile sOutputFile;

	if (!sInputFile.Open(sInputFileName, CFile::modeRead | CFile::shareDenyWrite))
	{
		AfxMessageBox("Could not open read file.");
		return;
	}

	if (!sOutputFile.Open(sOutputFileName, CFile::modeWrite | CFile::modeCreate))
	{
		AfxMessageBox("Could not open write file file.");
		return;
	}

	CString sInput;

	while (sInputFile.ReadString(sInput))
	{
		if (sInput.GetLength() == 0 || sInput.GetAt(0) != '0')
		{
			sInput += "\n";
			sOutputFile.WriteString(sInput);
			continue;
		}

		CString sStt = sInput.Left(12);
		CString sEnd = sInput.Right(12);

		int iStt = GetTimeVal(sStt);
		int iEnd = GetTimeVal(sEnd);

		double dNewStt = (double)iRealStt + ((double)(iStt - iSubStt)) * dRatio;
		double dNewEnd = (double)iRealStt + ((double)(iEnd - iSubStt)) * dRatio;

		CString sNewStt;
		CString sNewEnd;

		GetValStr((int)dNewStt, sNewStt);
		GetValStr((int)dNewEnd, sNewEnd);

		CString sOut;
		sOut.Format("%s --> %s\n", sNewStt, sNewEnd);
		sOutputFile.WriteString(sOut);
	}


	sInputFile.Close();
	sOutputFile.Close();

	WriteToRegistry();

}


int CSubTitleShifterDlg::GetTimeVal( CString sInput )
{
	int iMilSec = atoi(sInput.Mid(9,3));
	int iSec = atoi(sInput.Mid(6,2));
	int iMin = atoi(sInput.Mid(3,2));
	int iHour = atoi(sInput.Mid(0,2));

	int dVal = iHour;
	dVal = dVal * 60 + iMin;
	dVal = dVal * 60 + iSec;
	dVal = dVal * 1000 + iMilSec;

	return dVal;
}

void CSubTitleShifterDlg::GetValStr(int iVal, CString& sOut)
{
	int iMilSec = iVal % 1000;	iVal = iVal/1000;
	int iSec = iVal % 60;	iVal = iVal/60;
	int iMin = iVal % 60;	iVal = iVal/60;
	int iHour = iVal % 60;

	sOut.Format("%02d:%02d:%02d,%03d", iHour, iMin, iSec, iMilSec);
}

void CSubTitleShifterDlg::OnBnClickedButtonSelectInput()
{
	char strFilter[] = { "Srt Files (*.srt)|*.srt|All Files (*.*)|*.*||" };

	CFileDialog oFileDlg(TRUE, ".srt", NULL, 0, strFilter);

	if( oFileDlg.DoModal() == IDOK )
	{
		s_InputFileName = oFileDlg.GetPathName() ;
		UpdateData(FALSE);
	}
	else
		return;

	// TODO: Add your control notification handler code here
}

void CSubTitleShifterDlg::OnBnClickedButtonSelectOutput()
{
	char strFilter[] = { "Srt Files (*.srt)|*.srt|All Files (*.*)|*.*||" };

	CFileDialog oFileDlg(FALSE, ".srt", NULL, 0, strFilter);

	if( oFileDlg.DoModal() == IDOK )
	{
		s_OutpuFileName = oFileDlg.GetPathName() ;
		UpdateData(FALSE);
	}
	else
		return;

	// TODO: Add your control notification handler code here
}

void CSubTitleShifterDlg::WriteToRegistry()
{
	CWinApp* pApp = AfxGetApp();
	pApp->WriteProfileString("Time", "RealStart_Hr", s_RT_Start_Hour);
	pApp->WriteProfileString("Time", "RealStart_Min", s_RT_Start_Minute);
	pApp->WriteProfileString("Time", "RealStart_Sec", s_RT_Start_Second);
	pApp->WriteProfileString("Time", "RealStart_MilSec", s_RT_Start_MiliSecond);

	pApp->WriteProfileString("Time", "RealEnd_Hr", s_RT_End_Hour);
	pApp->WriteProfileString("Time", "RealEnd_Min", s_RT_End_Minute);
	pApp->WriteProfileString("Time", "RealEnd_Sec", s_RT_End_Second);
	pApp->WriteProfileString("Time", "RealEnd_MilSec", s_RT_End_MiliSecond);

	pApp->WriteProfileString("Time", "SubStart_Hr", s_ST_Start_Hour);
	pApp->WriteProfileString("Time", "SubStart_Min", s_ST_Start_Minute);
	pApp->WriteProfileString("Time", "SubStart_Sec", s_ST_Start_Second);
	pApp->WriteProfileString("Time", "SubStart_MilSec", s_ST_Start_MiliSecond);

	pApp->WriteProfileString("Time", "SubEnd_Hr", s_ST_End_Hour);
	pApp->WriteProfileString("Time", "SubEnd_Min", s_ST_End_Minute);
	pApp->WriteProfileString("Time", "SubEnd_Sec", s_ST_End_Second);
	pApp->WriteProfileString("Time", "SubEnd_MilSec", s_ST_End_MiliSecond);

	pApp->WriteProfileString("Files", "Input_File", s_InputFileName);
	pApp->WriteProfileString("Files", "Output_File", s_OutpuFileName);
}

void CSubTitleShifterDlg::LoadFromRegistry()
{
	CWinApp* pApp = AfxGetApp();
	s_RT_Start_Hour = pApp->GetProfileString("Time", "RealStart_Hr");
	s_RT_Start_Minute = pApp->GetProfileString("Time", "RealStart_Min");
	s_RT_Start_Second = pApp->GetProfileString("Time", "RealStart_Sec");
	s_RT_Start_MiliSecond = pApp->GetProfileString("Time", "RealStart_MilSec");

	s_RT_End_Hour = pApp->GetProfileString("Time", "RealEnd_Hr");
	s_RT_End_Minute = pApp->GetProfileString("Time", "RealEnd_Min");
	s_RT_End_Second = pApp->GetProfileString("Time", "RealEnd_Sec");
	s_RT_End_MiliSecond = pApp->GetProfileString("Time", "RealEnd_MilSec");

	s_ST_Start_Hour = pApp->GetProfileString("Time", "SubStart_Hr");
	s_ST_Start_Minute = pApp->GetProfileString("Time", "SubStart_Min");
	s_ST_Start_Second = pApp->GetProfileString("Time", "SubStart_Sec");
	s_ST_Start_MiliSecond = pApp->GetProfileString("Time", "SubStart_MilSec");

	s_ST_End_Hour = pApp->GetProfileString("Time", "SubEnd_Hr");
	s_ST_End_Minute = pApp->GetProfileString("Time", "SubEnd_Min");
	s_ST_End_Second = pApp->GetProfileString("Time", "SubEnd_Sec");
	s_ST_End_MiliSecond = pApp->GetProfileString("Time", "SubEnd_MilSec");

	s_InputFileName = pApp->GetProfileString("Files", "Input_File");
	s_OutpuFileName = pApp->GetProfileString("Files", "Output_File");

	UpdateData(FALSE);
}
void CSubTitleShifterDlg::OnBnClickedButtonGen()
{
	// TODO: Add your control notification handler code here
	GenAdjustedSrt();
}

void CSubTitleShifterDlg::OnEnVscrollEditRtStartHr()
{
	// TODO: Add your control notification handler code here
	int iK=0;
}

BOOL CSubTitleShifterDlg::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: Add your message handler code here and/or call default

	UpdateTimeComponents(pt, zDelta);
	return CDialog::OnMouseWheel(nFlags, zDelta, pt);
}


void CSubTitleShifterDlg::UpdateTimeComp( int iCtrl, CPoint pt, short zDelta, int i_Min, int i_Max, int i_Decimals ) 
{
	CWnd* pWnd = GetDlgItem(iCtrl);

	CRect rClient;
	pWnd->GetWindowRect(rClient);
	if (rClient.PtInRect(pt))
	{
		CString sVal;
		pWnd->GetWindowText(sVal);

		int iVal = atoi(sVal);
		iVal += zDelta > 0 ? 1 : -1;

		if (iVal < i_Min) 
			iVal = i_Max;

		if (iVal > i_Max) 
			iVal = i_Min;

		CString sFmt;
		sFmt.Format("%%0%dd", i_Decimals);

		sVal.Format(sFmt, iVal);
		pWnd->SetWindowText(sVal);
	}
}

void CSubTitleShifterDlg::UpdateTimeComponents( CPoint pt, short zDelta )
{
	UpdateTimeComp(IDC_EDIT_RT_START_HR, pt, zDelta, 0, 59, 2);
	UpdateTimeComp(IDC_EDIT_RT_START_MIN, pt, zDelta, 0, 59, 2);
	UpdateTimeComp(IDC_EDIT_RT_START_SEC, pt, zDelta, 0, 59, 2);
	UpdateTimeComp(IDC_EDIT_RT_START_MSEC, pt, zDelta, 0, 999, 3);

	UpdateTimeComp(IDC_EDIT_RT_END_HR, pt, zDelta, 0, 59, 2);
	UpdateTimeComp(IDC_EDIT_RT_END_MIN, pt, zDelta, 0, 59, 2);
	UpdateTimeComp(IDC_EDIT_RT_END_SEC, pt, zDelta, 0, 59, 2);
	UpdateTimeComp(IDC_EDIT_RT_END_MSEC, pt, zDelta, 0, 999, 3);

	UpdateTimeComp(IDC_EDIT_ST_START_HR, pt, zDelta, 0, 59, 2);
	UpdateTimeComp(IDC_EDIT_ST_START_MIN, pt, zDelta, 0, 59, 2);
	UpdateTimeComp(IDC_EDIT_ST_START_SEC, pt, zDelta, 0, 59, 2);
	UpdateTimeComp(IDC_EDIT_ST_START_MSEC, pt, zDelta, 0, 999, 3);

	UpdateTimeComp(IDC_EDIT_ST_END_HR, pt, zDelta, 0, 59, 2);
	UpdateTimeComp(IDC_EDIT_ST_END_MIN, pt, zDelta, 0, 59, 2);
	UpdateTimeComp(IDC_EDIT_ST_END_SEC, pt, zDelta, 0, 59, 2);
	UpdateTimeComp(IDC_EDIT_ST_END_MSEC, pt, zDelta, 0, 999, 3);
}