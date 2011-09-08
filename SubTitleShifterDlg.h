// SubTitleShifterDlg.h : header file
//

#pragma once


// CSubTitleShifterDlg dialog
class CSubTitleShifterDlg : public CDialog
{
// Construction
public:
	CSubTitleShifterDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_SUBTITLESHIFTER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	int GetTimeVal( CString sInput );
	void GetValStr(int iVal, CString& sOut);
	void WriteToRegistry();
	void LoadFromRegistry();
	void GenAdjustedSrt();

// Implementation
protected:
	HICON m_hIcon;

	void UpdateTimeComp(int iCtrl, CPoint pt, short zDelta, int iMin, int iMax, int iDecimals);
	void UpdateTimeComponents( CPoint pt, short zDelta );

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButtonSelectInput();
	afx_msg void OnBnClickedButtonSelectOutput();
	afx_msg void OnBnClickedButtonGen();

	CString s_InputFileName;
	CString s_OutpuFileName;
	CString s_ST_Start_Hour;
	CString s_ST_Start_Minute;
	CString s_ST_Start_Second;
	CString s_ST_Start_MiliSecond;
	CString s_ST_End_Hour;
	CString s_ST_End_Minute;
	CString s_ST_End_Second;
	CString s_ST_End_MiliSecond;
	CString s_RT_Start_Hour;
	CString s_RT_Start_Minute;
	CString s_RT_Start_Second;
	CString s_RT_Start_MiliSecond;
	CString s_RT_End_Hour;
	CString s_RT_End_Minute;
	CString s_RT_End_Second;
	CString s_RT_End_MiliSecond;
	afx_msg void OnEnVscrollEditRtStartHr();
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);

	
};
