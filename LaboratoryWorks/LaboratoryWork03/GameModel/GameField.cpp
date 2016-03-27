/**
 * Project LaboratoryWork03
 */

#include "stdafx.h"
#include "GameField.h"
#include "BehaviorGenerator.h"



/**
 * GameField implementation
 */


 GameField::GameField(int fieldWidth, int fieldHeight) :
	 _ant(this)
 {
	 std::vector<Cell> row;
	 row.resize(fieldWidth, false);
	 _cells.resize(fieldHeight, row);
	 srand(time(0));
	 _startColumn = rand() % fieldWidth;
	 _startRow = rand() % fieldHeight;
	StaticGameFieldGenerator(_cells, _startRow, _startColumn);
	// FieldGenerator(_cells, 20, APPLES_COUNT, _startRow, _startColumn);
	_apples = appleCount();
	 _cells[_startRow][_startColumn] = PASSED;

	 _ant = Ant(this, _startRow, _startColumn);

 }

 void GameField::operator=(const GameField & g)
 {
	 std::vector<Cell> row;
	 row.resize(g._cells[0].size(), false);
	 _cells.resize(g._cells.size(), row);
	 _startRow = g._startRow;
	 _startColumn = g._startColumn;
	 _cells = g._cells;
	 _ant = g._ant;
 }

 void GameField::drawField()
{
	for (unsigned int row = 0; row < _cells.size(); row++)
	{
		for (unsigned int column = 0; column < _cells[row].size(); column++)
		{
			switch (_cells[row][column])
			{
				case EMPTY:
					glColor3f(1, 1, 1);
					break;
				case APPLE:
					glColor3f(0, 0, 0);
					break;
				case APPLEWAY:
					glColor3f(0.5, 0.5, 0.5);
					break;
				case PASSED:
					glColor3f(1, 0, 0);
					break;
				default:
				break;
			}
			glBegin(GL_QUADS);
			glVertex2f((float)(column) / (_cells[row].size() / 2) - 1, -(float)(row) / (_cells.size() / 2) + 1);
			glVertex2f((float)(column) / (_cells[row].size() / 2) - 1, -(float)(row + 1) / (_cells.size() / 2) + 1);
			glVertex2f((float)(column + 1) / (_cells[row].size() / 2) - 1, -(float)(row + 1) / (_cells.size() / 2) + 1);	
			glVertex2f((float)(column + 1) / (_cells[row].size() / 2)- 1, -(float)(row) / (_cells.size() / 2) + 1);
			glEnd();
			glColor3f(0, 0, 0);
			glBegin(GL_LINE_LOOP);
			glVertex2f((float)(column) / (_cells[row].size() / 2) - 1, -(float)(row) / (_cells.size() / 2) + 1);
			glVertex2f((float)(column) / (_cells[row].size() / 2) - 1, -(float)(row + 1) / (_cells.size() / 2) + 1);
			glVertex2f((float)(column + 1) / (_cells[row].size() / 2) - 1, -(float)(row + 1) / (_cells.size() / 2) + 1);
			glVertex2f((float)(column + 1) / (_cells[row].size() / 2) - 1, -(float)(row) / (_cells.size() / 2) + 1);
			glEnd();
		}
	}
}

 void GameField::updateField()
 {
	 int rowP, colP;
	 _ant.getPosition(rowP, colP);
	 _cells[rowP][colP] = EMPTY;
	 _ant.move();
	 _ant.getPosition(rowP, colP);
	 _cells[rowP][colP] = PASSED;
 }

 void GameField::initAnt(BehaviorGenerator & bGen)
 {
	 _ant.initBehavior(bGen);
 }



 int GameField::row(int num)
 {
	 if (num < 0)
		 return (num + _cells.size()) % _cells.size();
	 return num % _cells.size();
 }

 int GameField::column(int num)
 {
	 if (num < 0)
		 return (num + _cells[0].size()) % _cells[0].size();
	 return num % _cells[0].size();
 }

 int GameField::apples()
 {
	 return appleCount();
 }

 int GameField::appleCount()
 {
	 int apples = 0;
	 for (unsigned int i = 0; i < _cells.size(); i++)
	 {
		 for (unsigned int j = 0; j < _cells[0].size(); j++)
		 {
			 if (_cells[i][j] == APPLE)
				 apples++;
		 }
	 }
	 return apples;
 }

 void GameField::getStartPosition(int & row, int & column)
 {
	 row = _startRow;
	 column = _startColumn;
 }

 void GameField::reinit()
 {
	 std::vector<Cell> row;
	 row.resize(_cells[0].size(), false);
	 _cells.resize(_cells.size(), row);
	 srand(time(0));
	 _startColumn = rand() % _cells[0].size();
	 _startRow = rand() % _cells.size();
	 StaticGameFieldGenerator(_cells, _startRow, _startColumn);
	 //FieldGenerator(_cells, 20, APPLES_COUNT, _startRow, _startColumn);
	 _apples = appleCount();
	 _cells[_startRow][_startColumn] = PASSED;

	 _ant = Ant(this, _startRow, _startColumn);
 }



 void GameField::directMove(Direction direction, int & r, int & c)
 {
	 switch (direction)
	 {
	 case NORTH:
		 r = row(r - 1);	 
		 break;
	 case SOUTH:
		 r = row(r + 1);
		 break;
	 case EAST:
		 c = column(c - 1);
		 break;
	 case WEST:
		 c = column(c + 1);
		 break;
	 default:
		 break;
	 }
 }

 Direction GameField::leftDirection(Direction d)
 {
	 switch (d)
	 {
	 case NORTH:
		 return EAST;
	 case SOUTH:
		 return WEST;
	 case EAST:
		 return SOUTH;
	 case WEST:
		 return NORTH;
	 default:
		 break;
	 }
 }

 Direction GameField::rightDirection(Direction d)
 {
	 switch (d)
	 {
	 case NORTH:
		 return WEST;
	 case SOUTH:
		 return EAST;
	 case EAST:
		 return NORTH;
	 case WEST:
		 return SOUTH;
	 default:
		 break;
	 }
 }



 /**
 * @param row
 * @param column
 * @return bool
 */
bool GameField::isFoodCell(int row, int column) 
{
	if (_cells[row][column] == APPLE)
		return true;
	return false;
}

void GameField::deleteApple(int row, int column)
{
	_cells[row][column] = EMPTY;
	_apples--;
}

bool GameField::isApplesExist()
{
	if (_ant.eatenApples() < APPLES_COUNT)
		return true;
	return false;
}





