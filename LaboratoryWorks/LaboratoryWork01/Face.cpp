#include "stdafx.h"
#include "Face.h"
using namespace GraphicElements;

glm::mat3x3 GraphicElements::Face::xRotationMatrix(float angle)
{
	return glm::mat3x3(1, 0, 0,
		0, cos(angle), sin(angle),
		0, -sin(angle), cos(angle));
}

glm::mat3x3 GraphicElements::Face::yRotationMatrix(float angle)
{
	return glm::mat3x3(cos(angle), 0, sin(angle),
		0, 1, 0,
		-sin(angle), 0, cos(angle));
}

void GraphicElements::Face::drawPoint(glm::vec3 point, glm::vec3 figurePos)
{
	drawPoint(point, figurePos, glm::vec3(0, 0, 0));
}

void GraphicElements::Face::drawPoint(glm::vec3 point, glm::vec3 figurePos, glm::vec3 figureRot)
{
	point = xRotationMatrix(_rotation.x) * yRotationMatrix(_rotation.y) * point;
	point += _position;
	
	point = xRotationMatrix(figureRot.x) * yRotationMatrix(figureRot.y) * point;
	point += figurePos;

	glVertex3f(point.x,
		point.y,
		point.z);

}



Face::Face() :
	GraphicElement()
{
}

GraphicElements::Face::Face(glm::vec3 pos, glm::vec3 col) :
	Face(pos, col, glm::vec3(0, 0, 0))
{
}

GraphicElements::Face::Face(glm::vec3 pos, glm::vec3 col, glm::vec3 rot) :
	GraphicElement(pos, col, rot)
{
}

GraphicElements::Face::Face(glm::vec3 pos) :
	Face(pos, COLOR_WHITE)
{
}


void Face::draw(glm::vec3 figurePos)
{
	draw(figurePos, glm::vec3(0, 0, 0));
}

void GraphicElements::Face::draw(glm::vec3 figurePos, glm::vec3 figureRot)
{
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glPolygonMode(GL_FRONT_AND_BACK, _polygonMode);
	applyColor();
	glBegin(_drawingMode);
	for (auto point : _points)
		drawPoint(point, figurePos, figureRot);
	glEnd();
}

std::vector<glm::vec3> GraphicElements::Face::points()
{
	return _points;
}

void GraphicElements::Face::saveProperties(CProperties & propertyRS, long figureID, long faceID)
{
	GraphicElement::saveProperties(propertyRS, figureID, faceID);
	saveProperty(propertyRS, _T("ColorR"),_color.x, figureID, faceID);
	saveProperty(propertyRS, _T("ColorG"), _color.y, figureID, faceID);
	saveProperty(propertyRS, _T("ColorB"), _color.z, figureID, faceID);
}


Face::~Face()
{
}
