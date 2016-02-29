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
	, _isInited(FALSE)
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

BOOL PrismAddingDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	UpdateData(TRUE);
	_heightSlider.SetRange(0, 100, TRUE);
	_heightSlider.SetPos(30);
	_height.Format(_T("30"));

	_xCoordinateEdit.SetWindowTextW(_T("0"));
	_yCoordinateEdit.SetWindowTextW(_T("0"));
	_zCoordinateEdit.SetWindowTextW(_T("0"));

	_xFaceTranslation.SetWindowTextW(_T("0"));
	_yFaceTranslation.SetWindowTextW(_T("0"));
	_zFaceTranslation.SetWindowTextW(_T("0"));

	_yFaceTranslation.EnableWindow(FALSE);
	_zFaceTranslation.EnableWindow(FALSE);

	_quadHeightEdit.SetWindowTextW(_T("0"));
	_topEdgeEdit.SetWindowTextW(_T("0"));
	_topEdgeTranslation.SetWindowTextW(_T("0"));
	_bottomEdgeEdit.SetWindowTextW(_T("0"));

	_quadList.AddString(_T("Trapeze"));
	_quadList.AddString(_T("Parallelogram"));
	_quadList.AddString(_T("Rectangle"));
	

	_quadList.SetCurSel(0);

	_colorList.AddString(_T("Red"));
	_colorList.AddString(_T("Blue"));
	_colorList.AddString(_T("Green"));
	_colorList.AddString(_T("White"));
	_colorList.AddString(_T("Black"));

	

	_colorList.SetCurSel(0);

	_isInited = TRUE;
	UpdateData(FALSE);
	return TRUE;
}


BEGIN_MESSAGE_MAP(PrismAddingDialog, CDialogEx)
	ON_WM_HSCROLL()
	ON_LBN_SELCHANGE(IDC_QUADRANGLE_LIST, &PrismAddingDialog::OnLbnSelchangeQuadrangleList)
	ON_BN_CLICKED(IDOK, &PrismAddingDialog::OnBnClickedOk)
	ON_EN_CHANGE(IDC_TOP_EDGE_LENGTH, &PrismAddingDialog::OnEnChangeTopEdgeLength)
END_MESSAGE_MAP()


// AddPrismDialog message handlers


void PrismAddingDialog::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: Add your message handler code here and/or call default
	if (pScrollBar == (CScrollBar *)&_heightSlider)
	{
		int value = _heightSlider.GetPos();
		_height.Format(_T("%d"), value);
		UpdateData(FALSE);
	}
	else
		CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}


void PrismAddingDialog::OnLbnSelchangeQuadrangleList()
{
	UpdateData(TRUE);
	CString type, tmp;
	_quadList.GetText(_quadList.GetCurSel(), type);
	if (type == "Rectangle")
	{
		_topEdgeTranslation.SetWindowTextW(_T("0"));

		_topEdgeEdit.GetWindowTextW(tmp);
		_bottomEdgeEdit.SetWindowTextW(tmp);

		_topEdgeTranslation.EnableWindow(FALSE);
		_bottomEdgeEdit.EnableWindow(FALSE);
	}
	if (type == "Trapeze")
	{
		_topEdgeTranslation.EnableWindow(TRUE);
		_bottomEdgeEdit.EnableWindow(TRUE);
	}
	if (type == "Parallelogram")
	{
		_topEdgeEdit.GetWindowTextW(tmp);
		_bottomEdgeEdit.SetWindowTextW(tmp);
		_topEdgeTranslation.EnableWindow(TRUE);
		_bottomEdgeEdit.EnableWindow(FALSE);
	}
	UpdateData(FALSE);

}


void PrismAddingDialog::OnBnClickedOk()
{
	UpdateData(TRUE);
	CString x, y, z,
		xT, yT, zT,
		qHeight, qTopLength, qBottomLenth, qTrans;
	_xCoordinateEdit.GetWindowTextW(x);
	_yCoordinateEdit.GetWindowTextW(y);
	_zCoordinateEdit.GetWindowTextW(z);

	_xFaceTranslation.GetWindowTextW(xT);
	_yFaceTranslation.GetWindowTextW(yT);
	_zFaceTranslation.GetWindowTextW(zT);

	_quadHeightEdit.GetWindowTextW(qHeight);
	_topEdgeEdit.GetWindowTextW(qTopLength);
	_bottomEdgeEdit.GetWindowTextW(qBottomLenth);
	_topEdgeTranslation.GetWindowTextW(qTrans);

	CString color;
	_colorList.GetText(_colorList.GetCurSel(), color);

	_oglControl->addFigure(new QuadrangularPrism(glm::vec3(
			_oglControl->getValue(x),
			_oglControl->getValue(y),
			_oglControl->getValue(z)),
		_oglControl->getColor(color),
		glm::vec3(
			_oglControl->getValue(xT),
			_oglControl->getValue(yT),
			_oglControl->getValue(zT)),
		_oglControl->getValue(_height) / 10,
		new Trapeze(glm::vec3(0, 0, 0),
			_oglControl->getColor(color),
			glm::vec3(0, 0, 0),
			_oglControl->getValue(qHeight),
			_oglControl->getValue(qTopLength),
			_oglControl->getValue(qBottomLenth),
			_oglControl->getValue(qTrans)))
		);
	UpdateData(FALSE);
	CDialogEx::OnOK();
}


void PrismAddingDialog::OnEnChangeTopEdgeLength()
{
	if (_isInited)
		OnLbnSelchangeQuadrangleList();
}





