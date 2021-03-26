// Copyright 2021 Nikolaev Ivan

#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_
#include <string>
#include <list>
#include "../include/object.h"
#include "../include/cell.h"
#include "../include/predator.h"
#include "../include/stone.h"

class Ocean {
 public:
    Ocean();
    Ocean(int height, int width, int preys, int predators, int stones);
    ~Ocean();

    void addObject(int x, int y, Object* obj);
    void addObjects();
    void addPreys();
    void addPredators();
    void run();
    Cell** getCells();
    void setCell(int x, int y, Object* obj);
    void deleteObj(Object* objectForDelete);
    int getPreys();
    void setPreys(int preys);
    int getPredators();
    void setPredators(int predators);
    int getHeight();
    int getWidth();
    void print() const;

 protected:
    int height = 0;
    int width = 0;
    int preys = 0;
    int predators = 0;
    int stones = 0;
    Cell** cells;
    std::list<Object*> stuff;
};

#endif  // INCLUDE_OCEAN_H_
