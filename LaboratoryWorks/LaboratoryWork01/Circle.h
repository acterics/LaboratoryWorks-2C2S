#pragma once
#include "Face.h"
#include <string>
#include <fstream>
#include <exception>
#include <sstream>

#define DEFAULT_RADIUS 1
#define DEFAULT_SMOOTH 36
namespace GraphicElements
{
	class Circle : public Face
	{
	protected:
		float _radius;
		unsigned int _smooth;

	public:
		Circle(glm::vec3 pos, glm::vec3 col, float r);
		Circle(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, float r);
		Circle(glm::vec3 pos, glm::vec3 col, float r, unsigned int smooth);
		Circle(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, float r, unsigned int smooth);
		Circle(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, float scale, float r, unsigned int smooth);

		virtual void saveProperties(CProperties &propertyRS, long figureID, long faceID) override;
		void init() override;
		~Circle();
	private:
		void generate(unsigned int smooth);
		std::string getFileName(unsigned int smooth);
	};
}

