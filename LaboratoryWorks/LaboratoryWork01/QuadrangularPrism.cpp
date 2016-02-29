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
	Figure(pos, col)
{
	Quadrangle * top = new Quadrangle(*face);
	top->translate(glm::vec3(topFaceTrans.x, h / 2 + topFaceTrans.y, topFaceTrans.z));
	top->rotate(glm::vec3(-PI / 2, 0, 0));
	top->setColor(COLOR_GREEN);
	addFace(top);
	Quadrangle * bot = new Quadrangle(*face);
	bot->translate(glm::vec3(0, -h / 2, 0));
	bot->rotate(glm::vec3(-PI / 2, 0, 0));
	bot->setColor(COLOR_GREEN);
	addFace(bot);
	/*	face->translate(glm::vec3(0, -h, 0));
	face->rotate(glm::vec3(PI / 2, 0, 0));
	addFace(face)*/;
	addFace(new SideFace(glm::vec3(0, 0, 0), col, glm::vec3(-PI / 2, 0, 0), topFaceTrans, h, face));
}


QuadrangularPrism::~QuadrangularPrism()
{
}
