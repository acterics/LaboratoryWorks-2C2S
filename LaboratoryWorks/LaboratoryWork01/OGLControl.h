#pragma once
#include "afxwin.h"
#include "Frustum.h"
#include "QuadrangulaPrism.h"

//#include "Frustum.h"
//using namespace GraphicElements;
// OGLControl dialog
//using namespace GraphicElements;
using namespace GraphicElements;
class OGLControl : public CWnd
{
public:
	UINT_PTR _unpTimer;
	bool _isMaximized;
	float _fZoom;
	float _fPosX;
	float _fPosY;
	float _fRotX;
	float _fRotY;

	


private:


	//Frustum fr;

	//std::vector<Figure *> _figures;
	std::vector<Figure *> _figures;


	CRect _rect;
	CRect _originalRect;
	CRect _oldWindow;

	int _pixelFormat;
	HDC _hdc;
	HGLRC _hrc;

	CWnd * _hWnd;

public:
	OGLControl(void); 
	virtual ~OGLControl(void);
	void oglCreate(CRect rect, CWnd * parrent);
	void oglInitialize(void);
	void oglDrawScene(void);

	void addFigure(Figure * f);
	void clearScene();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LAB01TRAINING01_DIALOG };
#endif

protected:

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg	void OnDraw(CDC *pDC);
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
