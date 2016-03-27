/**
 * Project LaboratoryWork03
 */

#include "stdafx.h"
#include "Ant.h"
#include "GameField.h"
#include "BehaviorGenerator.h"

/**
 * Ant implementation
 */


Ant::Ant(GameField * field) :
	_gameField(field), _behavior(7)
{
	_eatenApples = 0;
	_direction = WEST;
}

 Ant::Ant(GameField * field, Behavior b, int startR, int startC) :
	 _gameField(field), _behavior(b), _rowPosition(startR), _columnPosition(startC), _direction(WEST)
 {
	 _eatenApples = 0;
	 _action = FRONT;
 }

 Ant::Ant(GameField * field, int startR, int startC) :
	 _gameField(field), _behavior(STATE_COUNT), _rowPosition(startR), _columnPosition(startC), _direction(WEST)
 {
	 _eatenApples = 0;
	 _action = FRONT;
	 
	 
 }

 void Ant::operator=(const Ant & a)
 {
	 _behavior = a._behavior;
	 _direction = a._direction;
	 _action = a._action;
	 _gameField = a._gameField;
	 _columnPosition = a._columnPosition;
	 _rowPosition = a._rowPosition;
	 _eatenApples = a._eatenApples;
 }

void Ant::move() 
{
	_action = _behavior.choseAction(isFoodInFront());
	if (_gameField->isFoodCell(_rowPosition, _columnPosition))
	{
		_gameField->deleteApple(_rowPosition, _columnPosition);
		_eatenApples++;
	}
	switch (_action)
	{
	case FRONT:
		_gameField->directMove(_direction, _rowPosition, _columnPosition);
		break;
	case LEFT:
		_direction = _gameField->leftDirection(_direction);
		//_gameField->directMove(_direction, _rowPosition, _columnPosition);
		break;
	case RIGHT:
		_direction = _gameField->rightDirection(_direction);
		//_gameField->directMove(_direction, _rowPosition, _columnPosition);
		break;
	case NOTHING:
		break;
	default:
		break;
	}
	
}

int Ant::eatenApples()
{
	return _eatenApples;
}

/**
 * @return bool
 */
bool Ant::isFoodInFront() 
{
	int frontRow = _rowPosition;
	int frontColumn = _columnPosition;
	_gameField->directMove(_direction, frontRow, frontColumn);
	if (_gameField->isFoodCell(frontRow, frontColumn))
		return true;
	else
		return false;
}

void Ant::initBehavior(BehaviorGenerator & bGen)
{
	_behavior = bGen.findBehavior();
	//Behavior b(7);
	//State s0(Transit(4, FRONT), Transit(2, RIGHT));
	//State s1(Transit(3, FRONT), Transit(0, FRONT));
	//State s2(Transit(6, FRONT), Transit(4, RIGHT));
	//State s3(Transit(4, FRONT), Transit(1, FRONT));
	//State s4(Transit(1, FRONT), Transit(5, RIGHT));
	//State s5(Transit(6, FRONT), Transit(1, LEFT));
	//State s6(Transit(3, FRONT), Transit(1, FRONT));
	//b._currentState = s0;
	//b._states[0] = s0;
	//b._states[1] = s1;
	//b._states[2] = s2;
	//b._states[3] = s3;
	//b._states[4] = s4;
	//b._states[5] = s5;
	//b._states[6] = s6;
	//Behavior b(5);
	//State s0(Transit(0, FRONT), Transit(1, RIGHT));
	//State s1(Transit(0, FRONT), Transit(2, RIGHT));
	//State s2(Transit(0, FRONT), Transit(3, RIGHT));
	//State s3(Transit(0, FRONT), Transit(4, RIGHT));
	//State s4(Transit(0, FRONT), Transit(0, FRONT));
	//b._currentState = s0;
	//b._states[0] = s0;
	//b._states[1] = s1;
	//b._states[2] = s2;
	//b._states[3] = s3;
	//b._states[4] = s4;
	/*_behavior = b;*/

}



 void Ant::getPosition(int & row, int & col)
 {
	 row = _rowPosition;
	 col = _columnPosition;
 }
