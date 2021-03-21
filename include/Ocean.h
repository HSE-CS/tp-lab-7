// Copyright Baklanov 2021
#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include "Cell.h"
#include <list>
#include "common.h"

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
    ~Ocean() {
        stuff.clear();
        delete[] cells;
    }
    int getSizeX() {
        return size_x;
    }
    int getSizeY() {
        return size_y;
    }
    void print() const;
    void addObjects(int mountprey, int mountstone, int mountpredator);
    void run();
    std::list<Object*> getStuff() {
        return stuff;
    }
    friend Object;
};
#endif  // INCLUDE_OCEAN_H_
