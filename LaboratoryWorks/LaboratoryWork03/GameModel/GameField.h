/**
 * Project LaboratoryWork03
 */

#include <gl\GL.h>
#include <gl\GLU.h>
#include "FieldGenerator.h"
#include "StaticGameFieldGenerator.h"
#include "Ant.h"

class BehaviorGenerator;

#define APPLES_COUNT 89

#ifndef _GAMEFIELD_H
#define _GAMEFIELD_H

class GameField {
public: 
	GameField(int fieldWidth, int fieldHeight);
	
	void operator=(const GameField & g);
	void drawField();
	void updateField();
	void initAnt(BehaviorGenerator &bGen);

	int row(int num);
	int column(int num);
	int apples();
	
	void getStartPosition(int &row, int &column);
	void reinit();
	/**
	 * @param row
	 * @param column
	 */
	void directMove(Direction direction, int& row, int &column);
	Direction leftDirection(Direction d);
	Direction rightDirection(Direction d);

	bool isFoodCell(int row, int column);
	void deleteApple(int row, int column);
	bool isApplesExist();
private: 
	Ant _ant;
	int _startRow;
	int _startColumn;
	int _apples;
	std::vector<std::vector<Cell> > _cells;

	int appleCount();
};

#endif //_GAMEFIELD_H