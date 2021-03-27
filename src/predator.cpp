// Copyright 2021 Smirnov Grigory
#include "../include/prey.h"
#include "../include/predator.h"
#include "../include/cell.h"
#include "../include/ocean.h"
#include <vector>
#include <random>

Predator::Predator(Cell* c) : Prey(c) {
	type = PREDATOR_N;
}

Cell* Predator::devour() {
	std::vector<Cell*> ways;
	if (cell->getTop()->getObject()!=nullptr)
	  if (cell->getTop()->getObject()->getType() == PREY_N)
		  ways.push_back(cell->getTop());
	if (cell->getTop()->getObject() != nullptr)
	  if (cell->getBot()->getObject()->getType() == PREY_N)
		  ways.push_back(cell->getBot());
	if (cell->getTop()->getObject() != nullptr)
	  if (cell->getLeft()->getObject()->getType() == PREY_N)
		  ways.push_back(cell->getLeft());
	if (cell->getTop()->getObject() != nullptr)
	  if (cell->getRight()->getObject()->getType() == PREY_N)
		  ways.push_back(cell->getRight());

	if (ways.empty()) {
		return nullptr;
	}

	else {
		std::random_device seed;
		return ways[seed() % ways.size()];
	}
}

void Predator::live() {
	satiety--;
	if (satiety == 0) {
		cell->setNull();
		death();
		return;
	}

	Cell* newCell = devour();
	if (newCell != nullptr) {
		cell->setNull();
		newCell->getObject()->death();
		newCell->setObject(this);
		satiety += 6;
	} else {
		cell->setNull();
		newCell->setObject(this);
	}

	reproductionCycle--;
	if (reproductionCycle <= 0 && satiety > 10) {
		Cell* forChild = toGo();
		if (forChild != nullptr) {
			Object* o = new Predator(forChild);
			forChild->setObject(o);
			forChild->ocean->addObj(o);
			resetReproductionCycle();
		}
	}
}