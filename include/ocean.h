// Copyright 2021 Khoroshavina Ekaterina
#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_
#include <list>
#include "../include/object.h"
#include "../include/cell.h"
#include "../include/predator.h"
#include "../include/prey.h"
#include "../include/stone.h"

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
#endif  // INCLUDE_OCEAN_H_
