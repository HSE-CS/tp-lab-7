//  Copyright 2021 Kartseva Masha
#pragma once
#define OCEAN_H
#ifdef OCEAN_H
#include "Cell.h"
#include "Common.h"
#include "Predator.h"
#include "Prey.h"
#include "Stone.h"
#include "Object.h"
#include <list>
#include <iostream>
#include <random>
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
