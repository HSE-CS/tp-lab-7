//  Copyright 2021 Nikita Naumov
#ifndef INCLUDE_OCEAN_H
#define INCLUDE_OCEAN_H

#include <list>
#include <vector>
#include <typeinfo>
#include <iostream>
#include "common.h"
#include "cell.h"

class Ocean {
 private:
    Cell** cells;
    std::list<Object*> stuff;

 public:
    Ocean();
    ~Ocean();
    void print() const;
    void addObjects();
    void run();
};

#endif  //  INCLUDE_OCEAN_H
