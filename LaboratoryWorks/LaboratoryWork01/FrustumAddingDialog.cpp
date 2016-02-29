// FrustumAddingDialog.cpp : implementation file
//

#include "stdafx.h"
#include "LaboratoryWork01.h"
#include "FrustumAddingDialog.h"
#include "afxdialogex.h"


// FrustumAddingDialog dialog

IMPLEMENT_DYNAMIC(FrustumAddingDialog, CDialogEx)

FrustumAddingDialog::FrustumAddingDialog(OGLControl  *o, CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ADD_FRUSTUM_DIALOG, pParent)
	, _height(_T(""))
	, _topRadius(_T(""))
	, _bottomRadius(_T(""))
	, _oglControl(o)
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
	DDX_Control(pDX, IDC_COLOR_LIST, _colorList);
	DDX_Control(pDX, IDC_SMOOTH, _smooth);
}

BOOL FrustumAddingDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	_heightSlider.SetRange(0, 100, TRUE);
	_heightSlider.SetPos(30);
	_height.Format(_T("%d"), 30);

	_topRadiusSlider.SetRange(0, 100, TRUE);
	_topRadiusSlider.SetPos(10);
	_topRadius.Format(_T("%d"), 10);

	_bottomRadiusSlider.SetRange(0, 100, TRUE);
	_bottomRadiusSlider.SetPos(10);
	_bottomRadius.Format(_T("%d"), 10);
	

	_xCoordinate.ReplaceSel(_T("0"));
	_yCoordinate.ReplaceSel(_T("0"));
	_zCoordinate.ReplaceSel(_T("0"));

	_smooth.ReplaceSel(_T("18"));

	_colorList.AddString(_T("Red"));
	_colorList.AddString(_T("Blue"));
	_colorList.AddString(_T("Green"));
	_colorList.AddString(_T("White"));
	_colorList.AddString(_T("Black"));

	_colorList.SetCurSel(0);

	UpdateData(FALSE);
	return TRUE;
}




BEGIN_MESSAGE_MAP(FrustumAddingDialog, CDialogEx)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDOK, &FrustumAddingDialog::OnBnClickedOk)
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


void FrustumAddingDialog::OnBnClickedOk()
{
	CString x, y, z, smooth;
	_xCoordinate.GetWindowTextW(x);
	_yCoordinate.GetWindowTextW(y);
	_zCoordinate.GetWindowTextW(z);
	_smooth.GetWindowTextW(smooth);

	CString color;
	_colorList.GetText(_colorList.GetCurSel(), color);
	_oglControl->addFigure(new Frustum(
		glm::vec3(_oglControl->getValue(x),
			_oglControl->getValue(y),
			_oglControl->getValue(z)),
		_oglControl->getColor(color),
		_oglControl->getValue(_height) / 10,
		_oglControl->getValue(_topRadius) / 10,
		_oglControl->getValue(_bottomRadius) / 10,
		_oglControl->getValue(smooth)));
	CDialogEx::OnOK();
}
