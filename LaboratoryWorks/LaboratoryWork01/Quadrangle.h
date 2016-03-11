#pragma once
#include "Face.h"

namespace GraphicElements
{
	class Quadrangle : public Face
	{
	public:
		Quadrangle(Quadrangle &q);
		Quadrangle(glm::vec3 col, glm::vec3 a, glm::vec3 b, glm::vec3 c, glm::vec3 d);
		Quadrangle(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, Quadrangle* face);
		Quadrangle(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, glm::vec3 a, glm::vec3 b, glm::vec3 c, glm::vec3 d);
		~Quadrangle();
		void init() override;
	};

	class Trapeze : public Quadrangle
	{
	protected:
		float _height;
		float _topEdge;
		float _bottomEdge;
		float _topEdgeTranslation;

		
	public:
		Trapeze(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, float h, float tE, float bE, float tETr);
		void saveProperties(CProperties & propertyRS, long figureID, long faceID) override;
	};

	class Parallelogram : public Trapeze
	{
	public:
		Parallelogram(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, float h, float edge, float tETr);
	};

	class Rectangle : public Parallelogram
	{
	public:
		Rectangle(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, float h, float w);
		Rectangle(float w, float h);
	};
}
