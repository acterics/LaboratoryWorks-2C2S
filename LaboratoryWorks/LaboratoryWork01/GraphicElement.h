#pragma once
#include "glm\glm.hpp"
#include <gl/gl.h>
#include <gl/glu.h>


#define COLOR_WHITE glm::vec3(1.0f, 1.0f, 1.0f)
#define COLOR_BLACK glm::vec3(0.0f, 0.0f, 0.0f)
#define COLOR_RED	glm::vec3(1.0f, 0.0f, 0.0f)
#define COLOR_GREEN glm::vec3(0.0f, 1.0f, 0.0f)
#define COLOR_BLUE	glm::vec3(0.0f, 0.0f, 1.0f)

#define PI 3.14159265359

namespace GraphicElements
{


	class GraphicElement
	{
	protected:
		glm::vec3 _position;
		glm::vec3 _color;
		UINT _polygonMode;
		UINT _drawingMode;

		void applyColor();

	public:
		GraphicElement();
		GraphicElement(glm::vec3 pos, glm::vec3 color);
		GraphicElement(glm::vec3 pos);

		void setPolygonMode(UINT p);
		void setDrawingMode(UINT d);
		void setColor(glm::vec3 color);
		void translate(glm::vec3 translation);
		~GraphicElement();

	};
}

