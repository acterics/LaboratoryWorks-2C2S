#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include <sstream>
#include "OGLControl.h"


// FrustumAddingDialog dialog

class FrustumAddingDialog : public CDialogEx
{
	DECLARE_DYNAMIC(FrustumAddingDialog)

public:
	FrustumAddingDialog(OGLControl *o, CWnd* pParent = NULL); 
	virtual ~FrustumAddingDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD_FRUSTUM_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	BOOL OnInitDialog();

	OGLControl *_oglControl;

	float getValue(CString var);
	glm::vec3 getColor(CString var);

	DECLARE_MESSAGE_MAP()
public:
	CString _height;
	CSliderCtrl _heightSlider;
	CString _topRadius;
	CSliderCtrl _topRadiusSlider;
	CString _bottomRadius;
	CSliderCtrl _bottomRadiusSlider;
	CEdit _xCoordinate;
	CEdit _yCoordinate;
	CEdit _zCoordinate;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnBnClickedOk();
	CListBox _colorList;
	CEdit _smooth;
};
