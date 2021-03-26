// Copyright 2021 Sozinov Kirill
#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include <list>
#include "common.h"
#include "cell.h"


class Ocean {
private:
    Cell** cells;
    std::list<Object*> stuff;
    std::list<Object*> ListOfTheDead;
    int M, N, number_objects;

public:
    Ocean(int M, int N,
        int number_objects);
    ~Ocean();
    void print() const;
    void addObjects(int number_objects);
    void run();

    Cell* seachEmptyPlace(Pair coordinate);
    void addObject(Object* object__);
    void AddListOfTheDead(Object* object__);
    void ClearListOfTheDead();
    Cell* hunt(Pair coordinate);
};

#endif  // INCLUDE_OCEAN_H_