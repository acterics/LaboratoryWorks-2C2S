#pragma once
#include "afxwin.h"


// FigureAddingDialog dialog

class FigureAddingDialog : public CDialogEx
{
	DECLARE_DYNAMIC(FigureAddingDialog)

public:
	FigureAddingDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~FigureAddingDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD_FIGURE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListBox _figureList;
};
