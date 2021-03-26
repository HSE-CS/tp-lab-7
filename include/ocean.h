// Copyright 2021 Stifeev Nikita

#ifndef INCLUDE_OCEAN_H
#define INCLUDE_OCEAN_H

#include "../include/common.h"
#include "../include/cell.h"
#include <list>
#include <vector>
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

#endif  // INCLUDE_OCEAN_H
