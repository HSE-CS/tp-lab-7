// Copyright 2020 Osmanov Islam

#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "../include/common.h"
#include "../include/cell.h"
#include "../include/predator.h"
#include "../include/stone.h"

class Ocean {
 private:
    Cell** cells;
    std::list<Object*> animals;
 public:
    Ocean(float preyPercentage,
          float predatorPercentage,
          float stonePercentage);
    ~Ocean();
    void print() const;
    void addObject(Object* elem);
    void run();
    Cell* findCell(Cell* cell);
};

#endif // INCLUDE_OCEAN_H_
