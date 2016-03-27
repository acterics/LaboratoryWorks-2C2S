#pragma once
#include <vector>
#include <ctime>
#include <algorithm>
#include <map>

#include "Cell.h"
#include "Direction.h"

typedef std::vector<std::vector<Cell> > Matrix;
class FieldGenerator
{

public:
	FieldGenerator(Matrix &matrix, int dencity, int applesCount, int r, int c);
	~FieldGenerator();


private:
	Matrix initializeApples(int applesCount);
	Direction reverseDirection(Direction d);
	Direction chooseTurn(Matrix &cells, Direction d, int r, int c);
	Direction leftDirection(Direction d);
	Direction rightDirection(Direction d);

	int row(Matrix& m, int num);
	int column(Matrix& m, int num);

	bool putWayCell(Matrix& m, Direction cur, int row, int column);
	void directMove(Matrix &cells, Direction direction, int& row, int &column);

	int dencity(Matrix m);

	int _startRow;
	int _startColumn;
};

