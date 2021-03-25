// Copyright 2021 MalininDmitry

#ifndef CELL_H_
#define CELL_H_
#include "common.h"
#include "object.h"
#include "ocean.h"

class Ocean;

class Cell {
    friend Ocean;
 private:
    Pair crd = {0, 0};
    Object *obj = nullptr;
    Ocean *ocean;
 public:
    explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr) :
    crd(p),
    obj(nullptr),
    ocean(oc) {}
    void init(Pair p, Ocean* oc);
    Object* getObject() const;
    void setObject(Object * object);
    void killMe();
    Pair getCrd();
    Ocean * getOcean();
};
#endif  // INCLUDE_CELL_H_
