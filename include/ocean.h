// Copyright 2021 Stifeev Nikita

#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include <vector>
#include <list>
#include "../include/common.h"
#include "../include/cell.h"
using std::vector;

class Ocean {
 private:
    vector<vector<Cell*>> cells;
    std::list<Object*> stuff;
    std::list<Object*> toDelete;
    void counter(size_t&, size_t&, size_t&);
    friend Cell;
 public:
    Ocean();
    ~Ocean();
    void print() const;
    void addObjects(ObjType type, size_t number);
    void run();
    vector<Cell*>* getEmptyCells(Cell*);
    void addObject(Object*);
    vector<Cell*>* getCellsWithPrey(Cell*);
    void killObject(Cell*);
};

#endif  // INCLUDE_OCEAN_H_
