#include "stdafx.h"
#include "Face.h"
using namespace GraphicElements;

glm::mat3x3 GraphicElements::Face::xRotationMatrix()
{
	return glm::mat3x3(1, 0, 0,
		0, cos(_rotation.x), sin(_rotation.x),
		0, -sin(_rotation.x), cos(_rotation.x));
}

glm::mat3x3 GraphicElements::Face::yRotationMatrix()
{
	return glm::mat3x3(cos(_rotation.y), 0, sin(_rotation.y),
		0, 1, 0,
		-sin(_rotation.y), 0, cos(_rotation.y));
}

void GraphicElements::Face::drawPoint(glm::vec3 point, glm::vec3 figurePos)
{
	glm::vec3 drawingPosition = xRotationMatrix() * yRotationMatrix() * point;
	glVertex3f(drawingPosition.x + _position.x + figurePos.x,
		drawingPosition.y + _position.y + figurePos.y,
		drawingPosition.z + _position.z + figurePos.z);
}



Face::Face() :
	GraphicElement(), _rotation(glm::vec3(0, 0, 0))
{
}

GraphicElements::Face::Face(glm::vec3 pos, glm::vec3 col) :
	Face(pos, col, glm::vec3(0, 0, 0))
{
}

GraphicElements::Face::Face(glm::vec3 pos, glm::vec3 col, glm::vec3 rot) :
	GraphicElement(pos, col), _rotation(rot)
{
}

GraphicElements::Face::Face(glm::vec3 pos) :
	Face(pos, COLOR_WHITE)
{
}


void Face::draw(glm::vec3 figurePos)
{
	glPolygonMode(GL_FRONT_AND_BACK, _polygonMode);
	applyColor();
	glBegin(_drawingMode);
	for (auto point : _points)
		drawPoint(point, figurePos);
	glEnd();
	
}

void GraphicElements::Face::rotate(glm::vec3 r)
{
	_rotation += r;
}

std::vector<glm::vec3> GraphicElements::Face::points()
{
	return _points;
}


Face::~Face()
{
}
