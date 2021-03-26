// Copyright [2020] <Olesya Nikolaeva>

#ifndef _CELL_H_
#define _CELL_H_

#include "common.h"
#include "object.h"

class Ocean;

class Cell {
    friend Ocean;

 private:
    Pair crd;
    Object *obj;
    Ocean *ocean;

 public:
    explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr) :
        crd(p),
        obj(nullptr),
        ocean(oc) {}
    void init(Pair p, Ocean* oc);
    Object* getObject() const;
    void setObject(Object*);
};

#endif  //  INCLUDE_CELL_H_
