#include "stdafx.h"
#include "DialogControls.h"


DialogControls::DialogControls()
{
}


DialogControls::~DialogControls()
{
}

void DialogControls::operator=(DialogControls &d)
{
	m_openGLMode = d.m_openGLMode;
	m_selectedFigureColor = d.m_selectedFigureColor;
	m_deleteFigureButton = d.m_deleteFigureButton;
}

void DialogControls::ShowFigureControls()
{
	m_selectedFigureColor->ShowWindow(SW_SHOW);
	m_deleteFigureButton->ShowWindow(SW_SHOW);
}

void DialogControls::HideFigureControls()
{
	m_selectedFigureColor->ShowWindow(SW_HIDE);
	m_deleteFigureButton->ShowWindow(SW_HIDE);
}
