/**
 * Project LaboratoryWork03
 */
#include <vector>

#include "State.h"
#include "Action.h"

#ifndef _BEHAVIOR_H
#define _BEHAVIOR_H

class Behavior {
public: 
	Behavior(int states);
	Behavior(const Behavior &b);
	State  _currentState;
	std::vector<State> _states;
	void operator=(Behavior b);

	bool operator>(Behavior b);
	bool operator<(Behavior b);
	bool operator>=(Behavior b);
	bool operator<=(Behavior b);
	
	Action choseAction(bool isFoodInFront);
	int _fitness;
};

#endif //_BEHAVIOR_H