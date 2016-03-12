#include "stdafx.h"
#include "Disc.h"

using namespace GraphicElements;



GraphicElements::Disc::Disc(glm::vec3 pos, glm::vec3 col, float r) :
	Disc(pos, col, glm::vec3(0, 0, 0), r)
{
}

GraphicElements::Disc::Disc(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, float r) :
	Disc(pos, col, rot, r, DEFAULT_SMOOTH)
{
}

GraphicElements::Disc::Disc(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, float r, unsigned int smooth) : 
	Disc(pos, col, rot, 1, r, smooth)
{
}

GraphicElements::Disc::Disc(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, float scale, float r, unsigned int smooth) :
	Circle(pos, col, rot, scale, r, smooth)
{
	_polygonMode = GL_FILL;
	_drawingMode = GL_TRIANGLES;
}

GraphicElements::Disc::Disc(Circle & circle) :
	Circle(circle)
{
	_polygonMode = GL_FILL;
	_drawingMode = GL_TRIANGLES;
	init();
}


Disc::~Disc()
{
}


void GraphicElements::Disc::init()
{
	std::vector<glm::vec3> points;
	for (unsigned int i = 1; i < _points.size(); i++)
	{
		points.push_back(_points[i - 1]);
		points.push_back(_position);
		points.push_back(_points[i]);
	}
	points.push_back(_points.back());
	points.push_back(_position);
	points.push_back(_points.front());
	_points = points;
	
}
