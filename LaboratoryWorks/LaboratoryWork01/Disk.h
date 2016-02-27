#pragma once
#include "Circle.h"

namespace GraphicElements
{
	class Disk : public Circle
	{
	public:
		Disk();
		Disk(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, float r, unsigned int smooth);
		~Disk();
		void init(unsigned int smooth) override;
	};
}

