//  Copyright © 2021 Ksuvot
#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include "Common.h"
#include "Cell.h"
#include <list>

class Object;
class Cell;

class Ocean {
 private:
    Cell** cells;
    std::list<Object*> stuff;
    int x;
    int y;

 public:
    Ocean(int x, int y);
    ~Ocean() {
        stuff.clear();
        delete[] cells;
    }
    [[nodiscard]] int getX() const {
        return x;
    }
    [[nodiscard]] int getY() const {
        return y;
    }
    void print() const;
    void addObjects(int prey, int stone, int predator);
    void run();
    friend Object;
    std::list<Object*> getStuff() {
        return stuff;
    }
};
#endif  // INCLUDE_OCEAN_H_
