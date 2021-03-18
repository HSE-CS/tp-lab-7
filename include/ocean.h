// Copyright 2020 GHA Test Team
#ifndef _OCEAN_H_
#define _OCEAN_H_
#include "common.h"
#include "Cell.h"
#include "stone.h"
#include "prey.h"
#include "predator.h"
#include <list>
#include <vector>
#include "windows.h"
#include <time.h>


class Ocean {
 private:
	Cell** cells;
	std::list<Object*> stuff;
	std::list<Object*> objectsToDie;
	std::list<Object*> objectsToReproduce;
	unsigned size_x, size_y;
	unsigned stones_n, preys_n, predators_n;
	unsigned prey_live_num, predator_live_num;
	unsigned prey_food_n_to_reproduce, predator_food_n_to_reproduce;
	unsigned objects_num;
	int print_delay;
	void init_cells();
	void createObjects();

 public:
	Ocean();
	Ocean(unsigned int size_x, unsigned size_y, unsigned stones_n,
		unsigned preys_n, unsigned predators_n, unsigned prey_live_num,
		unsigned prey_food_n_to_reproduce, unsigned predator_live_num,
		unsigned predator_food_n_to_reproduce, int print_delay = 300);
	~Ocean();
	Ocean(const Ocean&) = delete;
	Ocean& operator=(const Ocean&) = delete;
	void print() const;
	void addObjects();
	void run();
	unsigned getSize_x() const;
	unsigned getSize_y() const;
	Cell** getCells() const;
	void addObjectToDie(Object* obj);
	void addObjectToReproduce(Object* obj);
	void killObjects();
	void reproduceObjects();
	void decPreysNum();
	void incPreysNum();
	void decPredatorsNum();
	void incPredatorsNum();
};
#endif  // INCLUDE_OCEAN_H_
