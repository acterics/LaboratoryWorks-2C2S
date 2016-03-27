/**
 * Project LaboratoryWork03
 */

#include "stdafx.h"
#include "State.h"

/**
 * State implementation
 */


/**
 * @param food 
 * @param action
 * @return int
 */
State::State()
{
}

State::State(Transit f, Transit fn)
{
	_foodTransit = f;
	_noFoodTransit = fn;
}

void State::operator=(const State & state)
{
	_foodTransit = state._foodTransit;
	_noFoodTransit = state._noFoodTransit;
}

bool State::operator==(State state)
{
	if (_foodTransit == state._foodTransit && _noFoodTransit == state._noFoodTransit)
		return true;
	return false;
}

 int State::transition(bool food , Action& action)
{
	if (food)
	{
		action = _foodTransit._action;
		return _foodTransit._arrivalState;
	}
	else
	{
		action = _noFoodTransit._action;
		return _noFoodTransit._arrivalState;
	}

}