/**
 * Project LaboratoryWork03
 */

#include "stdafx.h"
#include "Behavior.h"

/**
 * Behavior implementation
 */


Behavior::Behavior(int states)
{
	_states.resize(states);
	_currentState = _states[0];
	_fitness = -1;
}

Behavior::Behavior(const Behavior & b)
{
	_states.resize(b._states.size());
	_currentState = b._currentState;
	for (unsigned int i = 0; i < b._states.size(); i++)
		_states[i] = b._states[i];
	_fitness = b._fitness;
}

void Behavior::operator=(Behavior b)
{
	_states.resize(b._states.size());
	_currentState = b._currentState;
	for (unsigned int i = 0; i < b._states.size(); i++)
		_states[i] = b._states[i];
	_fitness = b._fitness;
}

bool Behavior::operator>(Behavior b)
{
	return _fitness > b._fitness;
}

bool Behavior::operator<(Behavior b)
{
	return _fitness < b._fitness;
}

bool Behavior::operator>=(Behavior b)
{
	return _fitness >= b._fitness;
}

bool Behavior::operator<=(Behavior b)
{
	return _fitness >= b._fitness;
}

Action Behavior::choseAction(bool isFoodInFront)
{
	Action a;
	_currentState = _states[_currentState.transition(isFoodInFront, a)];
	return a;
}