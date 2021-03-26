// Copyright 2021 Stolbov Yaroslav

#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_
#include <list>
#include "../include/common.h"
#include "../include/cell.h"
#include "../include/predator.h"
#include "../include/stone.h"
#include "../include/prey.h"

class Ocean {
 protected:
    Cell** cells;
    std::list<Object*> stuff;

 public:
    Ocean();
    ~Ocean();
    void addObjects(unsigned int n, ObjType type);
    void addObjectToStuff(Object* obj);
    void run();
    void print() const;
    Cell* transferObject(Pair crd);
};

#endif  // INCLUDE_OCEAN_H_
