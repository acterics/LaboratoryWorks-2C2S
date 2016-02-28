#pragma once
#include "Circle.h"
namespace GraphicElements
{
	class Disc : public Circle
	{
	public:
		Disc();
		Disc(glm::vec3 pos, glm::vec3 col, float r);
		Disc(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, float r);
		Disc(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, float r, unsigned int smooth);
		~Disc();
		void draw(glm::vec3 figurePos) override;
	};
}

