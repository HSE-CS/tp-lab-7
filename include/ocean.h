// Copyright 2021 MalininDmitry

#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_
#include <list>
#include <vector>
#include "common.h"
#include "cell.h"

class Ocean {
 private:
    Cell **cells;
    std::vector<Object*> stuff;
    int numStones = 0;
    int numPreys = 0;
    int numPredators = 0;
 public:
    Ocean(int numStones, int numPreys,
          int numPredators, int live_count,
          int time_reproduction, int satiety,
          int deathByStarvation);
    ~Ocean();
    void print() const;
    void addObjects(Object* obj);
    void run();
    void deleteObjects(Object* obj);
    Cell **getCells();
};
#endif  // INCLUDE_OCEAN_H_
