// Copyright 2021 FOM
#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include <list>
#include "../include/common.h"
#include "../include/cell.h"


class Ocean {
 private:
    Cell** cells;
    std::list<Object*> stuff;
    std::list<Object*> ListOfTheDead;
    size_t M, N, number_objects;

 public:
    Ocean(size_t M, size_t N,
        size_t number_objects);
    ~Ocean();
    void print() const;
    void addObjects(size_t number_objects);
    void run();

    Cell* seachEmptyPlace(Pair coordinate);
    void addObject(Object* object__);
    void AddListOfTheDead(Object* object__);
    void ClearListOfTheDead();
    Cell* hunt(Pair coordinate);
};

#endif  // INCLUDE_OCEAN_H_
