#include "stdafx.h"
#include "FieldGenerator.h"




FieldGenerator::FieldGenerator(Matrix & matrix, int d, int applesCount, int r, int c)
{
	_startRow = r;
	_startColumn = c;
	Matrix cur = initializeApples(applesCount);
	while (dencity(cur) > d)
	{
		cur = initializeApples(applesCount);
	}
	matrix = cur;
}

FieldGenerator::~FieldGenerator()
{
}

Matrix FieldGenerator::initializeApples(int applesCount)
{
	Matrix cells;
	std::vector<Cell> row;
	row.resize(32, 0);
	cells.resize(32, row);
	
	int currentRow = _startRow;
	int currentColumn = _startColumn;
	directMove(cells, WEST, currentRow, currentColumn);
	Direction curDir = WEST;
	for (unsigned int i = 0; i < applesCount;)
	{
		if (putWayCell(cells, curDir, currentRow, currentColumn))
			i++;
		curDir = chooseTurn(cells, curDir, currentRow, currentColumn);
		directMove(cells, curDir, currentRow, currentColumn);
	}
	return cells;

}

Direction FieldGenerator::reverseDirection(Direction d)
{
	return (Direction)((int)d % 2 ? d - 1 : d + 1);
}

Direction FieldGenerator::chooseTurn(Matrix& cells, Direction d, int r, int c)
{
	std::vector<float> directionFactors;
	std::map<float, Direction> directionMap;
	int tmpRow = r, tmpColumn = c;

	directMove(cells, d, tmpRow, tmpColumn);
	directionFactors.push_back(cells[tmpRow][tmpColumn]._cellFactor * 1.01);
	directionMap[(cells[tmpRow][tmpColumn]._cellFactor) * 1.01] = d;

	tmpRow = r;
	tmpColumn = c;
	directMove(cells, leftDirection(d), tmpRow, tmpColumn);
	directionFactors.push_back(cells[tmpRow][tmpColumn]._cellFactor * 1.02);
	directionMap[cells[tmpRow][tmpColumn]._cellFactor * 1.02] = leftDirection(d);

	tmpRow = r;
	tmpColumn = c;
	directMove(cells, rightDirection(d), tmpRow, tmpColumn);
	directionFactors.push_back(cells[tmpRow][tmpColumn]._cellFactor * 1.03);
	directionMap[cells[tmpRow][tmpColumn]._cellFactor * 1.03] = rightDirection(d);

	std::sort(directionFactors.begin(), directionFactors.end());
	std::vector<Direction> resultVector;
	resultVector.push_back(directionMap[directionFactors.front()]);
	for (unsigned int i = 1; i < directionFactors.size(); i++)
	{
		if ((int)directionFactors[i - 1] == (int)directionFactors[i])
			resultVector.push_back(directionMap[directionFactors[i]]);
		else
			break;
	}
	return resultVector[rand() % resultVector.size()];

}

Direction FieldGenerator::leftDirection(Direction d)
{
	return  (Direction)(((int)d + 2) % 4);
}

Direction FieldGenerator::rightDirection(Direction d)
{
	switch (d)
	{
	case NORTH:
		return WEST;
	case SOUTH:
		return EAST;
	case EAST:
		return SOUTH;
	case WEST:
		return NORTH;
	default:
		break;
	}
}

int FieldGenerator::row(Matrix & m, int num)
{
	if (num < 0)
		return (num + m.size()) % m.size();
	return num % m.size();
}

int FieldGenerator::column(Matrix & m, int num)
{
	if (num < 0)
		return (num + m[0].size()) % m[0].size();
	return num % m[0].size();
}

bool FieldGenerator::putWayCell(Matrix& cells, Direction cur, int row, int column)
{
	cells[row][column]._cellFactor = 100;
	int tmpRow = row, tmpColumn = column;
	directMove(cells, reverseDirection(cur), tmpRow, tmpColumn);
	cells[tmpRow][tmpColumn]._cellFactor += 3;
	directMove(cells, leftDirection(cur), tmpColumn, tmpColumn);
	cells[tmpRow][tmpColumn]._cellFactor += 3;
	directMove(cells, rightDirection(cur), tmpRow, tmpColumn);
	directMove(cells, rightDirection(cur), tmpRow, tmpColumn);
	cells[tmpRow][tmpColumn]._cellFactor += 3;
	tmpRow = row;
	tmpColumn = column;
	directMove(cells, leftDirection(cur), tmpRow, tmpColumn);
	cells[tmpRow][tmpColumn]._cellFactor += 1;
	directMove(cells, rightDirection(cur), tmpRow, tmpColumn);
	directMove(cells, rightDirection(cur), tmpRow, tmpColumn);
	cells[tmpRow][tmpColumn]._cellFactor += 1;
	tmpRow = row;
	tmpColumn = column;
	directMove(cells, cur, tmpRow, tmpColumn);
	cells[tmpRow][tmpColumn]._cellFactor++;
	if (rand() % 100 > 10)
	{
		cells[row][column] = APPLE;
		return true;
	}
	else
	{
		cells[row][column] = APPLEWAY;
		return false;
	}
}

void FieldGenerator::directMove(Matrix &cells, Direction direction, int & r, int & c)
{
	switch (direction)
	{
	case NORTH:
		r = row(cells, r - 1);
		break;
	case SOUTH:
		r = row(cells, r + 1);
		break;
	case EAST:
		c = column(cells, c - 1);
		break;
	case WEST:
		c = column(cells, c + 1);
		break;
	default:
		break;
	}
}

int FieldGenerator::dencity(Matrix m)
{
	int localDencity = 0;
	int matrixDencity = 0;
	int currentRowQuart = 0;
	int currentColumnQuart = 0;
	int sectorSize = 8;
	for (; currentRowQuart < (m.size() / sectorSize); currentRowQuart++)
	{
		for (;currentColumnQuart < (m[0].size() / sectorSize); currentColumnQuart++)
		{
			for (int row = currentRowQuart * sectorSize; row < (currentRowQuart + 1) * sectorSize; row++)
			{
				for (int column = currentColumnQuart * sectorSize; column < (currentColumnQuart + 1) * sectorSize; column++)
				{
					if (m[row][column] > 0)
						localDencity++;
				}

			}
			if (localDencity > matrixDencity)
				matrixDencity = localDencity;
			localDencity = 0;
		}
		currentColumnQuart = 0;
	}
	return matrixDencity;
}

