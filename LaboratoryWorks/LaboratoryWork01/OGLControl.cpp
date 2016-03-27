// OGLControl.cpp : implementation file
//

#include "stdafx.h"
#include "OGLControl.h"
#include "LaboratoryWork01.h"
#include "afxdialogex.h"


// OGLControl dialog

//IMPLEMENT_DYNAMIC(OGLControl, CDialog)

void OGLControl::lightSwitch()
{
	if (_lightOn)
	{
		glDisable(GL_LIGHTING);
		_lightOn = false;
	}
	else
	{
		glEnable(GL_LIGHTING);
		_lightOn = true;
	}
}

void OGLControl::loadFigure(CProperties &pRS)
{
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 color;
	int type;
	float scale;
	pRS.MoveFirst();
	while (!pRS.IsEOF())
	{
		if (pRS.m_NAME == "PositionX")
			position.x = pRS.m_VALUE;
		if (pRS.m_NAME == "PositionY")
			position.y = pRS.m_VALUE;
		if (pRS.m_NAME == "PositionZ")
			position.z = pRS.m_VALUE;
		if (pRS.m_NAME == "ColorR")
			color.x = pRS.m_VALUE;
		if (pRS.m_NAME == "ColorG")
			color.y = pRS.m_VALUE;
		if (pRS.m_NAME == "ColorB")
			color.z = pRS.m_VALUE;
		if (pRS.m_NAME == "RotationX")
			rotation.x = pRS.m_VALUE;
		if (pRS.m_NAME == "RotationY")
			rotation.y = pRS.m_VALUE;
		if (pRS.m_NAME == "RotationZ")
			rotation.z = pRS.m_VALUE;
		if (pRS.m_NAME == "Scale")
			scale = pRS.m_VALUE;
		if (pRS.m_NAME == "Type")
			type = (int)pRS.m_VALUE;

		pRS.MoveNext();
	}
		
	
	switch (type)
	{
	case TYPE_FRUSTUM:
		loadFrustum(position, color, rotation, scale, pRS);
		break;
	case TYPE_PRISM:
		loadPrism(position, color, rotation, scale, pRS);
		break;
	default:
		break;
	}
}

void OGLControl::loadFrustum(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, float scale, CProperties& pRS)
{

	float smooth;
	float height;
	float topR;
	float bottR;
	pRS.MoveFirst();
	while (!pRS.IsEOF())
	{
		if (pRS.m_NAME == "Smooth")
			smooth = pRS.m_VALUE;
		if (pRS.m_NAME == "Height")
			height = pRS.m_VALUE;
		if (pRS.m_NAME == "TopRadius")
			topR = pRS.m_VALUE;
		if (pRS.m_NAME == "BottomRadius")
			bottR = pRS.m_VALUE;
		pRS.MoveNext();
	}
	_figures.push_back(new Frustum(pos, col, rot, scale, height, topR, bottR, (unsigned int)smooth));
}

void OGLControl::loadPrism(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, float scale, CProperties & pRS)
{
	float height;
	glm::vec3 topFaceTrans;
	glm::vec3 a, b, c, d;
	pRS.MoveFirst();
	while (!pRS.IsEOF())
	{
		if (pRS.m_NAME == "Height")
			height = pRS.m_VALUE;
		if (pRS.m_NAME == "TopFaceTranslationX")
			topFaceTrans.x = pRS.m_VALUE;
		if (pRS.m_NAME == "TopFaceTranslationY")
			topFaceTrans.y = pRS.m_VALUE;
		if (pRS.m_NAME == "TopFaceTranslationZ")
			topFaceTrans.z = pRS.m_VALUE;

		if (pRS.m_NAME == "Ax")
			a.x = pRS.m_VALUE;
		if (pRS.m_NAME == "Ay")
			a.y = pRS.m_VALUE;
		if (pRS.m_NAME == "Az")
			a.z = pRS.m_VALUE;

		if (pRS.m_NAME == "Bx")
			b.x = pRS.m_VALUE;
		if (pRS.m_NAME == "By")
			b.y = pRS.m_VALUE;
		if (pRS.m_NAME == "Bz")
			b.z = pRS.m_VALUE;

		if (pRS.m_NAME == "Cx")
			c.x = pRS.m_VALUE;
		if (pRS.m_NAME == "Cy")
			c.y = pRS.m_VALUE;
		if (pRS.m_NAME == "Cz")
			c.z = pRS.m_VALUE;

		if (pRS.m_NAME == "Dx")
			d.x = pRS.m_VALUE;
		if (pRS.m_NAME == "Dy")
			d.y = pRS.m_VALUE;
		if (pRS.m_NAME == "Dz")
			d.z = pRS.m_VALUE;
		pRS.MoveNext();
	}

	_figures.push_back(new QuadrangularPrism(pos, col, rot, scale, topFaceTrans, height, new Quadrangle(col, a, b, c, d)));
}

void OGLControl::setDefaultSceneState()
{
	//_fZoom = 10.0f;
	_fPosX = 0.0f;
	_fPosY = 0.0f;
	_fRotX = 0.0f;
	_fRotY = 0.0f;
}

void OGLControl::changeColor()
{
	COLORREF color = _controls.m_selectedFigureColor->GetColor();
	glm::vec3 colorVec(GetRValue(color), GetGValue(color), GetBValue(color));
	colorVec /= 255;

	for (Figure * figure : _selected)
	{
		figure->setColor(colorVec);
	}
}

void OGLControl::enableInterseptMode()
{
	for (Figure * figure : _figures)
		figure->setPolygonMode(GL_LINE);
}

void OGLControl::disableInterseptMode()
{
	for (Figure * figure : _figures)
		figure->setPolygonMode(GL_FILL);
}

glm::vec2 OGLControl::projection(CPoint point)
{
	GetWindowRect(_rect);
	return glm::vec2(((point.x - (float)(_rect.Width()) / 2) / (float)(_rect.Width()) / 2) * MATRIX_SIZE * 2 * (_fZoom / 10)
		, (((float)(_rect.Height()) / 2 - point.y) / (float)(_rect.Height()) / 2) * MATRIX_SIZE * 2 * (_fZoom / 10));
}

BOOL OGLControl::isSelect(CRect b)
{
	if (b.left < _selectRect.left)
		return false;
	if (b.bottom < _selectRect.bottom)
		return false;
	if (b.right > _selectRect.right)
		return false;
	if (b.top > _selectRect.top)
		return false;
	return true;
}


OGLControl::OGLControl()
{
	_isMaximized = false;
	_selecting = false;
	_fZoom = 10.0f;
	_fPosX = 0.0f;
	_fPosY = 0.0f;
	_fRotX = 0.0f;
	_fRotY = 0.0f;
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
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClearDepth(1.0f);

	glEnable(GL_COLOR_MATERIAL);


	_lightOn = true;



	// Turn on backface culling 
	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);

	// Turn on depth testing 
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	glEnable(GL_LIGHTING);
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	glEnable(GL_NORMALIZE);


	glEnable(GL_LIGHT0);
	float light_ambient[] = { 0.0,0.0,0.0,1.0 };
	float light_diffuse[] = { 0.5,0.5,0.5,1.0 };
	float light_specular[] = { 1.0,1.0,1.0,1.0 };
	float light_position[] = { 10, 0, 1.0 ,0.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	OnDraw(NULL);
}

void OGLControl::oglDrawScene()
{
	
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -_fZoom);

	glPushMatrix();

	glTranslatef(_fPosX, _fPosY, 0.0f);
	glRotatef(_fRotX, 1.0f, 0.0f, 0.0f);
	glRotatef(_fRotY, 0.0f, 1.0f, 0.0f);



	glColor3d(1, 1, 1);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	glVertex3f(MATRIX_SIZE * _fZoom / 10, 0, 0);

	glVertex3f(0, 0, 0);
	glVertex3f(0, MATRIX_SIZE * _fZoom / 10, 0);

	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, MATRIX_SIZE * _fZoom / 10);
	glEnd();

	if (_selecting)
	{
		glEnable(GL_LINE_STIPPLE);
		glLineWidth(2);
		glLineStipple(5, GL_LINE_STIPPLE_PATTERN);
		glColor3f(1, 1, 1);
		glBegin(GL_LINE_LOOP);
		glVertex3f((float)_selectRect.TopLeft().x / ACCURACY, (float)_selectRect.TopLeft().y / ACCURACY, 0);
		glVertex3f((float)_selectRect.BottomRight().x / ACCURACY, (float)_selectRect.TopLeft().y / ACCURACY, 0);
		glVertex3f((float)_selectRect.BottomRight().x / ACCURACY, (float)_selectRect.BottomRight().y / ACCURACY, 0);
		glVertex3f((float)_selectRect.TopLeft().x / ACCURACY, (float)_selectRect.BottomRight().y / ACCURACY, 0);
		glEnd();
		glDisable(GL_LINE_STIPPLE);
		glLineWidth(1);
	}

	for (auto figure : _figures)
		figure->draw();
	glPopMatrix();
	
	glPopMatrix();

	

}

void OGLControl::addFigure(Figure * f)
{
	_figures.push_back(f);
}

void OGLControl::clearScene()
{
	_figures.clear();
}

void OGLControl::rotateX(float a)
{
	for (auto figure = _figures.begin(); figure != _figures.end(); figure++)
	{
		(*figure)->rotate(glm::vec3(a, 0, 0));
	}
}

void OGLControl::rotateY(float a)
{
	for (auto figure = _figures.begin(); figure != _figures.end(); figure++)
	{
		(*figure)->rotate(glm::vec3(0, a, 0));
	}
}

float OGLControl::getValue(CString var)
{
	int resultNumber;
	std::string input;
	for (int i = 0; i < var.GetLength(); i++)
		input.push_back((char)var[i]);
	std::istringstream convertingStream(input);
	convertingStream >> resultNumber;
	return (float)resultNumber;
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
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEWHEEL()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()


// OGLControl message handlers





void OGLControl::OnTimer(UINT_PTR nIDEvent)
{
	if (_selected.empty())
	{
		_controls.HideFigureControls();
		
	}
	else
	{
		_controls.ShowFigureControls();

		glm::vec3 colorVec = _selected.front()->color();
		colorVec *= 255;
		COLORREF color = RGB(colorVec.x, colorVec.y, colorVec.z);
		_controls.m_selectedFigureColor->SetColor(color);
	}
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



}


void OGLControl::OnPaint()
{
	ValidateRect(NULL);
}


void OGLControl::OnSize(UINT nType, int cx, int cy)
{

	CWnd::OnSize(nType, cx, cy);

	if (0 >= cx || 0 >= cy || nType == SIZE_MINIMIZED) return;


	GetWindowRect(_rect);
	_viewAngle = 60;
	_cameraPos = glm::vec3(0, 0, 5);
	double	 aspect = (cy == 0) ? cx : (double)cx / (double)cy;

	glViewport(0, 0, cx, cy);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(_viewAngle, aspect, 0.1, 170.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(_cameraPos.x, _cameraPos.y, _cameraPos.z, 0, 0, 0, 0, 1, 0);
	glDrawBuffer(GL_BACK);

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


void OGLControl::OnMouseMove(UINT nFlags, CPoint point)
{
	int diffX = (int)(point.x - _fLastX);
	int diffY = (int)(point.y - _fLastY);
	_fLastX = (float)point.x;
	_fLastY = (float)point.y;
	switch (_mode)
	{
	case SELECT: 
	{
		if (!_selected.empty())
		{

			if (nFlags & MK_LBUTTON)
			{
				glm::vec3 translation(0.0032f * diffX * _fZoom, 0.0032f * (-diffY) * _fZoom, 0);
				
				for (Figure * s : _selected)
				{
					
					s->translate(translation);
					//s->rotate(glm::vec3(_fRotY, _fRotY, 0));
				}
					
				glPopMatrix();
			}
			if (nFlags & MK_MBUTTON)
			{
				glm::vec3 translation(0, 0, 0.0032f * (-diffY) * _fZoom);

				//_selected->translate(translation);

			}
			if (nFlags & MK_RBUTTON)
			{
				for (Figure * s : _selected)
					s->rotate(glm::vec3(PI * diffY / 180, PI * diffX / 180,  0));
			}
		}
		else
		{
			glm::vec2 p = projection(point);
			if (nFlags & MK_LBUTTON)
			{
				if(_selecting)
					_selectRect.SetRect(_selectRect.TopLeft(), CPoint((int)(p.x * ACCURACY), (int)(p.y * ACCURACY)));
			}
		}
		break;
	};
	case ROTATE:
	{
		if (nFlags & MK_LBUTTON)
		{
			_fRotX += (float)0.5f * diffY;


			if ((_fRotX > 360.0f) || (_fRotX < -360.0f))
			{
				_fRotX = 0.0f;
			}

			_fRotY += (float)0.5f * diffX;

			if ((_fRotY > 360.0f) || (_fRotY < -360.0f))
			{
				_fRotY = 0.0f;
			}
		}

		// Right mouse button
		else if (nFlags & MK_RBUTTON)
		{
			_fZoom -= (float)0.1f * diffY;
		}

		// Middle mouse button
		else if (nFlags & MK_MBUTTON)
		{
			_fPosX += (float)0.05f * diffX;
			_fPosY -= (float)0.05f * diffY;
		}

		OnDraw(NULL);

		CWnd::OnMouseMove(nFlags, point);
		break;
	}
	case OGLControl::INTERSEPT:
		break;
	default:
		break;
	}
	
}


void OGLControl::OnLButtonDown(UINT nFlags, CPoint point)
{

	
	switch (_mode)
	{
	case OGLControl::SELECT:
	{
		if (!_selected.empty())
			return;
		Figure *s = nullptr;
		glm::vec2 p = projection(point);
		float maxZ = INT16_MIN;
		float *current = nullptr;
		for (auto figure = _figures.begin(); figure != _figures.end(); figure++)
		{
			if ((*figure)->detectCollision(p))
			{
				current = (*figure)->detectCollision(p);
				if (*current > maxZ)
				{
					maxZ = *current;
					s = *figure;
				}
			}
		}

		if (s)
		{
			if (_selected.empty())
				_selected.push_back(s);
			else
			{
				for (Figure * f : _selected)
					if (s == f)
						return;
				_selected.clear();
				for (Figure *s : _figures)
					s->borderVisibleOff();
			}

		}		
		else
		{
			_selecting = true;
			_selectRect.SetRect(CPoint((int)(p.x * ACCURACY), (int)(p.y * ACCURACY)), CPoint((int)(p.x * ACCURACY), (int)(p.y * ACCURACY)));
			_selected.clear();
			for (Figure *s : _figures)
				s->borderVisibleOff();
			return;
		}
		for (Figure *s : _selected)
			s->borderVisibleOn();
		break;
	}
	case OGLControl::ROTATE:
		break;
	case OGLControl::INTERSEPT:
		break;
	default:
		break;
	}
}


BOOL OGLControl::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	switch (_mode)
	{
	case OGLControl::SELECT:
	{
		if (!_selected.empty())
		{
			float factor;
			if (zDelta > 0)
				factor = 1.1f;
			else
				factor = 0.9f;

			for (Figure * s : _selected)
				s->scale(factor);
		}
		break;
	}
		
	case OGLControl::ROTATE:
		break;
	case OGLControl::INTERSEPT:
		break;
	default:
		break;
	}
	// TODO: Add your message handler code here and/or call default
	

	return CWnd::OnMouseWheel(nFlags, zDelta, pt);
}


void OGLControl::OnLButtonUp(UINT nFlags, CPoint point)
{
	switch (_mode)
	{
	case OGLControl::SELECT:
	{
		if (_selecting)
		{

			_selected.clear();
			for (Figure * figure : _figures)
			{
				if (isSelect(figure->border()))
					_selected.push_back(figure);
			}
			if (!_selected.empty())
			{
				for (Figure *s : _selected)
					s->borderVisibleOn();
			}
			_selecting = false;
		}
		else
		{
			glm::vec2 p = projection(point);
			for (Figure * figure : _selected)
			{
				if (figure->detectCollision(p))
				{
					return;
				}
			}
			_selected.clear();
			for (Figure *s : _figures)
				s->borderVisibleOff();
		}
		break;
	}
	case OGLControl::ROTATE:
		break;
	case OGLControl::INTERSEPT:
		break;
	default:
		break;
	}
	
		
}


void OGLControl::OnLButtonDblClk(UINT nFlags, CPoint point)
{

}


void OGLControl::deleteFigure()
{
	for (Figure *s : _selected)
	{
		for (auto f = _figures.begin(); f != _figures.end(); f++)
		{
			if (s == (*f))
			{
				_figures.erase(f);
				delete s;
				break;
			}
					
		}
	}
	_selected.clear();
}


