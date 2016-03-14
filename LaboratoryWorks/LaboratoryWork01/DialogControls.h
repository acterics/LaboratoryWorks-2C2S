#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "afxcolorbutton.h"
class DialogControls
{
public:
	DialogControls();
	~DialogControls();
	void operator=(DialogControls &);
	CButton				*m_openGLMode;
	CMFCColorButton		*m_selectedFigureColor;
	CButton				*m_deleteFigureButton;

	void ShowFigureControls();
	void HideFigureControls();

};

