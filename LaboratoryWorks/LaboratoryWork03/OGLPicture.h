#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "GameModel\GameField.h"


class CLaboratoryWork03Dlg;
#define STEP_COUNT 200

#define FIELD_WIDTH 32
#define FIELD_HEIGHT 32
class OGLPicture : public CWnd
{
	
public:
	
	BOOL _isMaximized;
	UINT _unpTimer;
private:


	GameField _gameField;
	int _step;

	CRect _rect;
	CRect _originalRect;
	CRect _oldWindow;
	

	int _pixelFormat;
	HDC _hdc;
	HGLRC _hrc;

	CWnd * _hWnd;

	BOOL _isRunning;


public:
	OGLPicture(void); 
	virtual ~OGLPicture(void);
	void oglCreate(CRect rect, CWnd * parrent);
	void oglInitialize(void);
	void oglDrawScene(void);

	void updateField();
	void run();
	void stop();

	int apples();
	int step();

	void initAnt(CLaboratoryWork03Dlg * pP);
	void restart();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDC_OGL_PICTURE};
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
