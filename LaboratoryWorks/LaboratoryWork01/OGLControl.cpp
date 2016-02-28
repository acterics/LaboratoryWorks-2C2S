// OGLControl.cpp : implementation file
//

#include "stdafx.h"
#include "OGLControl.h"


// OGLControl dialog

//IMPLEMENT_DYNAMIC(OGLControl, CDialog)

OGLControl::OGLControl()
{
	_isMaximized = false;
	_fZoom = 10.0f;
	_fPosX = 0.0f;
	_fPosY = 0.0f;
	_fRotX =0.0f;
	_fRotY = -0.0f;

}

void OGLControl::oglCreate(CRect rect, CWnd * parent)
{
	CString className = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_OWNDC, NULL, (HBRUSH)GetStockObject(BLACK_BRUSH), NULL);

	CreateEx(0, className, _T("OpenGL"), WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN, rect, parent, 0);
	_oldWindow = rect;
	_originalRect = rect;

	_hWnd = parent;
}

void OGLControl::oglInitialize()
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

	// Basic Setup:
	//
	// Set color to use when clearing the background.
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);
	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);
	//float ambient[4] = { 1, 1, 1, 0 };
	//float pos[4] = { 3, 6, -3, 0.5 };
	//float dir[3] = { -1, -1, -1 };
	//GLfloat mat_specular[] = { 0, 1, 1, 1 };
	//glLightfv(GL_LIGHT0, GL_POSITION, pos);
	//glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dir);

	//glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	//glMaterialf(GL_FRONT, GL_SHININESS, 128.0);


	//glLighti(GL_LIGHT0, GL_SPOT_EXPONENT, 0);
	//glLighti(GL_LIGHT0, GL_SPOT_CUTOFF, 90);

	// Turn on backface culling
	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);

	// Turn on depth testing
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	// Send draw request
	OnDraw(NULL);
}

void OGLControl::oglDrawScene()
{
	for (auto figure : _figures)
		figure->draw();
	//glColor3f(1, 1, 1);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//glBegin(GL_LINES);
	//glVertex3f(0, 0, 0);
	//glVertex3f(1, 0, 0);

	//glVertex3f(0, 0, 0);
	//glVertex3f(0, 1, 0);

	//glVertex3f(0, 0, 0);
	//glVertex3f(0, 0, 1);
	//glEnd();

}

void OGLControl::addFigure(Figure * f)
{
	_figures.push_back(f);
}

void OGLControl::clearScene()
{
	_figures.clear();
	_fZoom = 10.0f;
	_fPosX = 0.0f;
	_fPosY = 0.0f;
	_fRotX = 0.0f;
	_fRotY = -0.0f;
}

float OGLControl::getValue(CString var)
{
	int resultNumber;
	std::string input;
	for (unsigned int i = 0; i < var.GetLength(); i++)
		input.push_back(var[i]);
	std::istringstream convertingStream(input);
	convertingStream >> resultNumber;
	return resultNumber;
}

glm::vec3 OGLControl::getColor(CString var)
{
	if (var == "Red")
		return COLOR_RED;
	if (var == "Blue")
		return COLOR_BLUE;
	if (var == "Green")
		return COLOR_GREEN;
	if (var == "White")
		return COLOR_WHITE;
	if (var == "Black")
		return COLOR_BLACK;
	else
		return COLOR_RED;
}

OGLControl::~OGLControl()
{
}



BEGIN_MESSAGE_MAP(OGLControl, CWnd)
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_SIZE()
END_MESSAGE_MAP()


// OGLControl message handlers


void OGLControl::OnTimer(UINT_PTR nIDEvent)
{
	switch (nIDEvent)
	{
	case 1:
	{
		// Clear color and depth buffer bits
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Draw OpenGL scene
		oglDrawScene();

		// Swap buffers
		SwapBuffers(_hdc);

		break;
	}

	default:
		break;
	}
	//fr.components()[0]->rotate(0, 0, PI / 300);
	_fRotX += _xRotationSpeed;
	_fRotY += _yRotationSpeed;
	OnDraw(NULL);
	CWnd::OnTimer(nIDEvent);
}


int OGLControl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	oglInitialize();

	// TODO:  Add your specialized creation code here

	return 0;
}

void OGLControl::OnDraw(CDC * pDC)
{
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -_fZoom);
	glTranslatef(_fPosX, _fPosY, 0.0f);
	glRotatef(_fRotX, 1.0f, 0.0f, 0.0f);
	glRotatef(_fRotY, 0.0f, 1.0f, 0.0f);
}


void OGLControl::OnPaint()
{
	ValidateRect(NULL);
}


void OGLControl::OnSize(UINT nType, int cx, int cy)
{

	CWnd::OnSize(nType, cx, cy);

	if (0 >= cx || 0 >= cy || nType == SIZE_MINIMIZED) return;

	// Map the OpenGL coordinates.
	glViewport(0, 0, cx , cy );

	// Projection view
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	// Set our current view perspective
	gluPerspective(60.0f, (float)cx / (float)cy, 0.01f, 2000.0f);

	// Model view
	glMatrixMode(GL_MODELVIEW);

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
