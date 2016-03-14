#pragma once
#include "glm\glm.hpp"
#include "CProperties.h"
#include <gl/gl.h>
#include <gl/glu.h>


#define COLOR_WHITE glm::vec3(1.0f, 1.0f, 1.0f)
#define COLOR_BLACK glm::vec3(0.0f, 0.0f, 0.0f)
#define COLOR_RED	glm::vec3(1.0f, 0.0f, 0.0f)
#define COLOR_GREEN glm::vec3(0.0f, 1.0f, 0.0f)
#define COLOR_BLUE	glm::vec3(0.0f, 0.0f, 1.0f)

#define TYPE_FRUSTUM	1
#define TYPE_SIDE_FACE	5
#define TYPE_DISC		3
#define TYPE_TRAPEZE	4
#define TYPE_PRISM		2
#define PI 3.14159265359

#define ACCURACY 100

namespace GraphicElements
{


	class GraphicElement
	{
	protected:
		glm::vec3 _position;
		glm::vec3 _color;
		glm::vec3 _rotation;
		float _scale;
		UINT _polygonMode;
		UINT _drawingMode;
		

		void applyColor();

	public:
		GraphicElement();
		GraphicElement(glm::vec3 pos, glm::vec3 color, glm::vec3 rot, float scale);
		GraphicElement(glm::vec3 pos, glm::vec3 color, glm::vec3 rot);
		GraphicElement(glm::vec3 pos, glm::vec3 color);
		GraphicElement(glm::vec3 pos);


		glm::vec3 color();


		void setPolygonMode(UINT p);
		void setDrawingMode(UINT d);
		void setColor(glm::vec3 color);
		void translate(glm::vec3 translation);
		void scale(float scaleFactor);
		void rotate(glm::vec3 r);

		glm::mat3x3 xRotationMatrix(float angle);
		glm::mat3x3 yRotationMatrix(float angle);
		glm::mat3x3 scaleMatrix(float scale);

		virtual void saveProperties(CProperties &propertyRS, long figureID, long faceID = -1);
		virtual void saveProperty(CProperties &propertyRS, CString name, float value, long figureID, long faceID = -1);
		~GraphicElement();

	};
}

