#pragma once
#include "GraphicElement.h"
#include <vector>
namespace GraphicElements
{
	class Face : public GraphicElement
	{
	protected:
		std::vector<glm::vec3> _points;
		CRect _border;
		float _maxX;
		float _maxY;
		float _minX;
		float _minY;
		float _maxZ;


		void drawPoint(glm::vec3 point, glm::vec3 figurePos);
		void drawPoint(glm::vec3 point, glm::vec3 figurePos, glm::vec3 figureRot);
		

	public:
		Face();
		Face(glm::vec3 pos, glm::vec3 col, glm::vec3 rot);
		Face(glm::vec3 pos, glm::vec3 col);
		Face(glm::vec3 pos);
		virtual void draw(glm::vec3 figurePos);
		virtual void draw(glm::vec3 figurePos, glm::vec3 figureRot);

		float maxZ() { return _maxZ; }
		
		std::vector<glm::vec3> points();
		CRect faceRect();
		virtual void saveProperties(CProperties & propertyRS, long figureID, long faceID) override;
		~Face();
	};
}

