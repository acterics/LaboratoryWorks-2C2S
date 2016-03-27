/**
 * Project LaboratoryWork03
 */

#include "stdafx.h"
#include "BehaviorGenerator.h"
#include "Ant.h"

/**
 * BehaviorGenerator implementation
 */





BehaviorGenerator::BehaviorGenerator(CLaboratoryWork03Dlg * pP, GameField g, int startR, int startC) :
	_pParent(pP), _gameField(g), _fitBehavior(STATE_COUNT), _isFinded(false), _startRow(startR), _startCol(startC)
 {
	 srand(time(0));
	 generationNumber = 0;
	 _currentGeneration.reserve(GENERATION_SIZE * 2);
 }



Behavior BehaviorGenerator::findBehavior()
{
	generate();
	while (!_isFinded)
	{
		algorithmIteration();
		_pParent->progressStep();
	}
	return _fitBehavior;

}

void BehaviorGenerator::generate()
{
	
	for (int i = 0; i < 2 * GENERATION_SIZE; i++)
	{
		Behavior item = Behavior(STATE_COUNT);
		for (int state = 0; state < item._states.size(); state++)
		{
			Transit f(rand() % STATE_COUNT, (Action)(rand() % 3));
			Transit fn(rand() % STATE_COUNT, (Action)(rand() % 3));
			item._states[state] = State(f, fn);
		}
		item._currentState = item._states.front();
		_currentGeneration.push_back(item);// = item;
	}
	
}

void BehaviorGenerator::fitness(Behavior& b)
{
	_lock.lock();
	GameField g = _gameField;
	b._currentState = b._states.front();
	Ant ant(&g, b, _startRow, _startCol);
	_lock.unlock();
	int steps = 0;
	for (;steps < 200; steps++)
	{
		if (ant.eatenApples() == 89)
			break;
		ant.move();
	}
	b._fitness = ant.eatenApples() + (200 - steps);
}

void BehaviorGenerator::initFitness()
{
	for (int i = 0; i < _currentGeneration.size(); i++)
	{
		if (_currentGeneration[i]._fitness < 0)
		{
			_currentGeneration[i];
			_threads.push_back(std::thread([=] {fitness(_currentGeneration[i]);}));
		}
	}
	for (unsigned int i = 0; i < _threads.size(); i++)
	{
		_threads[i].join();
	}
	_threads.clear();
}



void BehaviorGenerator::mutation1(Behavior & b)
{
	int randomState = rand() % b._states.size();
	while (b._currentState == b._states[randomState])
	{
		randomState = rand() % b._states.size();
	}
	b._currentState = b._states[randomState];
}

void BehaviorGenerator::mutation2(Behavior & b)
{
	int randomState = rand() % b._states.size();
	bool randomTranslaation = rand() % 2;
	Action randomAction = (Action)(rand() % 3);
	if (randomTranslaation)
		b._states[randomState]._foodTransit._action = randomAction;
	else
		b._states[randomState]._noFoodTransit._action = randomAction;
}

void BehaviorGenerator::mutation3(Behavior & b)
{
	int randomState = rand() % b._states.size();
	bool randomTranslaation = rand() % 2;
	int randomArrState = rand() % b._states.size();
	if (randomTranslaation)
		b._states[randomState]._foodTransit._arrivalState = randomArrState;
	else
		b._states[randomState]._noFoodTransit._arrivalState = randomArrState;
}

void BehaviorGenerator::mutation4(Behavior & b)
{
	int randomState = rand() % b._states.size();
	Transit temp = b._states[randomState]._foodTransit;
	b._states[randomState]._foodTransit = b._states[randomState]._noFoodTransit;
	b._states[randomState]._noFoodTransit = temp;
}

void BehaviorGenerator::crossover(Behavior & parent1, Behavior & parent2, int position)
{
	Behavior child1(STATE_COUNT);
	Behavior child2(STATE_COUNT);
	int randomTransit;
	bool randomParent;
	State childState1, childState2;
	std::vector<Transit> pool;
	for (unsigned int i = 0; i < STATE_COUNT; i++)
	{
		pool.clear();
		pool.push_back(parent1._states[i]._foodTransit);
		pool.push_back(parent1._states[i]._noFoodTransit);
		pool.push_back(parent2._states[i]._foodTransit);
		pool.push_back(parent2._states[i]._noFoodTransit);

		randomTransit = rand() % pool.size();
		childState1._foodTransit = pool[randomTransit];
		pool.erase(pool.begin() + randomTransit);

		randomTransit = rand() % pool.size();
		childState1._noFoodTransit = pool[randomTransit];
		pool.erase(pool.begin() + randomTransit);

		randomTransit = rand() % pool.size();
		childState2._foodTransit = pool[randomTransit];
		pool.erase(pool.begin() + randomTransit);

		randomTransit = rand() % pool.size();
		childState2._noFoodTransit = pool[randomTransit];

		child1._states[i] = childState1;
		child2._states[i] = childState2;
	}
	
	child1._currentState = child1._states.front();
	child2._currentState = child2._states.front();

	_lock.lock();
	(_currentGeneration[position]) = child1;
	(_currentGeneration[position + 1]) = child2;
	_lock.unlock();
}

void BehaviorGenerator::crossoverAll()
{
	std::vector<int> parents;
	parents.reserve(_currentGeneration.size() / 2);
	unsigned int i = 0;
	for (; i < _currentGeneration.size() / 2; i++)
		parents.push_back(i);
	while (!parents.empty())
	{
		int parent1 = rand() % parents.size();
		parents.erase(parents.begin() + parent1);
		if (parents.empty())
			break;
		int parent2 = rand() % parents.size();
		parents.erase(parents.begin() + parent2);
		/*_threads.push_back(std::thread([=] {*/crossover(_currentGeneration[parent1], _currentGeneration[parent2], i);
		i += 2;//}));
	}
	//for (int i = 0; i < _threads.size(); i++)
	//{
	//	_threads[i].join();
	//}
	//_threads.clear();
}

void BehaviorGenerator::mutate(Behavior & mutated)
{
	mutated._fitness = -1;
	int mutation = rand() % 4;
	switch (mutation)
	{
	case 0:
		mutation1(mutated);
		break;
	case 1:
		mutation2(mutated);
		break;
	case 2:
		mutation3(mutated);
		break;
	case 3:
		mutation4(mutated);
		break;
	default:
		break;
	}
}

void BehaviorGenerator::mutateAll()
{
	for (unsigned int i = 0; i < _currentGeneration.size(); i++)
	{
		if (rand() % 100 < MUTATION_PROBABILITY)
		{
			mutate(_currentGeneration[i]);
		}
	}
//	for (unsigned int i = 0; i < _threads.size(); i++)
//	{
//		_threads[i].join();
//	}
//	_threads.clear();
}


void BehaviorGenerator::selection()
{
	initFitness();
	std::sort(_currentGeneration.begin(), _currentGeneration.end(), compare());
	if (_currentGeneration.front()._fitness >= APPLES_COUNT || generationNumber == MAX_GENERATION)
	{
		_fitBehavior = _currentGeneration.front();
		_isFinded = true;
		return;
	}

	//int size = _currentGeneration.size() / 2;
	//for (int i = 0; i < size; i++)
	//	_currentGeneration.pop_back();

	_maxFitness = _currentGeneration.front()._fitness;
	
}

void BehaviorGenerator::algorithmIteration()
{
	crossoverAll();


	selection();
	if (_isFinded)
		return;


	
	mutateAll();

	//Behavior mutated(STATE_COUNT);

	generationNumber++;
}
