#include "stdafx.h"
#include "GraphicElement.h"

using namespace GraphicElements;

GraphicElement::GraphicElement() :
	GraphicElement(glm::vec3(0, 0, 0))
{
}

GraphicElements::GraphicElement::GraphicElement(glm::vec3 pos, glm::vec3 color, glm::vec3 rot, float scale) :
	_position(pos), _color(color), _rotation(rot), _scale(scale)
{
	_polygonMode = GL_FILL;
	_drawingMode = GL_LINE_LOOP;

}

GraphicElements::GraphicElement::GraphicElement(glm::vec3 pos, glm::vec3 color, glm::vec3 rot) :
	GraphicElement(pos, color, rot, 1)
{

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

void GraphicElements::GraphicElement::scale(float scaleFactor)
{
	_scale *= scaleFactor;
}


void GraphicElements::GraphicElement::saveProperties(CProperties & propertyRS, long figureID, long faceID)
{
	propertyRS.addRecord(_T("PositionX"), _position.x, figureID, faceID);
	propertyRS.addRecord(_T("PositionY"), _position.y, figureID, faceID);
	propertyRS.addRecord(_T("PositionZ"), _position.z, figureID, faceID);
	propertyRS.addRecord(_T("RotationX"), _rotation.x, figureID, faceID);
	propertyRS.addRecord(_T("RotationY"), _rotation.y, figureID, faceID);
	propertyRS.addRecord(_T("RotationZ"), _rotation.z, figureID, faceID);
	propertyRS.addRecord(_T("ColorR"), _color.x, figureID, faceID);
	propertyRS.addRecord(_T("ColorG"), _color.y, figureID, faceID);
	propertyRS.addRecord(_T("ColorB"), _color.z, figureID, faceID);
	propertyRS.addRecord(_T("Scale"), _scale, figureID, faceID);
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

glm::mat3x3 GraphicElements::GraphicElement::xRotationMatrix(float angle)
{
	return glm::mat3x3(1, 0, 0,
		0, cos(angle), sin(angle),
		0, -sin(angle), cos(angle));
}

glm::mat3x3 GraphicElements::GraphicElement::yRotationMatrix(float angle)
{
	return glm::mat3x3(cos(angle), 0, sin(angle),
		0, 1, 0,
		-sin(angle), 0, cos(angle));
}

glm::mat3x3 GraphicElements::GraphicElement::scaleMatrix(float scale)
{
	return glm::mat3x3(scale, 0, 0,
						0, scale, 0,
						0, 0,	scale);
}
