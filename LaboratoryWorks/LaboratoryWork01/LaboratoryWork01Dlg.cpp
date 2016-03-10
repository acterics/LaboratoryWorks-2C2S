
// Lab01Training02Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "LaboratoryWork01.h"
#include "LaboratoryWork01Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLab01Training02Dlg dialog



CLaboratoryWork01Dlg::CLaboratoryWork01Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LABORATORYWORK01_DIALOG, pParent)
	, _xRotationEcho(_T(""))
	, _yRotationEcho(_T(""))
	, _xGLPositionEcho(_T(""))
	, _yGLPositionEcho(_T(""))
{

	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//_facesRS = CFaces();
	//_sessionsRS = CSessions();
	//_figuresRS = CFigures();
	//_propertiesRS = CProperties();
}

void CLaboratoryWork01Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_X_ROTATION_SPEED_SLIDER, _xRotationSlider);
	DDX_Text(pDX, IDC_X_ROTATION_SPEED_ECHO, _xRotationEcho);
	DDX_Control(pDX, IDC_Y_ROTATION_SPEED_SLIDER, _yRotationSlider);
	DDX_Text(pDX, IDC_Y_ROTATION_SPEED_ECHO, _yRotationEcho);
}

BEGIN_MESSAGE_MAP(CLaboratoryWork01Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_SIZE()
	ON_COMMAND(ID_HELP_ABOUT, &CLaboratoryWork01Dlg::OnHelpAbout)
	ON_BN_CLICKED(IDC_ADD_FRUSTUM_BUTTON, &CLaboratoryWork01Dlg::OnBnClickedAddFrustumButton)
	ON_BN_CLICKED(IDC_CLEAR_BUTTON, &CLaboratoryWork01Dlg::OnBnClickedClearButton)
	ON_BN_CLICKED(IDC_ADD_PRISM_BUTTON, &CLaboratoryWork01Dlg::OnBnClickedAddPrismButton)
	ON_WM_HSCROLL()
	ON_COMMAND(ID_TOOLS_LIGHT, &CLaboratoryWork01Dlg::OnToolsLight)
	ON_WM_MOUSEMOVE()
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CLab01Training02Dlg message handlers

BOOL CLaboratoryWork01Dlg::OnInitDialog()
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
	GetDlgItem(IDC_OGL_CONTROL)->GetWindowRect(rect);

	// Convert screen coordinates to client coordinates
	ScreenToClient(rect);

	// Create OpenGL Control window
	_oglWindow.oglCreate(rect, this);
	_xRotationSlider.SetRange(0, 100, TRUE);
	_xRotationSlider.SetPos(0);
	_xRotationEcho.Format(_T("0"));

	_yRotationSlider.SetRange(0, 100, TRUE);
	_yRotationSlider.SetPos(0);
	_yRotationEcho.Format(_T("0"));

	_xGLPositionEcho.Format(_T("0"));
	_yGLPositionEcho.Format(_T("0"));


	// Setup the OpenGL Window's timer to render
	_oglWindow._unpTimer = _oglWindow.SetTimer(1, 1, 0);
	SetTimer(0, 100, NULL);
	UpdateData(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control

}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLaboratoryWork01Dlg::OnPaint()
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
HCURSOR CLaboratoryWork01Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLaboratoryWork01Dlg::OnTimer(UINT_PTR nIDEvent)
{
	//UpdateData(TRUE);
	//_xGLPositionEcho.Format(_T("%d"), _oglWindow._fLastX);
	//_yGLPositionEcho.Format(_T("%d"), _oglWindow._fLastY);
	//UpdateData(FALSE);
	//CDialogEx::OnTimer(nIDEvent);
}


void CLaboratoryWork01Dlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	switch (nType)
	{
	case SIZE_RESTORED:
	{
		if (_oglWindow._isMaximized)
		{
			_oglWindow.OnSize(nType, cx, cy);
			_oglWindow._isMaximized = false;
		}

		break;
	}

	case SIZE_MAXIMIZED:
	{
		_oglWindow.OnSize(nType, cx, cy);
		_oglWindow._isMaximized = true;

		break;
	}
	}
}


void CLaboratoryWork01Dlg::OnHelpAbout()
{
	CDialog dlgAbout(IDD_ABOUT);
	dlgAbout.DoModal();
	//dlgAbout.

}








void CLaboratoryWork01Dlg::OnBnClickedAddFrustumButton()
{
	FrustumAddingDialog dlg(&_oglWindow);
	dlg.DoModal();
	//dlgAbout.DoModal();
}


void CLaboratoryWork01Dlg::OnBnClickedClearButton()
{
	_oglWindow.clearScene();
}


void CLaboratoryWork01Dlg::OnBnClickedAddPrismButton()
{
	PrismAddingDialog dlg(&_oglWindow);
	dlg.DoModal();
	// TODO: Add your control notification handler code here
}


void CLaboratoryWork01Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	if (pScrollBar == (CScrollBar *)&_xRotationSlider)
	{
		int value = _xRotationSlider.GetPos();
		_xRotationEcho.Format(_T("%d"), value);
		_oglWindow.setXRotationSpeed((float)value / 10);
		UpdateData(FALSE);
	}
	if (pScrollBar == (CScrollBar *)&_yRotationSlider)
	{
		int value = _yRotationSlider.GetPos();
		_yRotationEcho.Format(_T("%d"), value);
		_oglWindow.setYRotationSpeed((float)value / 10);
		UpdateData(FALSE);
	}
	else
		CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}





void CLaboratoryWork01Dlg::OnToolsLight()
{
	_oglWindow.lightSwitch();
}



void CLaboratoryWork01Dlg::OnStnClickedOglControl()
{

}





void CLaboratoryWork01Dlg::SaveScene()
{
	

	if (_oglWindow.figures().empty())
	{
		MessageBox(_T("Nothing to save!"));
		return;
	}
	_figuresRS.Open();
	_facesRS.Open();
	_sessionsRS.Open();
	_propertiesRS.Open();
	int sID, figID, faceID;
	sID = _sessionsRS.addRecord();
	for (auto figure : _oglWindow.figures())
	{
		figID = _figuresRS.addRecord(sID);
		figure->saveProperties(_propertiesRS, figID);
		//for (unsigned int i = 0; i < figure->faces().size(); i++)
		//{
		//	faceID = _facesRS.addRecord(figID);
		//	figure->faces()[i]->saveProperties(_propertiesRS, figID, faceID);
		//}
	}
	_figuresRS.Close();
	_facesRS.Close();
	_sessionsRS.Close();
	_propertiesRS.Close();
}

void CLaboratoryWork01Dlg::LoadScene(int sessionID)
{
	
	_figuresRS.m_strFilter.Format(_T("[SESSION_ID] = %d"), sessionID);
	_figuresRS.Open();
	if (_figuresRS.IsEOF() && _figuresRS.IsBOF())
	{
		MessageBox(_T("Invalid SESSION_ID"));
		_figuresRS.m_strFilter = "";
		_figuresRS.Close();
		return;
	}
	_oglWindow.clearScene();
	//_figuresRS.Update();
	if (!_figuresRS.IsBOF())
		_figuresRS.MoveFirst();
	_propertiesRS.Open();
	while (!_figuresRS.IsEOF())
	{
		_propertiesRS.m_strFilter.Format(_T("[FIGURE_ID] = %d"), _figuresRS.m_ID);
		_propertiesRS.Requery();
		//_facesRS.m_strFilter.Format(_T("[FIGURE_ID] = %d", _figuresRS.m_ID));
		_oglWindow.loadFigure(_propertiesRS);
		_figuresRS.MoveNext();
	}
	
	_propertiesRS.m_strFilter = "";
	_figuresRS.m_strFilter = "";
	_figuresRS.Close();
	_propertiesRS.Close();
}







void CLaboratoryWork01Dlg::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	_propertiesRS.clearRecords();
	_figuresRS.clearRecords();
	_sessionsRS.clearRecords();
	_facesRS.clearRecords();
	SaveScene();
	CDialogEx::OnClose();
}


