#pragma once
#include "Face.h"
#include "GraphicElement.h"
namespace GraphicElements
{
	class Figure : public GraphicElement
	{
	protected:
		std::vector<Face *> _faces;
	public:
		Figure();
		Figure(glm::vec3 pos, glm::vec3 col);
		Figure(glm::vec3 pos, glm::vec3 col, glm::vec3 rot);
		~Figure();
		void draw();
		void addFace(Face * face);
		std::vector<Face *> faces() { return _faces; }
		float detectCollision(CPoint p);
	};
}

