#pragma once
#include "Face.h"
#include <string>
#include <fstream>
#include <exception>
#include <sstream>

#define DEFAULT_RADIUS 1
#define DEFAULT_SMOOTH 18
namespace GraphicElements
{
	class Circle : public Face
	{
	protected:
		float _radius;
		unsigned int _smooth;

		void generate(unsigned int smooth);
		std::string getFileName(unsigned int smooth);
	public:
		Circle();
		Circle(glm::vec3 pos, glm::vec3 col, float r);
		Circle(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, float r);
		Circle(glm::vec3 pos, glm::vec3 col, float r, unsigned int smooth);
		Circle(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, float r, unsigned int smooth);
		virtual void init(unsigned int smooth);
		~Circle();
	};
}
