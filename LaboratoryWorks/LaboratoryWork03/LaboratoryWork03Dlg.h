
// LaboratoryWork03Dlg.h : header file
//

#pragma once
#include <thread>

#include "OGLPicture.h"
#include "afxwin.h"
#include "afxcmn.h"

#define MAX_GENERATION 10

// CLaboratoryWork03Dlg dialog
class CLaboratoryWork03Dlg : public CDialogEx
{
// Construction
public:
	CLaboratoryWork03Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LABORATORYWORK03_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	OGLPicture m_oglPicture;
	CString m_stepCountEcho;
	CButton m_runButtonCtrl;
	CButton m_stepButtonCtrl;
	CButton m_stopButtonCtrl;
	BOOL m_bIsGenerated;
	CProgressCtrl m_generationProgressCtrl;

	UINT_PTR m_timer;

	void generateAnt();
	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnStnClickedOglPicture();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedStepButton();
	afx_msg void OnBnClickedRunButton();
	afx_msg void OnBnClickedStopButton();
	CString m_applesCountEcho;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void progressStep();
	
	afx_msg void OnBnClickedGenerateButton();
	
	CButton m_generationButtonCtrl;
private:
	CString m_resultEcho;
	CButton m_restartButtonCtrl;
public:
	afx_msg void OnBnClickedRestartButton();
};
