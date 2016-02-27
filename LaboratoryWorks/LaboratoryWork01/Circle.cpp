#include "stdafx.h"
#include "Circle.h"
using namespace GraphicElements;

Circle::Circle() :
	Face(), _radius(DEFAULT_RADIUS)
{
}

GraphicElements::Circle::Circle(glm::vec3 pos, glm::vec3 col, float r) :
	Circle(pos, col, glm::vec3(0, 0, 0), r)
{
}

GraphicElements::Circle::Circle(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, float r) :
	Circle(pos, col, rot, r, DEFAULT_SMOOTH)
{
}

GraphicElements::Circle::Circle(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, float r, unsigned int smooth) :
	Face(pos, col, rot), _radius(r)
{
	_polygonMode = GL_LINE;
	_drawingMode = GL_LINE_LOOP;
	init(smooth);
}

void GraphicElements::Circle::init(unsigned int smooth)
{
	try
	{
		_points.clear();
		//unsigned int size;
		std::string fileName = "circles//circle_smooth" + smooth;
		fileName.append(".bin");
		std::ifstream fin(fileName, std::ios::binary);
		//fin.read(reinterpret_cast<char *>(&size), sizeof(unsigned int));
		glm::vec2 point;
		while (!fin.eof())
		{
			fin.read(reinterpret_cast<char *>(&point), sizeof(glm::vec2));
			_points.push_back(glm::vec3(point.x * _radius, point.y * _radius, 0));
		}
		fin.close();
	}
	catch (float a)
	{
		generate(smooth);
		init(smooth);
	}
}


Circle::~Circle()
{
}

void GraphicElements::Circle::generate(unsigned int smooth)
{
	std::string fileName = "circles//circle_smooth" + smooth;
	fileName.append(".bin");
	std::ofstream fout(fileName, std::ios::binary);
	unsigned int size = 3 * smooth + 1;
	glm::vec2 * points = new glm::vec2[size];
	//points[0] = glm::vec2(0, 1);
	for (unsigned int i = 1; i <= smooth; i++)
	{
		points[i] = glm::vec2(sin(i * PI * 2 / (float)smooth), cos(i * PI * 2 / (float)smooth));
		//points[i * 3 - 2] = glm::vec2(0, 0);
		//points[i * 3 - 1] = points[i * 3] = glm::vec2(sin(i * PI * 2 / (float)smooth), cos(i * PI * 2 / (float)smooth));
	}

	fout.write(reinterpret_cast<char*>(points), sizeof(glm::vec2) * size);
	fout.close();
}
