
// Lab01Training02Dlg.h : header file
//

#pragma once
#include "OGLControl.h"
#include "FrustumAddingDialog.h"
#include "PrismAddingDialog.h"
#include "CSessions.h"
#include "CFaces.h"
#include "CFigures.h"
#include "afxwin.h"
#include "afxcmn.h"
//#include 

// CLab01Training02Dlg dialog
class CLaboratoryWork01Dlg : public CDialogEx
{
	// Construction
public:
	CLaboratoryWork01Dlg(CWnd* pParent = NULL);	// standard constructor

	OGLControl _oglWindow;
	CSessions _sessionsRS;
	CFigures  _figuresRS;
	CFaces	  _facesRS;
	CProperties _propertiesRS;
	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LABORATORYWORK01_DIALOG};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


														// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnHelpAbout();
	afx_msg void OnBnClickedAddFrustumButton();
	afx_msg void OnBnClickedClearButton();
	afx_msg void OnBnClickedAddPrismButton();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
private:
	CSliderCtrl _xRotationSlider;
	CString _xRotationEcho;
	CSliderCtrl _yRotationSlider;
	CString _yRotationEcho;

public:
	afx_msg void OnToolsLight();
	afx_msg void OnStnClickedOglControl();
private:
	CString _xGLPositionEcho;
	CString _yGLPositionEcho;
public:
	void SaveScene();
	void LoadScene(int sessionID);
	afx_msg void OnClose();
	afx_msg void OnBnClickedSelectModeRadio();
	afx_msg void OnBnClickedRotateModeRadio();
	CButton _selectModeRadio;
	afx_msg void OnDestroy();
};
