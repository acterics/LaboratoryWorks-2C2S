#include "stdafx.h"
#include "SideFace.h"
using namespace GraphicElements;

SideFace::SideFace()
{
}

GraphicElements::SideFace::SideFace(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, float h, Face * topFace, Face * bottomFace) :
	SideFace(pos, col, rot, glm::vec3(0, 0, 0), h, topFace, bottomFace)
{
}

GraphicElements::SideFace::SideFace(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, glm::vec3 topFaceTrans, float h, Face * topFace, Face * bottomFace) :
	Face(pos, col, rot), _height(h), _topFaceTranslation(topFaceTrans), _topFacePointer(topFace), _bottomFacePointer(bottomFace)
{
	_drawingMode = GL_QUAD_STRIP;
	init(topFace, bottomFace, topFaceTrans);
}

GraphicElements::SideFace::SideFace(glm::vec3 pos, glm::vec3 col, float h, Face * topFace, Face * bottomFace) :
	SideFace(pos, col, glm::vec3(0, 0, 0), h, topFace, bottomFace)
{
}

GraphicElements::SideFace::SideFace(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, glm::vec3 topFaceTrans, float h, Face * face) :
	SideFace(pos, col, rot, topFaceTrans, h, face, face)
{
}

GraphicElements::SideFace::SideFace(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, float h, Face * face) :
	SideFace(pos, col, rot, h, face, face)
{
}

GraphicElements::SideFace::SideFace(glm::vec3 pos, glm::vec3 col, float h, Face * face) :
	SideFace(pos, col, glm::vec3(0, 0, 0), h, face)
{
}

void GraphicElements::SideFace::init(Face * topFace, Face * bottomFace, glm::vec3 topFaceTrans)
{
	glm::vec3 currentPoint;
	for (unsigned int i = 0; i < topFace->points().size(); i++)
	{
		currentPoint = topFace->points()[i];
		currentPoint += topFaceTrans;
		currentPoint.z += _height / 2;
		_points.push_back(currentPoint);
		currentPoint = bottomFace->points()[i];
		currentPoint.z -= _height / 2;
		_points.push_back(currentPoint);
	}
	currentPoint = topFace->points().front();
	currentPoint += topFaceTrans;
	currentPoint.z += _height / 2;
	_points.push_back(currentPoint);
	currentPoint = bottomFace->points().front();
	currentPoint.z -= _height / 2;
	_points.push_back(currentPoint);

}

void GraphicElements::SideFace::saveProperties(CProperties & propertyRS, long figureID, long faceID)
{
	Face::saveProperties(propertyRS, figureID, faceID);
	propertyRS.addRecord(_T("Type"), TYPE_SIDE_FACE, figureID, faceID);
	propertyRS.addRecord(_T("Height"), _height, figureID, faceID);
	//propertyRS.addRecord(_T("_TopFaceTranslationX"), _topFaceTranslation.x, figureID, faceID);
	//propertyRS.addRecord(_T("_TopFaceTranslationY"), _topFaceTranslation.y, figureID, faceID);
	//propertyRS.addRecord(_T("_TopFaceTranslationZ"), _topFaceTranslation.z, figureID, faceID);
	//_topFacePointer->saveProperties(propertyRS, -1, faceID);
	//_bottomFacePointer->saveProperties(propertyRS, -1, faceID);
	
}



SideFace::~SideFace()
{
}
