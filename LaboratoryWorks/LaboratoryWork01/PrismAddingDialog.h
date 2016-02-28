#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "OGLControl.h"


// AddPrismDialog dialog

class PrismAddingDialog : public CDialogEx
{
	DECLARE_DYNAMIC(PrismAddingDialog)

public:
	PrismAddingDialog(OGLControl *o, CWnd* pParent = NULL);   // standard constructor
	virtual ~PrismAddingDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD_PRISM_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);  
	BOOL OnInitDialog();
	OGLControl * _oglControl;

	BOOL _isInited;
	DECLARE_MESSAGE_MAP()
public:
	CEdit _xCoordinateEdit;
	CEdit _yCoordinateEdit;
	CEdit _zCoordinateEdit;
	CEdit _xFaceTranslation;
	CEdit _yFaceTranslation;
	CEdit _zFaceTranslation;
	CSliderCtrl _heightSlider;
	CString _height;
	CListBox _quadList;
	CListBox _colorList;
	CEdit _quadHeightEdit;
	CEdit _topEdgeEdit;
	CEdit _bottomEdgeEdit;
	CEdit _topEdgeTranslation;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnLbnSelchangeQuadrangleList();
	CString _topEdgeTranslationEcho;
	CString _bottomEdgeLengthEcho;
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeTopEdgeLength();
};
