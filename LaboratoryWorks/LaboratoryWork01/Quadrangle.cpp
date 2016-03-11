#include "stdafx.h"
#include "Quadrangle.h"
using namespace GraphicElements;



GraphicElements::Quadrangle::Quadrangle(Quadrangle & q) :
	Quadrangle(q._position, q._color, q._rotation, q._points[0], q._points[1], q._points[2], q._points[3])
{
}

GraphicElements::Quadrangle::Quadrangle(glm::vec3 col, glm::vec3 a, glm::vec3 b, glm::vec3 c, glm::vec3 d) :
	Quadrangle(glm::vec3(0, 0, 0), col, glm::vec3(0, 0, 0), a, b, c, d)
{
}

GraphicElements::Quadrangle::Quadrangle(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, Quadrangle * face) :
	Quadrangle(pos, col, rot, face->_points[0], face->_points[1], face->_points[2], face->_points[3])
{
}

GraphicElements::Quadrangle::Quadrangle(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, glm::vec3 a, glm::vec3 b, glm::vec3 c, glm::vec3 d) :
	Face(pos, col, rot)
{
	_drawingMode = GL_QUAD_STRIP;
	_points.push_back(a);
	_points.push_back(b);
	_points.push_back(c);
	_points.push_back(d);
	init();
}


Quadrangle::~Quadrangle()
{
}

void GraphicElements::Quadrangle::init()
{
	_normal = glm::normalize(glm::cross(_points[0] - _points[1], _points[2] - _points[1]));
	Face::init();
}


GraphicElements::Trapeze::Trapeze(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, float h, float tE, float bE, float tETr) :
	Quadrangle(pos, col, rot,
		glm::vec3(-tE / 2 + tETr, h / 2, 0),
		glm::vec3(-bE / 2, -h / 2, 0),
		glm::vec3(tE / 2 + tETr, h / 2, 0),
		glm::vec3(bE / 2, -h / 2, 0)), _height(h), _topEdge(tE), _bottomEdge(bE), _topEdgeTranslation(tETr)
{
}

void GraphicElements::Trapeze::saveProperties(CProperties & propertyRS, long figureID, long faceID)
{
	Face::saveProperties(propertyRS, figureID, faceID);
	propertyRS.addRecord(_T("Type"), TYPE_TRAPEZE, figureID, faceID);
	propertyRS.addRecord(_T("Height"), _height, figureID, faceID);
	propertyRS.addRecord(_T("TopEdgeLength"), _topEdge, figureID, faceID);
	propertyRS.addRecord(_T("BottomEdgeLength"), _bottomEdge, figureID, faceID);
	propertyRS.addRecord(_T("TopEdgeTranslation"), _topEdgeTranslation, figureID, faceID);
}

GraphicElements::Parallelogram::Parallelogram(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, float h, float edge, float tETr) :
	Trapeze(pos, col, rot, h, edge, edge, tETr)
{
}

GraphicElements::Rectangle::Rectangle(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, float h, float w) :
	Parallelogram(pos, col, rot, h, w, 0)
{
}

GraphicElements::Rectangle::Rectangle(float h, float w) :
	Rectangle(glm::vec3(0, 0, 0), COLOR_WHITE, glm::vec3(0, 0, 0), h, w)
{
}
