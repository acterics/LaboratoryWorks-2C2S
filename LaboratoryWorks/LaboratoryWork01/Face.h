#pragma once
#include "GraphicElement.h"
#include <vector>
namespace GraphicElements
{
	class Face : public GraphicElement
	{
	protected:
		std::vector<glm::vec3> _points;
		glm::vec3 _rotation;

		glm::mat3x3 xRotationMatrix();
		glm::mat3x3 yRotationMatrix();
		void drawPoint(glm::vec3 point, glm::vec3 figurePos);

	public:
		Face();
		Face(glm::vec3 pos, glm::vec3 col, glm::vec3 rot);
		Face(glm::vec3 pos, glm::vec3 col);
		Face(glm::vec3 pos);
		virtual void draw(glm::vec3 figurePos);
		void rotate(glm::vec3 r);
		std::vector<glm::vec3> points();
		~Face();
	};
}

