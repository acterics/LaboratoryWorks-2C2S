#pragma once


#include <vector>

#include "Cell.h"
#include "Direction.h"

typedef std::vector<std::vector<Cell> > Matrix;
class StaticGameFieldGenerator
{
public:
	StaticGameFieldGenerator(Matrix &matrix, int &startR, int &startC);
	~StaticGameFieldGenerator();
	void directMove(Matrix & cells, Direction direction, int & r, int & c);
	int row(Matrix & m, int num);
	int column(Matrix & m, int num);
};

