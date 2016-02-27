#pragma once
#include "Face.h"
#include <string>
#include <fstream>
#include <exception>

#define DEFAULT_RADIUS 1
#define DEFAULT_SMOOTH 18
namespace GraphicElements
{
	class Circle : public Face
	{
	protected:
		float _radius;
	public:
		Circle();
		Circle(glm::vec3 pos, glm::vec3 col, float r);
		Circle(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, float r);
		Circle(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, float r, unsigned int smooth);
		void init(unsigned int smooth);
		~Circle();
	private:
		void generate(unsigned int smooth);
	};
}

