#include "stdafx.h"
#include "GraphicElement.h"

using namespace GraphicElements;

GraphicElement::GraphicElement() :
	GraphicElement(glm::vec3(0, 0, 0))
{
}

GraphicElement::GraphicElement(glm::vec3 pos, glm::vec3 color) :
	_position(pos), _color(color)
{
	_polygonMode = GL_FILL;
	_drawingMode = GL_QUAD_STRIP;
}

GraphicElement::GraphicElement(glm::vec3 pos) :
	GraphicElement(pos, COLOR_WHITE)
{
}

void GraphicElements::GraphicElement::setPolygonMode(UINT p)
{
	_polygonMode = p;
}

void GraphicElements::GraphicElement::setDrawingMode(UINT d)
{
	_drawingMode = d;
}


GraphicElement::~GraphicElement()
{
}

void GraphicElements::GraphicElement::applyColor()
{
	glColor3f(_color.x, _color.y, _color.z);
}
