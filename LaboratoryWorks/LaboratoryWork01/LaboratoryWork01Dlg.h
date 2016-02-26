
// Lab01Training02Dlg.h : header file
//

#pragma once
#include "OGLControl.h"
#include "afxwin.h"
//#include 

// CLab01Training02Dlg dialog
class CLaboratoryWork01Dlg : public CDialogEx
{
	// Construction
public:
	CLaboratoryWork01Dlg(CWnd* pParent = NULL);	// standard constructor

	OGLControl _oglWindow;

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LAB01TRAINING03_DIALOG };
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
	CButton _fillRadioButton;
private:
	bool _isFill;
public:
};
