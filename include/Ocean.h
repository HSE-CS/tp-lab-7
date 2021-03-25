// Copyright 2021 Tyulin Igor
#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_

#pragma once
#include "common.h"
#include "Cell.h"
#include "Predator.h"
#include "Stone.h"
#include "Prey.h"
#include <list>
class Ocean
{
private:
	Cell **cells;
	std::list<Object*> stuff;
public:
	Ocean();
	~Ocean();
	void AddStuff(Object *obj);
	void addObjects(unsigned int n, ObjType type);
	bool DeleteObj(Object *obj);
	void run();
	void print() const;
	Cell * Step(Pair crd);
	Cell * Radar(Pair cord);
};

#endif  // INCLUDE_OBJECT_H_
