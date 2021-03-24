// Copyright 2021 Igumnova Natasha
#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_
#include <iostream>
#include <string>
#include <vector>
#include "common.h"
#include "cell.h"
#include "predator.h"
#include "stone.h"
#include <list>
class Ocean {
 private:
    Cell** cells;
    std::list<Object*> stuff;
 public:
    Ocean(float preyP,float predatorP,
        float stoneP);
    ~Ocean();
    void print() const;
    void addObject(Object* elem);
    void run();
    Cell* findCell(Cell* cell);
};
#endif  // INCLUDE_OCEAN_H_
