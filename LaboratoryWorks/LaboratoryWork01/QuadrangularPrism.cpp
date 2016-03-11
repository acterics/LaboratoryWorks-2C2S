#include "stdafx.h"
#include "QuadrangularPrism.h"
using namespace GraphicElements;

QuadrangularPrism::QuadrangularPrism()
{
}

GraphicElements::QuadrangularPrism::QuadrangularPrism(glm::vec3 pos, glm::vec3 col, float h, Quadrangle * face) :
	QuadrangularPrism(pos, col, glm::vec3(0, 0, 0), h, face)
{

}

GraphicElements::QuadrangularPrism::QuadrangularPrism(glm::vec3 pos, glm::vec3 col, glm::vec3 topFaceTrans, float h, Quadrangle * face) :
	Figure(pos, col), _facePointer(face), _topFaceTranslation(topFaceTrans), _height(h)
{
//	Quadrangle * top = new Quadrangle(*face);
//	top->translate(glm::vec3(topFaceTrans.x, h / 2 + topFaceTrans.y, topFaceTrans.z));
//	top->rotate(glm::vec3(-PI / 2, 0, 0));
////	top->setColor(COLOR_GREEN);
//	addFace(top);
//	Quadrangle * bot = new Quadrangle(*face);
//	bot->translate(glm::vec3(0, -h / 2, 0));
//	bot->rotate(glm::vec3(-PI / 2, 0, 0));
////	bot->setColor(COLOR_GREEN);
//	addFace(bot);
//	/*	face->translate(glm::vec3(0, -h, 0));
//	face->rotate(glm::vec3(PI / 2, 0, 0));
//	addFace(face)*/;
//	addFace(new SideFace(glm::vec3(0, 0, 0), col, glm::vec3(-PI / 2, 0, 0), topFaceTrans, h, face));


	Quadrangle * top = new Quadrangle(glm::vec3(topFaceTrans.x, h / 2 + topFaceTrans.y, topFaceTrans.z),
		col,
		glm::vec3(PI / 2, 0, 0),
		face);
	Quadrangle * bottom = new Quadrangle(glm::vec3(topFaceTrans.x, -h / 2 + topFaceTrans.y, topFaceTrans.z),
		col,
		glm::vec3(PI / 2, 0, 0),
		face);
	top->setNormal(glm::vec3(0, 0, -1));
	bottom->setNormal(glm::vec3(0, 0, -1));

	addFace(top);
	addFace(bottom);
	addFace(new Quadrangle(glm::vec3(0, 0, 0), col, glm::vec3(0, 0, 0),
		top->points()[0], bottom->points()[0],
		top->points()[2], bottom->points()[2]));
	addFace(new Quadrangle(glm::vec3(0, 0, 0), col, glm::vec3(0, 0, 0),
		top->points()[2], bottom->points()[2],
		top->points()[3], bottom->points()[3]));
	addFace(new Quadrangle(glm::vec3(0, 0, 0), col, glm::vec3(0, 0, 0),
		top->points()[3], bottom->points()[3],
		top->points()[1], bottom->points()[1]));
	addFace(new Quadrangle(glm::vec3(0, 0, 0), col, glm::vec3(0, 0, 0),
		top->points()[1], bottom->points()[1],
		top->points()[0], bottom->points()[0]));
}

void GraphicElements::QuadrangularPrism::saveProperties(CProperties & propertyRS, long figureID, long faceID)
{
	Figure::saveProperties(propertyRS, figureID);
	propertyRS.addRecord(_T("Type"), TYPE_PRISM, figureID);
	propertyRS.addRecord(_T("Height"), _height, figureID);
	propertyRS.addRecord(_T("TopFaceTranslationX"), _topFaceTranslation.x, figureID);
	propertyRS.addRecord(_T("TopFaceTranslationY"), _topFaceTranslation.y, figureID);
	propertyRS.addRecord(_T("TopFaceTranslationZ"), _topFaceTranslation.z, figureID);

	propertyRS.addRecord(_T("Ax"), _facePointer->points()[0].x, figureID);
	propertyRS.addRecord(_T("Ay"), _facePointer->points()[0].y, figureID);
	propertyRS.addRecord(_T("Az"), _facePointer->points()[0].z, figureID);

	propertyRS.addRecord(_T("Bx"), _facePointer->points()[1].x, figureID);
	propertyRS.addRecord(_T("By"), _facePointer->points()[1].y, figureID);
	propertyRS.addRecord(_T("Bz"), _facePointer->points()[1].z, figureID);

	propertyRS.addRecord(_T("Cx"), _facePointer->points()[2].x, figureID);
	propertyRS.addRecord(_T("Cy"), _facePointer->points()[2].y, figureID);
	propertyRS.addRecord(_T("Cz"), _facePointer->points()[2].z, figureID);

	propertyRS.addRecord(_T("Dx"), _facePointer->points()[3].x, figureID);
	propertyRS.addRecord(_T("Dy"), _facePointer->points()[3].y, figureID);
	propertyRS.addRecord(_T("Dz"), _facePointer->points()[3].z, figureID);

	//_facePointer->saveProperties(propertyRS, figureID, -1);
	//propertyRS.addRecord(_T("FacePointer"), (int)_facePointer, figureID);
}


QuadrangularPrism::~QuadrangularPrism()
{
}
