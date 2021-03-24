// Copyright 2021 Igumnova Natasha
#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_
#include <iostream>
#include <string>
#include <vector>
#include "../include/object.h"

class Ocean;

class Cell {
    friend Ocean;
 private:
    Pair crd;
    Object* obj;
    Ocean* ocean;
 public:
    explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr) :
        crd(p),
        obj(nullptr),
        ocean(oc) {}
    void init(Pair p, Ocean* oc);
    Object* getObject() const;
    Ocean* getOcean() const;
    void setObject(Object* obj);
    int getX() const;
    int getY() const;
    void killMe();
    bool isEmpty() const;
};
#endif  // INCLUDE_CELL_H_
