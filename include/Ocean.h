// copyright 2021 Victor Shatilov

#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include <vector>
#include "../include/common.h"

class Ocean {
 private:
    std::vector<std::vector<Cell *>> water;

 public:
    explicit Ocean();

    void renderOcean();

    void init(int stones, int preys, int predators);

    void run(int iterations = -1);

    bool isConditionOkay();

    Cell *getCell(int x, int y);
};


#endif  // INCLUDE_OCEAN_H_
