#include "stdafx.h"
#include "GraphicElement.h"

using namespace GraphicElements;

GraphicElement::GraphicElement() :
	GraphicElement(glm::vec3(0, 0, 0))
{
}

GraphicElements::GraphicElement::GraphicElement(glm::vec3 pos, glm::vec3 color, glm::vec3 rot) :
	_position(pos), _color(color), _rotation(rot)
{
	_polygonMode = GL_FILL;
	_drawingMode = GL_LINE_LOOP;
}

GraphicElement::GraphicElement(glm::vec3 pos, glm::vec3 color) :
	GraphicElement(pos, color, glm::vec3(0, 0, 0))
{
	
	
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

void GraphicElements::GraphicElement::setColor(glm::vec3 color)
{
	_color = color;
}

void GraphicElements::GraphicElement::translate(glm::vec3 translation)
{
	_position += translation;
}


GraphicElement::~GraphicElement()
{
}

void GraphicElements::GraphicElement::applyColor()
{
	glColor3f(_color.x, _color.y, _color.z);
}

void GraphicElements::GraphicElement::rotate(glm::vec3 r)
{
	_rotation += r;
}
