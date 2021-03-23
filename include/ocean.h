// Copyright 2021 Khoroshavina Ekaterina
#ifndef _OCEAN_H_
#define _OCEAN_H_
#include <list>
#include "object.h"
#include "cell.h"
#include "predator.h"
#include "prey.h"
#include "stone.h"

class Ocean {
private:
	Cell** cells;
	std::list<Object*> stuff;
public:
	Ocean();
	~Ocean();
	void makeOcean(int numPrey, int numPredator, int numStone);
	void print() const;
	void addObject(Object* newObj);
	void run();
	Cell* newCell(Pair crd);
};
#endif