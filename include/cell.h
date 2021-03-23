// Copyright 2021 Ilya Urtyukov
#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include "common.h"
#include "ocean.h"
#include <iostream>

class Ocean;
class Object;

class Cell {
 private:
    Pair coord;
    Object* obj;
    Ocean* ocean;
    bool isempty;

 public:
    explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr) 
    void init(Pair p, Ocean* oc);
    Object* getObject();
    void setObject(Object*);
    bool isEmpty();
    void killMe();
    friend Ocean;
};
#endif  // INCLUDE_CELL_H_
