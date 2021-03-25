//  Copyright 2021 Nikita Naumov
#ifndef INCLUDE_OCEAN_H
#define INCLUDE_OCEAN_H

#include <vector>
#include <typeinfo>
#include <iostream>
#include "../include/common.h"
#include "../include/cell.h"
#include "../include/Object.h"
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
    std::vector<Object*> getFreeAround();
};

#endif  //  INCLUDE_OCEAN_H
