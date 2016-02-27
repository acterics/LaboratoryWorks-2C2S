// FigureAddingDialog.cpp : implementation file
//

#include "stdafx.h"
#include "LaboratoryWork01.h"
#include "FigureAddingDialog.h"
#include "afxdialogex.h"


// FigureAddingDialog dialog

IMPLEMENT_DYNAMIC(FigureAddingDialog, CDialogEx)

FigureAddingDialog::FigureAddingDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ADD_FIGURE_DIALOG, pParent)
{

}

FigureAddingDialog::~FigureAddingDialog()
{
}

void FigureAddingDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FIGURE_LIST, _figureList);
}


BEGIN_MESSAGE_MAP(FigureAddingDialog, CDialogEx)
END_MESSAGE_MAP()


// FigureAddingDialog message handlers
