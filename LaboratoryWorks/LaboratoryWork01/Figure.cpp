#include "stdafx.h"
#include "Figure.h"
using namespace GraphicElements;

Figure::Figure()
{
}

GraphicElements::Figure::Figure(glm::vec3 pos, glm::vec3 col) :
	GraphicElement(pos, col)
{
}


Figure::~Figure()
{
}

void GraphicElements::Figure::draw()
{
	for (auto face : _faces)
		face->draw(_position);
}

void GraphicElements::Figure::addFace(Face * face)
{
	_faces.push_back(face);
}
