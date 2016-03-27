/**
 * Project LaboratoryWork03
 */
#include <vector>
#include <ctime>
#include <thread>
#include <mutex>
#include "GameField.h"
#include "State.h"
#include "Behavior.h"
#include "../LaboratoryWork03Dlg.h"

#define STATE_COUNT 7
#define GENERATION_SIZE 500
#define MUTATION_PROBABILITY 30

#ifndef _BEHAVIORGENERATOR_H
#define _BEHAVIORGENERATOR_H

class BehaviorGenerator {
public:
	BehaviorGenerator(CLaboratoryWork03Dlg * pP, GameField g, int startR, int startC);
	
	Behavior findBehavior();
private:

	std::recursive_mutex _lock;
	std::vector<std::thread> _threads;
	int _startRow, _startCol;
	CLaboratoryWork03Dlg * _pParent;

	bool _isFinded;
	Behavior _fitBehavior;
	GameField _gameField;
	std::vector<Behavior> _currentGeneration;
	unsigned int generationNumber;
	int _maxFitness;
	void generate();


	void fitness(Behavior &b);
	void initFitness();


	void mutation1(Behavior& b);
	void mutation2(Behavior& b);
	void mutation3(Behavior& b);
	void mutation4(Behavior& b);

	void crossover(Behavior & parent1, Behavior & parent2, int position);
	void crossoverAll();


	void mutate(Behavior &mutated);
	void mutateAll();

	void selection();
	void algorithmIteration();


	


};

struct compare
{
	inline bool operator() (const Behavior& b1, const Behavior& b2)
	{
		return (b1._fitness > b2._fitness);
	}
};

#endif //_BEHAVIORGENERATOR_H