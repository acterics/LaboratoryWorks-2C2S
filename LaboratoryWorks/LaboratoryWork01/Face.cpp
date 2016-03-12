#include "stdafx.h"
#include "Face.h"
using namespace GraphicElements;


void Face::init()
{
	_normal = xRotationMatrix(_rotation.x) * yRotationMatrix(_rotation.y) * _normal;
	for (glm::vec3& point : _points)
	{

		point = xRotationMatrix(_rotation.x) * yRotationMatrix(_rotation.y) * point;
		point += _position;
	}
}

void GraphicElements::Face::drawPoint(glm::vec3 point, glm::vec3 figurePos)
{
	drawPoint(point, figurePos, glm::vec3(0, 0, 0));
}

void GraphicElements::Face::drawPoint(glm::vec3 point, glm::vec3 figurePos, glm::vec3 figureRot)
{
	drawPoint(point, figurePos, figureRot, -1);

}

void GraphicElements::Face::drawPoint(glm::vec3 point, glm::vec3 figurePos, glm::vec3 figureRot, int pointIndex)
{
	
	point = xRotationMatrix(figureRot.x) * yRotationMatrix(figureRot.y)  * point;
	point *= _scale;
	point += figurePos;


	if (point.x > _maxX)
		_maxX = point.x;
	if (point.x < _minX)
		_minX = point.x;
	if (point.y > _maxY)
		_maxY = point.y;
	if (point.y < _minY)
		_minY = point.y;
	if (point.z > _maxZ)
		_maxZ = point.z;

		

	glVertex3f(point.x,
		point.y,
		point.z);
}





Face::Face() :
	GraphicElement()
{
}

GraphicElements::Face::Face(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, float scale) :
	GraphicElement(pos, col, rot, scale)
{
}

GraphicElements::Face::Face(glm::vec3 pos, glm::vec3 col) :
	Face(pos, col, glm::vec3(0, 0, 0))
{
}

GraphicElements::Face::Face(glm::vec3 pos, glm::vec3 col, glm::vec3 rot) :
	Face(pos, col, rot, 1)
{

	
	//for (auto point = _points.begin(); point != _points.end(); point++)

	
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
	_maxX = INT16_MIN;
	_maxY = INT16_MIN;
	_minX = INT16_MAX;
	_minY = INT16_MAX;
	_maxZ = INT16_MIN;
	
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glPolygonMode(GL_FRONT_AND_BACK, _polygonMode);
	glBegin(_drawingMode);
	
	glm::vec3 curNormal = xRotationMatrix(figureRot.x) * yRotationMatrix(figureRot.y) * _normal;

	glNormal3f(curNormal.x, curNormal.y, curNormal.z);
	applyColor();
	for (unsigned int i = 0; i < _points.size(); i++)
		drawPoint(_points[i], figurePos, figureRot, i);
	glEnd();
	//_maxZ *= ACCURACY;
	_border.SetRect(CPoint(_maxX * ACCURACY, _maxY * ACCURACY), CPoint(_minX * ACCURACY, _minY * ACCURACY));
}



std::vector<glm::vec3> GraphicElements::Face::points()
{
	return _points;
}

CRect GraphicElements::Face::faceRect()
{
	return _border;
}

void GraphicElements::Face::setNormal(glm::vec3 normal)
{
	_normal = xRotationMatrix(_rotation.x) * yRotationMatrix(_rotation.y) * normal;
}




Face::~Face()
{
}
