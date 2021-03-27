// Copyright 2021 Smirnov Grigory
#include "../include/prey.h"
#include "../include/cell.h"
#include "../include/ocean.h"
#include <random>
#include <vector>

Prey::Prey(Cell* c) : Object(c) {
	std::random_device seed;
	liveCycle = 20 + (seed() % 5);
	type = PREY_N;
}

Cell* Prey::toGo() {
	std::vector<Cell*> ways;

	if (cell->getTop()->getObject() == nullptr)
		ways.push_back(cell->getTop());
	if (cell->getBot()->getObject() == nullptr)
		ways.push_back(cell->getBot());
	if (cell->getLeft()->getObject() == nullptr)
		ways.push_back(cell->getLeft());
	if (cell->getRight()->getObject() == nullptr)
		ways.push_back(cell->getRight());

	if (ways.empty()) {
		return nullptr;
	} else {
		std::random_device seed;
		return ways[seed() % ways.size()];
	}
}

void Prey::resetReproductionCycle() {
	reproductionCycle = 10;
}

void Prey::live() {
	liveCycle--;
	if (liveCycle == 0) {
		cell->setNull();
		death();
		return;
	}

	Cell* newCell = toGo();
	if (newCell != nullptr) {
		cell->setNull();
		newCell->setObject(this);
	}

	reproductionCycle--;
	if (reproductionCycle <= 0) {
		Cell* forChild = toGo();
		if (forChild != nullptr) {
			Object* o = new Prey(forChild);
			forChild->setObject(o);
			forChild->ocean->addObj(o);
			resetReproductionCycle();
		}
	}
}
