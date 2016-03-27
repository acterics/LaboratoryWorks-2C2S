/**
 * Project LaboratoryWork03
 */

#include "Transit.h"

#ifndef _STATE_H
#define _STATE_H

class State {
public:
	State();
	State(Transit f, Transit fn);
	void operator=(const State &state);
	Transit  _foodTransit;
	Transit  _noFoodTransit;

	bool operator==(State state);
	
	/**
	 * @param food 
	 * @param action
	 */
	int transition(bool food , Action& action);
};

#endif //_STATE_H