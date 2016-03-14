#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "Frustum.h"
#include "QuadrangularPrism.h"

#include "CFaces.h"
#include "CProperties.h"
#include <glm\gtx\transform.hpp>
#include "DialogControls.h"
  
#define MATRIX_SIZE 20

using namespace GraphicElements;
class OGLControl : public CWnd
{
	
public:
	
	enum Mode { SELECT, ROTATE, INTERSEPT };

	DialogControls _controls;

	UINT_PTR	_unpTimer;
	bool		_isMaximized;
	float		_fLastX;
	float		_fLastY;
	float		_fZoom;
	float		_fPosX;
	float		_fPosY;
	float		_fRotX;
	float		_fRotY;

	BOOL		_lightOn;
	BOOL		_selecting;
	Mode		_mode;

	float		_viewAngle;
	glm::vec3	_cameraPos;

	

	void setXRotationSpeed(float a) { _xRotationSpeed = a; }
	void setYRotationSpeed(float a) { _yRotationSpeed = a; }
	void lightSwitch();
	void setDefaultSceneState();
	void changeColor();
	void enableInterseptMode();
	void disableInterseptMode();
	std::vector<Figure *> figures() { return _figures; }

	void loadFigure(CProperties& pRS);
	

private:


	//Frustum fr;

	//std::vector<Figure *> _figures;
	std::vector<Figure *> _selected;
	std::vector<Figure *> _figures;

	float _xRotationSpeed;
	float _yRotationSpeed;

	CRect _rect;
	CRect _originalRect;
	CRect _oldWindow;

	CRect _selectRect;

	int _pixelFormat;
	HDC _hdc;
	HGLRC _hrc;

	CWnd * _hWnd;


	void loadFrustum(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, float scale, CProperties& pRS);
	void loadPrism(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, float scale, CProperties& pRS);

	

	glm::vec2 projection(CPoint point);

	BOOL isSelect(CRect b);


public:
	OGLControl(void); 
	virtual ~OGLControl(void);
	void oglCreate(CRect rect, CWnd * parrent);
	void oglInitialize(void);
	void oglDrawScene(void);

	void setMode(Mode mode) { _mode = mode; }

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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);

	void deleteFigure();
	afx_msg void OnBnClickedDeleteFigureButton();
};
