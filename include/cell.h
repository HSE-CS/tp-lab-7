// Copyright 2021 Stolbov Yaroslav

#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include "../include/object.h"

class Ocean;

class Cell {
    friend Ocean;
 private:
    Object* object;
    Pair coordinates;
    Ocean* ocean;

 public:
    explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr) :
            coordinates(p), object(nullptr), ocean(oc) {}
    void initialize(Pair p, Ocean* oc);
    Object* getObject() const;
    void setObject(Object*);
    void killMe();
    Cell* moveToCell();
    Ocean* getOcean();
};

#endif  // INCLUDE_CELL_H_
