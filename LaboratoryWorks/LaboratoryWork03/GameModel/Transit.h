/**
 * Project LaboratoryWork03
 */
#include "Action.h"

#ifndef _TRANSIT_H
#define _TRANSIT_H

class Transit {
public: 
	Transit();
	Transit(int arState, Action a);
	void operator=(const Transit &t);
	bool operator==(Transit t);
	Action  _action;
	int  _arrivalState;
};

#endif //_TRANSIT_H