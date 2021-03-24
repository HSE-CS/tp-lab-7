// Copyright 2021 soda

#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include <list>
#include <ctime>

#include "../include/common.h"
#include "../include/cell.h"
#include "../include/object.h"
#include "../include/stone.h"
#include "../include/prey.h"
#include "../include/predator.h"

class Ocean {
 private:
    Cell** cells;
    std::list<Object*> objects;
    size_t time;

 public:
    Ocean();
    ~Ocean();
    void Create_WORLD();
    void run();
    void addObject(Object*);
    void delObj(const Object*);
    void print() const;
    Cell* get_cell(Pair);
};

void swapObj(int fist, int second, std::list<Object*>* objects);

#endif  // INCLUDE_OCEAN_H_
