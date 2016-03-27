/**
 * Project LaboratoryWork03
 */

#include "stdafx.h"
#include "Transit.h"

/**
 * Transit implementation
 */

	 Transit::Transit()
 {
	 _action = NOTHING;
	 _arrivalState = 0;
 }

	 Transit::Transit(int arState, Action a)
	 {
		 _arrivalState = arState;
		 _action = a;
	 }

	 void Transit::operator=(const Transit & t) 
	 {
		 _arrivalState = t._arrivalState;
		 _action = t._action;
	 }

	 bool Transit::operator==(Transit t)
	 {
		 if (_action == t._action && _arrivalState == t._arrivalState)
			 return true;
		 return false;
	 }
