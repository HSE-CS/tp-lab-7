#ifndef _OCEAN_H_
#define _OCEAN_H_

#include "common.h"
#include "cell.h"
#include "prey.h"
#include "predator.h"
#include <list>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

class Ocean {
    friend Prey;
    friend Predator;

private:
    Cell **cells;
    std::list<Object *> stuff;

public:
    Ocean();

    ~Ocean();

    ObjType getNear(int, int) const;

    void print() const;

    void addObjects();

    void run();
};

#endif
