//  Copyright 2021 Kartseva Masha
#pragma once
#define OCEAN_H
#ifdef OCEAN_H
#include "../include/common.h"
#include "../include/cell.h"
#include "../include/predator.h"
#include "../include/stone.h"
#include "../include/prey.h"
#include <list>
class Ocean {
 private:
    Cell** cells;
    std::list<Object*> stuff;
 public:
    Ocean();
    ~Ocean();
    void AddStuff(Object* obj);
    void addObjects(unsigned int n, ObjType type);
    bool DeleteObj(Object* obj);
    void run();
    void print() const;
    Cell* Step(Pair crd);
    Cell* Radar(Pair cord);
};
#endif  // OCEAN_H
