#include "stdafx.h"
#include "Disc.h"

using namespace GraphicElements;


Disc::Disc()
{
}

GraphicElements::Disc::Disc(glm::vec3 pos, glm::vec3 col, float r) :
	Disc(pos, col, glm::vec3(0, 0, 0), r)
{
}

GraphicElements::Disc::Disc(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, float r) :
	Disc(pos, col, rot, r, DEFAULT_SMOOTH)
{
}

GraphicElements::Disc::Disc(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, float r, unsigned int smooth) : 
	Circle(pos, col, rot, r, smooth)
{
	_polygonMode = GL_FILL;
	_drawingMode = GL_TRIANGLES;
}


Disc::~Disc()
{
}

void GraphicElements::Disc::draw(glm::vec3 figurePos)
{
	draw(figurePos, glm::vec3(0, 0, 0));
}

void GraphicElements::Disc::draw(glm::vec3 figurePos, glm::vec3 figureRot)
{
	glPolygonMode(GL_FRONT_AND_BACK, _polygonMode);
	applyColor();
	glBegin(_drawingMode);
	glNormal3f(_normal.x, _normal.y, _normal.z);
	for (unsigned int i = 1; i < _points.size(); i++)
	{
		drawPoint(_points[i - 1], figurePos, figureRot);
		drawPoint(glm::vec3(0, 0, 0), figurePos, figureRot);
		drawPoint(_points[i], figurePos, figureRot);
	}
	drawPoint(_points.back(), figurePos, figureRot);
	drawPoint(glm::vec3(0, 0, 0), figurePos, figureRot);
	drawPoint(_points.front(), figurePos, figureRot);
	glEnd();
}

void GraphicElements::Disc::init()
{
	Circle::init();
}
