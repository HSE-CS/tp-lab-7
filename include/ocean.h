// Copyright 2021 Ryzhova
#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include "../include/cell.h"
#include <list>

class Ocean {	
 private:
	Cell **cells;
	std::list<Object*> stuff;

public:
	Ocean();
	~Ocean();
	void print() const;
	void addObject(Object*);
	void addRandomObject();
	Cell** getCells();
	std::list<Object*> getStuff();
	void run();
};

#endif  // INCLUDE_OCEAN_H_
