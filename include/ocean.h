// Copyright 2021 VladimirUspensky

#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include <vector>
#include "../include/common.h"
#include "../include/cell.h"
#include "../include/prey.h"
#include "../include/predator.h"
#include "../include/stone.h"

class Ocean {
 private:
    Cell **cells;
    std::vector<Object*> stuff;
 public:
    std::vector<Object*> temp_stuff;
    std::minstd_rand rand;
    Ocean();
    ~Ocean();
    void run();
    void show() const;
    void addObjects();
    Cell **getCells() const;
};

#endif  // INCLUDE_OCEAN_H_
