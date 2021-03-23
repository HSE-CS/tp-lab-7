// Copyright 2021 Ilya Urtyukov
#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_
#include <time.h>
#include <list>
#include <vector>
#include "common.h"
#include "cell.h"
#include "stone.h"
#include "prey.h"
#include "predator.h"
#include <windows.h>


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
  Ocean(unsigned int, unsigned, unsigned,
    unsigned, unsigned, unsigned,
    unsigned, unsigned,
    unsigned, int print_delay = 300);
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
