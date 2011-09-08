// STTimeCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "SubTitleShifter.h"
#include "STTimeCtrl.h"


// STTimeCtrl

IMPLEMENT_DYNAMIC(STTimeCtrl, CWnd)

STTimeCtrl::STTimeCtrl()
{

}

STTimeCtrl::~STTimeCtrl()
{
}


BEGIN_MESSAGE_MAP(STTimeCtrl, CWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()



// STTimeCtrl message handlers



int STTimeCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here

	return 0;
}
