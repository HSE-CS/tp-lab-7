// Copyright 2021 VladimirUspensky

#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include "../include/common.h"
#include "../include/object.h"

class Ocean;

class Cell {
    friend Ocean;
 private:
    Pair crd;
    Object *obj;
    Ocean *ocean;
 public:
    explicit Cell(Pair pair = {0, 0 }, Ocean* o = nullptr) :
            crd(pair),
            obj(nullptr),
            ocean(o) {}
    void init(Pair p, Ocean* o);
    Object* getObject() const;
    void setObject(Object*);
    void killMe();
    Ocean *getOcean() const;
    const Pair &getCrd() const;
};

#endif  // INCLUDE_CELL_H_
