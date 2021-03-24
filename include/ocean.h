// Copyright 2021 soda

#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include "common.h"
#include "cell.h"
#include "object.h"
#include "stone.h"
#include "prey.h"
#include "predator.h"
#include <list>
#include <ctime>

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

#endif // INCLUDE_OCEAN_H_
