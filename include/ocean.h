// Copyright 2021 Ilya Urtyukov
#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include <list>

#include "common.h"
#include "cell.h"


class Object;
class Cell;

class Ocean {
 private:
    Cell** cells;
    std::list<Object*> stuff;
    int size_x;
    int size_y;

 public:
    Ocean(int x, int y);
    ~Ocean();
    int getSizeX();
    int getSizeY();
    void print() const;
    void addObjects(int mountprey, int mountstone, int mountpredator);
    void run();
    std::list<Object*> getStuff();
    friend Object;
};
#endif  // INCLUDE_OCEAN_H_
