#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// FrustumAddingDialog dialog

class FrustumAddingDialog : public CDialogEx
{
	DECLARE_DYNAMIC(FrustumAddingDialog)

public:
	FrustumAddingDialog(CWnd* pParent = NULL); 
	virtual ~FrustumAddingDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD_FRUSTUM_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CString _height;
	CSliderCtrl _heightSlider;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);;
	CString _topRadius;
	CSliderCtrl _topRadiusSlider;
	CString _bottomRadius;
	CSliderCtrl _bottomRadiusSlider;
	CEdit _xCoordinate;
	CEdit _yCoordinate;
	CEdit _zCoordinate;
};
