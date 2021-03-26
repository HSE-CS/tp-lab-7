// Copyright 2021 Kuznetsov Mikhail
#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <random>
#include <cstdlib>
#include "common.h"
#include "cell.h"
#include "object.h"
#include "prey.h"
#include "predator.h"
#include "stone.h"

class Cell;
class Object;

class Ocean {
 private:
    unsigned int height;  // number of lines
    unsigned int width;  // number of columns
    std::vector<std::vector<Cell*>> cells;
    std::vector<unsigned int> addOrder;
    std::set<Object*> objects;
    std::map<NATURE, char> picture{{UNKNOWN, '.'},
                                  {PREY, 'f'},
                                  {PREDATOR, 'S'},
                                  {STONE, '#'}};
    std::map<NATURE, unsigned int> longevity{{UNKNOWN, 0},
                                                {PREY, 20},
                                                {PREDATOR, 10},
                                                {STONE, 1000}};

 public:
    Ocean(unsigned int _height, unsigned int _width);
    ~Ocean();
    void print();
    void createObjects(NATURE _nature, unsigned int _count);
    void generateOrder();
    void addObject(Object* _object);
    void deleteObject(Cell* _cell);
    void run(unsigned int _years);
    unsigned int getHeight();
    unsigned int getWidth();
    Cell* getCell(unsigned int _x, unsigned int _y);
};

#endif  // INCLUDE_OCEAN_H_
