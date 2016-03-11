#include "stdafx.h"
#include "Frustum.h"
using namespace GraphicElements;

Frustum::Frustum()
{
}

GraphicElements::Frustum::Frustum(glm::vec3 pos, glm::vec3 col, float h, float tR, float bR) :
	Frustum(pos, col, h, tR, bR, DEFAULT_SMOOTH)
{

}

GraphicElements::Frustum::Frustum(glm::vec3 pos, glm::vec3 col, float h, float tR, float bR, unsigned int smooth) :
	Frustum(pos, col, glm::vec3(0, 0, 0), h, tR, bR, smooth)
{

}

GraphicElements::Frustum::Frustum(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, float h, float tR, float bR, unsigned int smooth) :
	Figure(pos, col, rot), _height(h), _topRadius(tR), _bottomRadius(bR), _smooth(smooth)
{
	addFace(new Disc(glm::vec3(0, h / 2, 0), col, glm::vec3(PI / 2, 0, 0), tR, smooth));
	
	addFace(new Disc(glm::vec3(0, -h / 2, 0), col, glm::vec3(PI / 2, 0, 0), bR, smooth));
	for (unsigned int i = 0; i < _faces[0]->points().size() - 1; i++)
	{
		addFace(new Quadrangle(glm::vec3(0, 0, 0), col, glm::vec3(0, 0, 0),
			_faces[0]->points()[i], _faces[0]->points()[i + 1],
			_faces[1]->points()[i + 1], _faces[1]->points()[i]));
	}
	addFace(new Quadrangle(glm::vec3(0, 0, 0), col, glm::vec3(0, 0, 0),
		_faces[0]->points().back(), _faces[0]->points().front(),
		_faces[1]->points().front(), _faces[1]->points().back()));

}

void GraphicElements::Frustum::saveProperties(CProperties & propertyRS, long figureID, long faceID)
{
	GraphicElement::saveProperties(propertyRS, figureID);
	propertyRS.addRecord(_T("Type"), TYPE_FRUSTUM, figureID);
	propertyRS.addRecord(_T("Smooth"), _smooth, figureID);
	propertyRS.addRecord(_T("Height"), _height, figureID);
	propertyRS.addRecord(_T("TopRadius"), _topRadius, figureID);
	propertyRS.addRecord(_T("BottomRadius"), _bottomRadius, figureID);

}


Frustum::~Frustum()
{
}
