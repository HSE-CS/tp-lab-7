//  Copyright 2021 Nikita Naumov
#ifndef INCLUDE_OCEAN_H
#define INCLUDE_OCEAN_H

#include <vector>
#include <typeinfo>
#include <iostream>
#include "../include/common.h"
#include "../include/cell.h"
#include "../include/Object.h"
#include "../include/prey.h"

class Cell;
class Object;

class Ocean {
 private:
    Cell** cells;
    std::vector<Object*> stuff;

 public:
    Ocean();
    ~Ocean();
    void print() const;
    void addObjects();
    void run();
    std::vector<Cell> getNearbyCells(int i, int j);
    Cell* getCell(int i, int j);
    void setObjectToCell(Object* object, int i, int j);
};

#endif  //  INCLUDE_OCEAN_H
