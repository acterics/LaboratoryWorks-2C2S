
// LaboratoryWork03Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "LaboratoryWork03.h"
#include "LaboratoryWork03Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLaboratoryWork03Dlg dialog



CLaboratoryWork03Dlg::CLaboratoryWork03Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LABORATORYWORK03_DIALOG, pParent)
	, m_applesCountEcho(_T(""))
	, m_stepCountEcho(_T(""))
	, m_resultEcho(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLaboratoryWork03Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_APPLES_COUNT_ECHO, m_applesCountEcho);
	DDX_Text(pDX, IDC_STEP_NUMBER_ECHO, m_stepCountEcho);
	DDX_Control(pDX, IDC_RUN_BUTTON, m_runButtonCtrl);
	DDX_Control(pDX, IDC_STEP_BUTTON, m_stepButtonCtrl);
	DDX_Control(pDX, IDC_STOP_BUTTON, m_stopButtonCtrl);
	DDX_Control(pDX, IDC_GENERATION_PROGRESS, m_generationProgressCtrl);
	DDX_Control(pDX, IDC_GENERATE_BUTTON, m_generationButtonCtrl);
	DDX_Text(pDX, IDC_RESULT_ECHO, m_resultEcho);
	DDX_Control(pDX, IDC_RESTART_BUTTON, m_restartButtonCtrl);
}

BEGIN_MESSAGE_MAP(CLaboratoryWork03Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_STEP_BUTTON, &CLaboratoryWork03Dlg::OnBnClickedStepButton)
	ON_BN_CLICKED(IDC_RUN_BUTTON, &CLaboratoryWork03Dlg::OnBnClickedRunButton)
	ON_BN_CLICKED(IDC_STOP_BUTTON, &CLaboratoryWork03Dlg::OnBnClickedStopButton)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_GENERATE_BUTTON, &CLaboratoryWork03Dlg::OnBnClickedGenerateButton)
	ON_BN_CLICKED(IDC_RESTART_BUTTON, &CLaboratoryWork03Dlg::OnBnClickedRestartButton)
END_MESSAGE_MAP()


// CLaboratoryWork03Dlg message handlers

BOOL CLaboratoryWork03Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	UpdateData(TRUE);
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

									// TODO: Add extra initialization here
	CRect rect;

	// Get size and position of the template textfield we created before in the dialog editor
	GetDlgItem(IDC_OGL_PICTURE)->GetWindowRect(rect);

	// Convert screen coordinates to client coordinates
	ScreenToClient(rect);

	// Create OpenGL Control window

	m_generationProgressCtrl.ShowWindow(FALSE);
	m_oglPicture.oglCreate(rect, this);



	// Setup the OpenGL Window's timer to render
	m_oglPicture._unpTimer = m_oglPicture.SetTimer(1, 100, 0);
	SetTimer(0, 100, NULL);

	UpdateData(FALSE);
	return TRUE;   // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLaboratoryWork03Dlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLaboratoryWork03Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLaboratoryWork03Dlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	switch (nType)
	{
	case SIZE_RESTORED:
	{
		if (m_oglPicture._isMaximized)
		{
			m_oglPicture.OnSize(nType, cx, cy);
			m_oglPicture._isMaximized = false;
		}

		break;
	}

	case SIZE_MAXIMIZED:
	{
		m_oglPicture.OnSize(nType, cx, cy);
		m_oglPicture._isMaximized = true;

		break;
	}
	}
}




void CLaboratoryWork03Dlg::OnBnClickedStepButton()
{
	m_oglPicture.updateField();
}


void CLaboratoryWork03Dlg::OnBnClickedRunButton()
{
	m_timer = SetTimer(0, 200, NULL);
	m_oglPicture.run();
}


void CLaboratoryWork03Dlg::OnBnClickedStopButton()
{
	m_oglPicture.stop();
}


void CLaboratoryWork03Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	UpdateData(TRUE);
	int step = m_oglPicture.step();
	if (step >= 200)
	{
		CString message;
		m_oglPicture.stop();
		m_resultEcho.Format(_T("RESULT: %d"), 89 - m_oglPicture.apples());
		m_restartButtonCtrl.ShowWindow(TRUE);
	}
		
	
	m_applesCountEcho.Format(_T("%d"), m_oglPicture.apples());
	m_stepCountEcho.Format(_T("%d"), step);
	CDialogEx::OnTimer(nIDEvent);
	UpdateData(FALSE);
}


void CLaboratoryWork03Dlg::OnBnClickedGenerateButton()
{
	std::thread thread([=] {generateAnt();});
	thread.detach();
}

void CLaboratoryWork03Dlg::generateAnt()
{
	m_generationProgressCtrl.ShowWindow(TRUE);
	m_generationButtonCtrl.EnableWindow(FALSE);

	m_generationProgressCtrl.SetPos(0);
	m_generationProgressCtrl.SetRange(0, MAX_GENERATION);
	m_generationProgressCtrl.SetStep(1);
	m_oglPicture.initAnt(this);;

	m_runButtonCtrl.EnableWindow(TRUE);
	m_stepButtonCtrl.EnableWindow(TRUE);
	m_stopButtonCtrl.EnableWindow(TRUE);
	m_generationProgressCtrl.ShowWindow(FALSE);
}


void CLaboratoryWork03Dlg::progressStep()
{
	m_generationProgressCtrl.StepIt();
}

void CLaboratoryWork03Dlg::OnBnClickedRestartButton()
{
	UpdateData(TRUE);
	m_resultEcho.Format(_T(""));
	m_restartButtonCtrl.ShowWindow(FALSE);
	m_generationButtonCtrl.EnableWindow(TRUE);
	m_runButtonCtrl.EnableWindow(FALSE);
	m_stepButtonCtrl.EnableWindow(FALSE);
	m_stopButtonCtrl.EnableWindow(FALSE);
	m_oglPicture.restart();
	UpdateData(FALSE);
}
