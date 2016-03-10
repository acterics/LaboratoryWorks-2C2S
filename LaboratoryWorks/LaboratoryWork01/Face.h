#pragma once
#include "GraphicElement.h"
#include <vector>
namespace GraphicElements
{
	class Face : public GraphicElement
	{
	protected:
		std::vector<glm::vec3> _points;
		

		glm::mat3x3 xRotationMatrix(float angle);
		glm::mat3x3 yRotationMatrix(float angle);
		void drawPoint(glm::vec3 point, glm::vec3 figurePos);
		void drawPoint(glm::vec3 point, glm::vec3 figurePos, glm::vec3 figureRot);

	public:
		Face();
		Face(glm::vec3 pos, glm::vec3 col, glm::vec3 rot);
		Face(glm::vec3 pos, glm::vec3 col);
		Face(glm::vec3 pos);
		virtual void draw(glm::vec3 figurePos);
		virtual void draw(glm::vec3 figurePos, glm::vec3 figureRot);
		
		std::vector<glm::vec3> points();
		virtual void saveProperties(CProperties & propertyRS, long figureID, long faceID) override;
		~Face();
	};
}

