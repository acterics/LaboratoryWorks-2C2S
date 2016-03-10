#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "Frustum.h"
#include "QuadrangularPrism.h"

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
	float	 _fLastX;
	float	 _fLastY;
	float _fZoom;
	float _fPosX;
	float _fPosY;
	float _fRotX;
	float _fRotY;

	BOOL _lightOn;

	

	void setXRotationSpeed(float a) { _xRotationSpeed = a; }
	void setYRotationSpeed(float a) { _yRotationSpeed = a; }
	void lightSwitch();
	std::vector<Figure *> figures() { return _figures; }
private:


	//Frustum fr;

	//std::vector<Figure *> _figures;
	std::vector<Figure *> _figures;

	float _xRotationSpeed;
	float _yRotationSpeed;

	CRect _rect;
	CRect _originalRect;
	CRect _oldWindow;

	int _pixelFormat;
	HDC _hdc;
	HGLRC _hrc;

	CWnd * _hWnd;

	CString _xOGLPositionEcho;
	CString _yOGLPositionEcho;


public:
	OGLControl(void); 
	virtual ~OGLControl(void);
	void oglCreate(CRect rect, CWnd * parrent);
	void oglInitialize(void);
	void oglDrawScene(void);

	void addFigure(Figure * f);
	void clearScene();
	void rotateX(float a);
	void rotateY(float a);

	float getValue(CString var);
	glm::vec3 getColor(CString var);

#ifdef AFX_DESIGN_TIME
	enum { IDD = DC_OGL_CONTROL};
#endif

protected:
	//virtual void DoDataExchange(CDataExchange* pDX);

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg	void OnDraw(CDC *pDC);
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};
