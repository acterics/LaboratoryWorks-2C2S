#include "stdafx.h"
#include "Figure.h"
using namespace GraphicElements;

void GraphicElements::Figure::initBorder()
{
	long	maxX = INT16_MIN,
			maxY = INT16_MIN,
			minX = INT16_MAX,
			minY = INT16_MAX;
	_maxZ = INT16_MIN;
	CRect current;
	for (auto face : _faces)
	{
		current = face->faceRect();
		if (current.left > maxX)
			maxX = current.left;
		if (current.right < minX)
			minX = current.right;
		if (current.top > maxY)
			maxY = current.top;
		if (current.bottom < minY)
			minY = current.bottom;
		if(face->maxZ() > _maxZ)
			_maxZ = face->maxZ();

	}

	_border.SetRect(CPoint(maxX + BORDER_PADDING, maxY + BORDER_PADDING), CPoint(minX - BORDER_PADDING, minY - BORDER_PADDING));
}

void GraphicElements::Figure::rotateBorder(glm::vec2 rotation)
{
	glm::vec3 topLeft(_border.left, _border.top, _position.z * ACCURACY);
	glm::vec3 bottomRight(_border.right, _border.bottom, _position.z * ACCURACY);

	topLeft = xRotationMatrix(rotation.x) * yRotationMatrix(rotation.y) * topLeft;
	bottomRight = xRotationMatrix(rotation.x) * yRotationMatrix(rotation.y) * bottomRight;
	_border.SetRect(CPoint((int)topLeft.x, (int)topLeft.y),
		CPoint((int)bottomRight.x, (int)bottomRight.y));
}

void GraphicElements::Figure::changeBorderVisible()
{
	if (_borderVisible)
		_borderVisible = false;
	else
		_borderVisible = true;
}

void GraphicElements::Figure::drawBorder()
{
	if (!_borderVisible)
		return;
	glEnable(GL_LINE_STIPPLE);
	glLineWidth(2);
	glLineStipple(5, GL_LINE_STIPPLE_PATTERN);
	glColor3f(1, 1, 1);
	glBegin(GL_LINE_LOOP);
	glVertex3f((float)_border.TopLeft().x / ACCURACY, (float)_border.TopLeft().y / ACCURACY, _position.z/*(float)_maxZ / ACCURACY*/);
	glVertex3f((float)_border.BottomRight().x / ACCURACY, (float)_border.TopLeft().y / ACCURACY, _position.z/*(float)_maxZ / ACCURACY*/);
	glVertex3f((float)_border.BottomRight().x / ACCURACY, (float)_border.BottomRight().y / ACCURACY, _position.z/*(float)_maxZ / ACCURACY*/);
	glVertex3f((float)_border.TopLeft().x / ACCURACY, (float)_border.BottomRight().y / ACCURACY, _position.z/*(float)_maxZ / ACCURACY*/);
	glEnd();
	glDisable(GL_LINE_STIPPLE);
	glLineWidth(1);
}

Figure::Figure()
{
}

GraphicElements::Figure::Figure(glm::vec3 pos, glm::vec3 col) :
	Figure(pos, col, glm::vec3(0, 0, 0))
{
}

GraphicElements::Figure::Figure(glm::vec3 pos, glm::vec3 col, glm::vec3 rot) :
	Figure(pos, col, rot, 1)
{
	
}

GraphicElements::Figure::Figure(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, float scale) :
	GraphicElement(pos, col, rot, scale)
{
	_borderVisible = false;
}


Figure::~Figure()
{
}

void GraphicElements::Figure::draw()
{
	applyColor();
	for (auto face : _faces)
		face->draw(_position, _rotation);
	initBorder();
	drawBorder();
}

void GraphicElements::Figure::addFace(Face * face)
{
	_faces.push_back(face);
}

void GraphicElements::Figure::scale(float scaleFactor)
{
	_scale *= scaleFactor;
	for (Face * face : _faces)
		face->scale(scaleFactor);
}

void GraphicElements::Figure::setColor(glm::vec3 color)
{
	GraphicElement::setColor(color);
	for (Face * face : _faces)
		face->setColor(color);
}

void GraphicElements::Figure::setPolygonMode(UINT mode)
{
	GraphicElement::setPolygonMode(mode);
	for (Face * face : _faces)
		face->setPolygonMode(mode);
}

float * GraphicElements::Figure::detectCollision(glm::vec2 p)
{
	p *= ACCURACY;
	if (p.x < _border.left && p.x > _border.right)
	{
		if (p.y < _border.top && p.y > _border.bottom)
		{
			return new float(_maxZ);
		}
	}
	return nullptr;
	
		
}

float * GraphicElements::Figure::detectCollision(CPoint p)
{
	p.x *= ACCURACY;
	p.x *= ACCURACY;
	if (_border.PtInRect(p))
		return new float(_maxZ);
	return nullptr;


}
