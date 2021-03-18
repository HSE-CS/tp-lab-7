//Copyright soda 2021

#ifndef _OCEAN_H_
#define _OCEAN_H_

#include "common.h"
#include "Cell.h"
#include "object.h"
#include "stone.h"
#include "prey.h"
#include "predator.h"
#include <list>
#include <ctime>

class Ocean
{

private:
	Cell** cells;
	std::list<Object*> objects;
	size_t time;
public:
	Ocean();
	~Ocean();
	void print() const;
	void addObjects(...);
	void Create_WORLD();
	void addObject(Object*);
	void delObj(const Object*);
	void run();
	Cell* get_cell(Pair);
};

void swapObj(int fist, int second, std::list<Object*>& objects);
#endif