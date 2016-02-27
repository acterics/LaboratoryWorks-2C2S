// AddPrismDialog.cpp : implementation file
//

#include "stdafx.h"
#include "LaboratoryWork01.h"
#include "PrismAddingDialog.h"
#include "afxdialogex.h"


// AddPrismDialog dialog

IMPLEMENT_DYNAMIC(PrismAddingDialog, CDialogEx)

PrismAddingDialog::PrismAddingDialog(OGLControl *o, CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ADD_PRISM_DIALOG, pParent)
	, _height(_T(""))
	, _oglControl(o)
{

}

PrismAddingDialog::~PrismAddingDialog()
{
}

void PrismAddingDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_X_COORDINATE, _xCoordinateEdit);
	DDX_Control(pDX, IDC_Y_COORDINATE, _yCoordinateEdit);
	DDX_Control(pDX, IDC_Z_COORDINATE, _zCoordinateEdit);
	DDX_Control(pDX, IDC_X_COORDINATE_TRANSLATION, _xFaceTranslation);
	DDX_Control(pDX, IDC_Y_COORDINATE_TRANSLATION, _yFaceTranslation);
	DDX_Control(pDX, IDC_Z_COORDINATE_TRANSLATION, _zFaceTranslation);
	DDX_Control(pDX, IDC_HEIGHT_SCROLL, _heightSlider);
	DDX_Text(pDX, IDC_HEIGHT, _height);
	DDX_Control(pDX, IDC_QUADRANGLE_LIST, _quadList);
	DDX_Control(pDX, IDC_COLOR_LIST, _colorList);
	DDX_Control(pDX, IDC_QUAD_HEIGHT, _quadHeightEdit);
	DDX_Control(pDX, IDC_TOP_EDGE_LENGTH, _topEdgeEdit);
	DDX_Control(pDX, IDC_BOTTOM_EDGE_LENGTH, _bottomEdgeEdit);
	DDX_Control(pDX, IDC_TOP_EDGE_TRANSLATION, _topEdgeTranslation);
}


BEGIN_MESSAGE_MAP(PrismAddingDialog, CDialogEx)
END_MESSAGE_MAP()


// AddPrismDialog message handlers
