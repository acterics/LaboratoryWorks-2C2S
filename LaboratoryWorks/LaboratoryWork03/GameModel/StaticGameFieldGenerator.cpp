#include "stdafx.h"
#include "StaticGameFieldGenerator.h"


StaticGameFieldGenerator::StaticGameFieldGenerator(Matrix &matrix, int &startR, int &startC)
{
	startR = 0;
	startC = 0;
	int currentRow = 0, currentColumn = 1;
	Direction currentDirection = WEST;
	int i = 0;

	for (;i < 9;i++)
	{
		matrix[currentRow][currentColumn] = APPLE;
		directMove(matrix, currentDirection, currentRow, currentColumn);
	}


	i = 0;
	currentDirection = SOUTH;
	for (;i < 10;i++)
	{
		matrix[currentRow][currentColumn] = APPLE;
		directMove(matrix, currentDirection, currentRow, currentColumn);
	}


	i = 0;
	currentDirection = EAST;
	for (;i < 7;i++)
	{
		matrix[currentRow][currentColumn] = APPLE;
		directMove(matrix, currentDirection, currentRow, currentColumn);
	}


	i = 0;
	currentDirection = NORTH;
	for (;i < 5 ;i++)
	{
		matrix[currentRow][currentColumn] = APPLE;
		directMove(matrix, currentDirection, currentRow, currentColumn);
	}


	i = 0;
	currentDirection = EAST;
	for (;i < 11;i++)
	{
		matrix[currentRow][currentColumn] = APPLE;
		directMove(matrix, currentDirection, currentRow, currentColumn);
	}
	matrix[currentRow][currentColumn] = APPLEWAY;
	directMove(matrix, SOUTH, currentRow, currentColumn);

	i = 0;
	currentDirection = SOUTH;
	for (;i < 5;i++)
	{
		matrix[currentRow][currentColumn] = APPLE;
		directMove(matrix, currentDirection, currentRow, currentColumn);
	}
	matrix[currentRow][currentColumn] = APPLEWAY;
	
	currentDirection = EAST;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	i = 0;
	for (;i < 5;i++)
	{
		matrix[currentRow][currentColumn] = APPLE;
		directMove(matrix, currentDirection, currentRow, currentColumn);
	}
	matrix[currentRow][currentColumn] = APPLEWAY;


	i = 0;
	currentDirection = SOUTH;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	for (;i < 6;i++)
	{
		matrix[currentRow][currentColumn] = APPLE;
		directMove(matrix, currentDirection, currentRow, currentColumn);
	}
	matrix[currentRow][currentColumn] = APPLEWAY;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLEWAY;
	directMove(matrix, currentDirection, currentRow, currentColumn);

	i = 0;
	for (;i < 6;i++)
	{
		matrix[currentRow][currentColumn] = APPLE;
		directMove(matrix, currentDirection, currentRow, currentColumn);
	}
	matrix[currentRow][currentColumn] = APPLEWAY;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLEWAY;
	directMove(matrix, EAST, currentRow, currentColumn);

	currentDirection = EAST;
	i = 0;
	for (;i < 6;i++)
	{
		matrix[currentRow][currentColumn] = APPLE;
		directMove(matrix, currentDirection, currentRow, currentColumn);
	}
	matrix[currentRow][currentColumn] = APPLEWAY;
	directMove(matrix, currentDirection, currentRow, currentColumn);

	i = 0;
	for (;i < 4;i++)
	{
		matrix[currentRow][currentColumn] = APPLE;
		directMove(matrix, currentDirection, currentRow, currentColumn);
	}
	matrix[currentRow][currentColumn] = APPLEWAY;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLEWAY;
	directMove(matrix, currentDirection, currentRow, currentColumn);

	i = 0;
	currentDirection = NORTH;
	i = 0;
	for (;i < 4;i++)
	{
		matrix[currentRow][currentColumn] = APPLE;
		directMove(matrix, currentDirection, currentRow, currentColumn);
	}
	matrix[currentRow][currentColumn] = APPLEWAY;
	directMove(matrix, currentDirection, currentRow, currentColumn);

	currentDirection = WEST;
	matrix[currentRow][currentColumn] = APPLEWAY;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLE;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLEWAY;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLEWAY;

	currentDirection = NORTH;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLE;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLEWAY;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLEWAY;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLEWAY;

	currentDirection = WEST;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLE;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLEWAY;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLEWAY;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLEWAY;

	currentDirection = NORTH;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLE;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLEWAY;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLEWAY;

	currentDirection = WEST;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLE;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLEWAY;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLEWAY;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLEWAY;

	currentDirection = NORTH;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLE;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLEWAY;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLEWAY;

	currentDirection = EAST;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLE;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLEWAY;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLEWAY;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLEWAY;

	currentDirection = NORTH;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLE;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLEWAY;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLEWAY;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLEWAY;

	currentDirection = WEST;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLE;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLEWAY;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLEWAY;

	currentDirection = NORTH;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLE;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLEWAY;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLEWAY;
	directMove(matrix, currentDirection, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLEWAY;

	directMove(matrix, WEST, currentRow, currentColumn);
	matrix[currentRow][currentColumn] = APPLE;



}


StaticGameFieldGenerator::~StaticGameFieldGenerator()
{
}

void StaticGameFieldGenerator::directMove(Matrix &cells, Direction direction, int & r, int & c)
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

int StaticGameFieldGenerator::row(Matrix & m, int num)
{
	if (num < 0)
		return (num + m.size()) % m.size();
	return num % m.size();
}

int StaticGameFieldGenerator::column(Matrix & m, int num)
{
	if (num < 0)
		return (num + m[0].size()) % m[0].size();
	return num % m[0].size();
}