// Copyright 2021 Krayushkina
#pragma once

#include <list>
#include "../include/common.h"
#include "../include/Cell.h"
#include "../include/Predator.h"
#include "../include/Stone.h"
#include "../include/Prey.h"
class Ocean {
 private:
    Cell **cells;
    std::list<Object*> stuff;
 public:
    Ocean();
    ~Ocean();
    void AddStuff(Object *obj);
    void addObjects(unsigned int n, ObjType type);
    bool DeleteObj(Object *obj);
    void run();
    void print() const;
    Cell * Step(Pair crd);
    Cell * Radar(Pair cord);
}
