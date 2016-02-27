#include "stdafx.h"
#include "QuadrangulaPrism.h"
using namespace GraphicElements;

QuadrangulaPrism::QuadrangulaPrism()
{
}

GraphicElements::QuadrangulaPrism::QuadrangulaPrism(glm::vec3 pos, glm::vec3 col, float h, Quadrangle * face) :
	Figure(pos, col), _height(h)
{
	//face->setColor(COLOR_GREEN);
	Quadrangle * top = new Quadrangle(*face);
	top->translate(glm::vec3(0, h / 2, 0));
	top->rotate(glm::vec3(PI / 2, 0, 0));
	top->setColor(COLOR_GREEN);
	addFace(top);
	Quadrangle * bot = new Quadrangle(*face);
	bot->translate(glm::vec3(0, -h / 2, 0));
	bot->rotate(glm::vec3(PI / 2, 0, 0));
	bot->setColor(COLOR_GREEN);
	addFace(bot);
/*	face->translate(glm::vec3(0, -h, 0));
	face->rotate(glm::vec3(PI / 2, 0, 0));
	addFace(face)*/;
	addFace(new SideFace(glm::vec3(0, 0, 0), col, glm::vec3(PI / 2, 0, 0), h, face));
}


QuadrangulaPrism::~QuadrangulaPrism()
{
}
