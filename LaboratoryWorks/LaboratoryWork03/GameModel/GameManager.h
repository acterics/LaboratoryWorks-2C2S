/**
 * Project LaboratoryWork03
 */

#include "GameField.h"



#ifndef _GAMEMANAGER_H
#define _GAMEMANAGER_H

class GameManager {
public: 
	GameManager();
	~GameManager();
	
	void makeStep();
	void drawGame();
	bool isEndOfGame();
private: 
	GameField  _gameField;
	int  _currentStep;
};

#endif //_GAMEMANAGER_H