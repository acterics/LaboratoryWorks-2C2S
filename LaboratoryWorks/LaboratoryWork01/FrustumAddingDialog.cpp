// FrustumAddingDialog.cpp : implementation file
//

#include "stdafx.h"
#include "LaboratoryWork01.h"
#include "FrustumAddingDialog.h"
#include "afxdialogex.h"


// FrustumAddingDialog dialog

IMPLEMENT_DYNAMIC(FrustumAddingDialog, CDialogEx)

FrustumAddingDialog::FrustumAddingDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ADD_FRUSTUM_DIALOG, pParent)
	, _height(_T(""))
	, _topRadius(_T(""))
	, _bottomRadius(_T(""))
{

}


FrustumAddingDialog::~FrustumAddingDialog()
{
}

void FrustumAddingDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_HEIGHT, _height);
	DDX_Control(pDX, IDC_HEIGHT_SCROLL, _heightSlider);
	DDX_Text(pDX, IDC_TOP_RADIUS, _topRadius);
	DDX_Control(pDX, IDC_TOP_RADIUS_SCROLL, _topRadiusSlider);
	DDX_Text(pDX, IDC_BOTTOM_RADIUS, _bottomRadius);
	DDX_Control(pDX, IDC_BOTTOM_RADIUS_SCROLL, _bottomRadiusSlider);
	DDX_Control(pDX, IDC_X_COORDINATE, _xCoordinate);
	DDX_Control(pDX, IDC_Y_COORDINATE, _yCoordinate);
	DDX_Control(pDX, IDC_Z_COORDINATE, _zCoordinate);
}

BOOL FrustumAddingDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	_heightSlider.SetRange(0, 10, TRUE);
	_heightSlider.SetPos(1);
	_height.Format(_T("%d"), 1);

	_topRadiusSlider.SetRange(0, 10, TRUE);
	_topRadiusSlider.SetPos(1);
	_topRadius.Format(_T("%d"), 1);

	_bottomRadiusSlider.SetRange(0, 10, TRUE);
	_bottomRadiusSlider.SetPos(1);
	_bottomRadius.Format(_T("%d"), 1);

	UpdateData(FALSE);
	return TRUE;
}


BEGIN_MESSAGE_MAP(FrustumAddingDialog, CDialogEx)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// FrustumAddingDialog message handlers


void FrustumAddingDialog::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	if (pScrollBar == (CScrollBar *)&_heightSlider)
	{
		int value = _heightSlider.GetPos();
		_height.Format(_T("%d"), value);
		UpdateData(FALSE);
	}
	if (pScrollBar == (CScrollBar *)&_topRadiusSlider)
	{
		int value = _topRadiusSlider.GetPos();
		_topRadius.Format(_T("%d"), value);
		UpdateData(FALSE);
	}
	if (pScrollBar == (CScrollBar *)&_bottomRadiusSlider)
	{
		int value = _bottomRadiusSlider.GetPos();
		_bottomRadius.Format(_T("%d"), value);
		UpdateData(FALSE);
	}
	else
		CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}
