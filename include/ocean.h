// Copyright 2021 valvarl

#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include <vector>
#include "common.h"
#include "cell.h"
#include "prey.h"
#include "predator.h"
#include "stone.h"

class Ocean {
 private:
    Cell **cells;
    std::vector<Object*> stuff;
 public:
    std::vector<Object*> temporary_stuff;
    std::minstd_rand simple_rand;
    Ocean();
    void print() const;
    void addObjects();
    void run();
    Cell **getCells() const;
    ~Ocean();
};

#endif  // INCLUDE_OCEAN_H_
