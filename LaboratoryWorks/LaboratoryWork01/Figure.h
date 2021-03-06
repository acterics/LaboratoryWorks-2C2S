#pragma once
#include "Face.h"
#include "GraphicElement.h"

#define BORDER_PADDING 50
namespace GraphicElements
{
	class Figure : public GraphicElement
	{
	protected:
		std::vector<Face *> _faces;
		CRect _border;
		bool _borderVisible;
		float _maxZ;

		void initBorder();
		
	public:
		Figure();
		Figure(glm::vec3 pos, glm::vec3 col);
		Figure(glm::vec3 pos, glm::vec3 col, glm::vec3 rot);
		Figure(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, float scale);
		~Figure();

		void draw();
		void drawBorder();
		void addFace(Face * face);

		void scale(float scaleFactor);
		void setColor(glm::vec3 color);
		void setPolygonMode(UINT mode);

		float * detectCollision(glm::vec2 p);
		float * detectCollision(CPoint p);
		CRect border() { return _border; }


		std::vector<Face *> faces() { return _faces; }

		void rotateBorder(glm::vec2);
		void borderVisibleOn() { _borderVisible = true; }
		void borderVisibleOff() { _borderVisible = false; }
		void changeBorderVisible();
	};
}

