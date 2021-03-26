// Copyright 2021 Vlad
#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_
#include <iostream>
#include <vector>
#include <list>
#include "Cell.h"
#include "Pair.h"
#include "Object.h"
class Object;
class Cell;
class Ocean {
    friend Cell;
    friend Object;
 private:
    Cell **ocean;
    std::vector<Object*> objects;
    const int N = 20;
    const int M = 50;
    void setObject(Object* obj);
 public:
    Ocean(int stone, int prey, int predactor, int reproduction, int death);
    void print() const;
    void AddObject(Object* object);
    void run();
    Cell* getCell(Pair pair);
    void removeObject(Object* object);
};
#endif  // INCLUDE_OCEAN_H_
