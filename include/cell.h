// Copyright [2020] <Olesya Nikolaeva>

#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include "common.h"
#include "object.h"

class Ocean;

class Cell {
    friend Ocean;

 private:
    Pair crd;
    Object *obj;
    Ocean *ocean;
    bool isfree = true;

 public:
    explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr) :
        crd(p),
        obj(nullptr),
        ocean(oc) {}
    void init(Pair p, Ocean* oc);
    void changeStatus(bool);
    Object* getObject() const;
    void setObject(Object*);
    Pair returnLocation();
    bool returnCellfromOcean(Pair);
    Cell* returnCellPointer(Pair);
};

#endif  //  INCLUDE_CELL_H_
