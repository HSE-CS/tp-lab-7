// Copyright 2020 Osmanov Islam
#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include <iostream>
#include <vector>
#include <string>
#include "../include/object.h"

class Ocean;

class Cell {
    friend Ocean;
 private:
    Pair crd;
    Object* obj;
    Ocean* ocean;
 public:
    explicit Cell(Pair par = { 0, 0 }, Ocean* ocean1 = nullptr);
    void init(Pair p, Ocean* oc);
    Object* getObject() const;
    Ocean* getOcean() const;
    void setObject(Object* obj);
};
#endif  // INCLUDE_CELL_H_
