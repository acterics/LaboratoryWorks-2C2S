// OGLControl.cpp : implementation file
//

#include "stdafx.h"
#include "OGLPicture.h"
#include "LaboratoryWork03.h"
#include "LaboratoryWork03Dlg.h"
#include "GameModel\BehaviorGenerator.h"
#include "afxdialogex.h"
#include <gl\GL.h>
#include <gl\GLU.h>



OGLPicture::OGLPicture() :
	_gameField(FIELD_WIDTH, FIELD_HEIGHT)
{
	_isMaximized = false;
	_isRunning = false;
	_step = 0;
}

void OGLPicture::oglCreate(CRect rect, CWnd * parent)
{
	CString className = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_OWNDC, NULL, (HBRUSH)GetStockObject(BLACK_BRUSH), NULL);

	CreateEx(0, className, _T("OpenGL"), WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN, rect, parent, 0);
	_oldWindow = rect;
	
	_originalRect = rect;

	_hWnd = parent;
}

void OGLPicture::oglInitialize()
{
	static PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,
		32, // bit depth
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		16, // z-buffer depth
		0, 0, 0, 0, 0, 0, 0,
	};

	// Get device context only once.
	_hdc = GetDC()->m_hDC;

	// Pixel format.
	_pixelFormat = ChoosePixelFormat(_hdc, &pfd);
	SetPixelFormat(_hdc, _pixelFormat, &pfd);

	// Create the OpenGL Rendering Context.
	_hrc = wglCreateContext(_hdc);
	wglMakeCurrent(_hdc, _hrc);


	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClearDepth(1.0f);


}

void OGLPicture::oglDrawScene()
{
	_gameField.drawField();
}



OGLPicture::~OGLPicture()
{
}



BEGIN_MESSAGE_MAP(OGLPicture, CWnd)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// OGLControl message handlers

int OGLPicture::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	oglInitialize();

	// TODO:  Add your specialized creation code here

	return 0;
}



void OGLPicture::OnPaint()
{
	ValidateRect(NULL);
}


void OGLPicture::OnSize(UINT nType, int cx, int cy)
{

	CWnd::OnSize(nType, cx, cy);

	if (0 >= cx || 0 >= cy || nType == SIZE_MINIMIZED) return;


	GetWindowRect(_rect);
	double	 aspect = (cy == 0) ? cx : (double)cx / (double)cy;

	//glViewport(0, 0, cx, cy);
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();

	glViewport(0, 0, cx, cy);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	switch (nType)
	{
		// If window resize token is "maximize"
	case SIZE_MAXIMIZED:
	{
		// Get the current window rect
		GetWindowRect(_rect);

		// Move the window accordingly
		MoveWindow(6, 6, cx - 14, cy - 14);

		// Get the new window rect
		GetWindowRect(_rect);

		// Store our old window as the new rect
		_oldWindow = _rect;

		break;
	}

	// If window resize token is "restore"
	case SIZE_RESTORED:
	{
		// If the window is currently maximized
		if (_isMaximized)
		{
			// Get the current window rect
			GetWindowRect(_rect);

			// Move the window accordingly (to our stored old window)
			MoveWindow(_oldWindow.left, _oldWindow.top - 18, _originalRect.Width() - 4, _originalRect.Height() - 4);

			// Get the new window rect
			GetWindowRect(_rect);

			// Store our old window as the new rect
			_oldWindow = _rect;
		}

		break;
	}
	}

}

void OGLPicture::OnTimer(UINT_PTR nIDEvent)
{
	CWnd::OnTimer(nIDEvent);
	switch (nIDEvent)
	{
	case 1:
	{
		// Clear color and depth buffer bits
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		if (_isRunning)
			updateField();
		// Draw OpenGL scene
		oglDrawScene();

		// Swap buffers
		SwapBuffers(_hdc);

		break;
	}
	}
}

void OGLPicture::updateField()
{
	_gameField.updateField();
	_step++;
}

void OGLPicture::run()
{
	_isRunning = true;
}

void OGLPicture::stop()
{
	_isRunning = false;
}

int OGLPicture::apples()
{
	return _gameField.apples();
}

int OGLPicture::step()
{
	return _step;
}


void OGLPicture::initAnt(CLaboratoryWork03Dlg * pP)
{
	BehaviorGenerator bGen(pP, _gameField, 0, 0);
	_gameField.initAnt(bGen);
}

void OGLPicture::restart()
{
	_gameField.reinit();
	_step = 0;
}