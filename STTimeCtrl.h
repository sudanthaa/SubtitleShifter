#pragma once


// STTimeCtrl

class STTimeCtrl : public CWnd
{
	DECLARE_DYNAMIC(STTimeCtrl)

public:
	STTimeCtrl();
	virtual ~STTimeCtrl();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};


