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


void GraphicElements::GraphicElement::saveProperties(CProperties & propertyRS, long figureID, long faceID)
{
	propertyRS.addRecord(_T("PositionX"), _position.x, figureID, faceID);
	propertyRS.addRecord(_T("PositionY"), _position.y, figureID, faceID);
	propertyRS.addRecord(_T("PositionZ"), _position.z, figureID, faceID);
	propertyRS.addRecord(_T("RotationX"), _rotation.x, figureID, faceID);
	propertyRS.addRecord(_T("RotationY"), _rotation.y, figureID, faceID);
	propertyRS.addRecord(_T("RotationZ"), _rotation.z, figureID, faceID);
}

void GraphicElements::GraphicElement::saveProperty(CProperties & propertyRS, CString name, float value, long figureID, long faceID)
{
	propertyRS.AddNew();
	propertyRS.m_ID = propertyRS.GetRecordCount();
	propertyRS.m_FIGURE_ID = figureID;
	if (faceID >= 0)
		propertyRS.m_FACE_ID = faceID;
	propertyRS.m_NAME = name;
	propertyRS.m_VALUE = value;
	propertyRS.Update();

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
