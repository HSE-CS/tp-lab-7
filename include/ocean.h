// Copyright 2021 MalininDmitry

#ifndef _OCEAN_H_
#define _OCEAN_H_

#include "common.h"
#include "cell.h"
#include <list>
#include <vector>

class Ocean
{

private:
    Cell **cells;
    std::vector<Object*> stuff;
    int numStones = 0;
    int numPreys = 0;
    int numPredators = 0;

public:
    Ocean(int numStones, int numPreys, int numPredators, int live_count, int time_reproduction, int satiety, int deathByStarvation);
    ~Ocean();
    void print() const;
    void addObjects(Object* obj);
    void run();
    void deleteObjects(Object* obj);
    Cell **getCells();

};
#endif
