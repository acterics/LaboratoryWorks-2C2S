#pragma once
#include "Figure.h"
#include "SideFace.h"
#include "Disc.h"

namespace GraphicElements
{
	class Frustum : public Figure
	{
		float _height;
		float _topRadius;
		float _bottomRadius;
	public:
		Frustum();
		Frustum(glm::vec3 pos, glm::vec3 col, float h, float tR, float bR);
		Frustum(glm::vec3 pos, glm::vec3 col, float h, float tR, float bR, unsigned int smooth);
		~Frustum();
	};
}

