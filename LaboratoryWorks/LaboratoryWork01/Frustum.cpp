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
	Figure(pos, col), _height(h), _topRadius(tR), _bottomRadius(bR)
{
	addFace(new Disc(glm::vec3(0, h / 2, 0), COLOR_GREEN, glm::vec3(PI / 2, 0, 0), tR, smooth));
	addFace(new Disc(glm::vec3(0, -h / 2, 0), COLOR_BLUE, glm::vec3(PI / 2, 0, 0), bR, smooth));
	addFace(new SideFace(glm::vec3(0, 0, 0), col, glm::vec3(-PI / 2, 0, 0), h, _faces.front(), _faces.back()));
}


Frustum::~Frustum()
{
}
