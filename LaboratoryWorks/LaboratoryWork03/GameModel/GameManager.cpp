/**
 * Project LaboratoryWork03
 */

#include "stdafx.h"
#include "GameManager.h"

/**
 * GameManager implementation
 */


GameManager::GameManager() :
	_gameField(32, 32)
{
	_currentStep = 0;
}

GameManager::~GameManager()
{
}

void GameManager::makeStep() {

}

void GameManager::drawGame()
{
	_gameField.drawField();
}

/**
 * @return bool
 */
bool GameManager::isEndOfGame() {
    return false;
}