//  Copyright 2021 Nikita Naumov
#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include <vector>
#include <typeinfo>
#include <iostream>
//#include <chrono>
//#include <thread>
#include "../include/common.h"
#include "../include/cell.h"
#include "../include/Object.h"
#include "../include/prey.h"

class Cell;
class Object;

class Ocean {
 private:
    Cell **cells;
    std::vector<Object *> stuff;

 public:
    Ocean();

    ~Ocean();

    void print() const;

    void addObjects(int amountOfPredators, int amountOfPreys,
                    int amountOfStones, int amountOfCorals);

    void run(int amountOfPredators, int amountOfPreys,
             int amountOfStones, int amountOfCorals);

    std::vector<Cell> getNearbyCells(int i, int j);

    Cell *getCell(int i, int j);

    void setObjectToCell(Object *object, int i, int j);

    bool isTherePredatorsOrPreys();

    void addToVector(Object* objToAdd);
    void removeFromVector(Pair coordPair);
    Object* returnByCoords(coord_t x, coord_t y);
};
#endif  //  INCLUDE_OCEAN_H_
