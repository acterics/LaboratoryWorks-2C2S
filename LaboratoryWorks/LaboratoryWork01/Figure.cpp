#include "stdafx.h"
#include "Figure.h"
using namespace GraphicElements;

Figure::Figure()
{
}

GraphicElements::Figure::Figure(glm::vec3 pos, glm::vec3 col) :
	GraphicElement(pos, col, glm::vec3(0, 0, 0))
{
}

GraphicElements::Figure::Figure(glm::vec3 pos, glm::vec3 col, glm::vec3 rot) :
	GraphicElement(pos, col, rot)
{
}


Figure::~Figure()
{
}

void GraphicElements::Figure::draw()
{
	for (auto face : _faces)
		face->draw(_position, _rotation);
}

void GraphicElements::Figure::addFace(Face * face)
{
	_faces.push_back(face);
}

float GraphicElements::Figure::detectCollision(CPoint p)
{
	return 0.0f;
}
