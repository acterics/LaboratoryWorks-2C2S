/**
 * Project LaboratoryWork03
 */
#include "Behavior.h"
#include "Direction.h"


class BehaviorGenerator;
class GameField;

#ifndef _ANT_H
#define _ANT_H

class Ant {
public: 
	Ant(GameField *field);
	Ant(GameField *field, Behavior b, int startR, int startC);
	Ant(GameField *field, int startR, int startC);
	void operator=(const Ant& a);
	void move();
	int eatenApples();
	bool isFoodInFront();
	void initBehavior(BehaviorGenerator& bGen);
	void getPosition(int &row, int &col);
private: 
	Behavior  _behavior;
	Direction  _direction;
	Action _action;
	GameField*  _gameField;
	int _columnPosition;
	int  _rowPosition;
	int _eatenApples;
};

#endif //_ANT_H