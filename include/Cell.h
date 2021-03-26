// Copyright 2021 Vlad
#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_
#include "Pair.h"
#include "Object.h"
#include "Ocean.h"
class Ocean;
class Cell {
    friend Ocean;
 private:
    Pair crd;
    Object* obj;
    Ocean* ocean;
 public:
    explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr)
        : crd(p), obj(nullptr), ocean(oc) {}
    void init(Pair p, Ocean* oc);
    Object* getObject() const;
    void setObject(Object* object);
    void killMe();
    Ocean* getOcean();
    int getX();
    int getY();
    void removeObj();
    void addObject(Object* obj);
};
#endif  // INCLUDE_CELL_H_
