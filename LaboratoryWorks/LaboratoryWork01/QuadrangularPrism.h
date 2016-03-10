#pragma once
#include "Figure.h"
#include "Quadrangle.h"
#include "SideFace.h"

namespace GraphicElements
{

	class QuadrangularPrism : public Figure
	{
		float _height;
		Quadrangle * _facePointer;
		glm::vec3 _topFaceTranslation;
	public:
		QuadrangularPrism();
		QuadrangularPrism(glm::vec3 pos, glm::vec3 col, float h, Quadrangle * face);
		QuadrangularPrism(glm::vec3 pos, glm::vec3 col, glm::vec3 topFaceTrans, float h, Quadrangle * face);
		void saveProperties(CProperties & propertyRS, long figureID, long faceID) override;
		~QuadrangularPrism();
	};
}
