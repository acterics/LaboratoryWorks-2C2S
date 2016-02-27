#include "stdafx.h"
#include "Circle.h"
using namespace GraphicElements;

Circle::Circle() :
	Circle(glm::vec3(0, 0, 0), COLOR_WHITE, DEFAULT_RADIUS)
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

GraphicElements::Circle::Circle(glm::vec3 pos, glm::vec3 col, float r, unsigned int smooth) :
	Circle(pos, col, glm::vec3(0, 0, 0), r, smooth)
{
}

GraphicElements::Circle::Circle(glm::vec3 pos, glm::vec3 col, glm::vec3 rot, float r, unsigned int smooth) :
	Face(pos, col, rot), _radius(r), _smooth(smooth)
{
	_polygonMode = GL_LINE;
	_drawingMode = GL_LINE_LOOP;
	init(smooth);
}

void GraphicElements::Circle::init(unsigned int smooth)
{
	_points.clear();
	std::ifstream fin(getFileName(smooth), std::ios::in, std::ios::binary);

	if (!fin)
	{
		fin.close();
		generate(smooth);
		init(smooth);
		return;
	}

	glm::vec2 point;
	while (!fin.eof())
	{
		fin.read(reinterpret_cast<char *>(&point), sizeof(glm::vec2));
		_points.push_back(glm::vec3(point.x * _radius, point.y * _radius, 0));
	}
	fin.close();
}


Circle::~Circle()
{
}

void GraphicElements::Circle::generate(unsigned int smooth)
{
	std::ofstream fout(getFileName(smooth), std::ios::out, std::ios::binary);
	glm::vec2 * points = new glm::vec2[smooth + 1];
	for (unsigned int i = 0; i <= smooth; i++)
	{
		points[i] = glm::vec2(sin(i * PI * 2 / (float)smooth), cos(i * PI * 2 / (float)smooth));
	}

	fout.write(reinterpret_cast<char*>(points), sizeof(glm::vec2) * smooth + 1);
	fout.close();
}

std::string GraphicElements::Circle::getFileName(unsigned int smooth)
{
	std::string fileName = "circles//circle_smooth";
	std::stringstream convertingStream;
	convertingStream << smooth;
	fileName += convertingStream.str();
	fileName += ".bin";
	return fileName;
	
}
