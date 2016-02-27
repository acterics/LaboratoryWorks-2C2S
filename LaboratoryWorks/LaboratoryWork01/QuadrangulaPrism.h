#pragma once
#include "Figure.h"
#include "Quadrangle.h"
#include "SideFace.h"

namespace GraphicElements
{

	class QuadrangulaPrism : public Figure
	{
		float _height;
	public:
		QuadrangulaPrism();
		QuadrangulaPrism(glm::vec3 pos, glm::vec3 col, float h, Quadrangle * face);
		~QuadrangulaPrism();
	};
}
