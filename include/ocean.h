// Copyright 2021 BekusovMikhail

#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include <list>
#include "../include/common.h"
#include "../include/cell.h"


class Ocean {
 private:
    Cell **cells;
    std::list<Object *> stuff;
    std::list<Object *> killList;
    int M, N, objectsQuantity;

 public:
    Ocean(unsigned int M, unsigned int N,
          int objectsQuantity);

    ~Ocean() = default;

    void print() const;

    void addObjects(int quantity);

    Cell *findEmptyCell(Pair coord);

    void start();

    void addObject(Object *obj);

    void addToKillList(Object *obj);

    void clearKillList();

    Cell *findPrey(Pair coord);
};

#endif  // INCLUDE_OCEAN_H_
