// Copyright 2021 Dmitry Vargin
#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include "../include/common.h"
#include "../include/object.h"

class Ocean;

class Cell {
    friend Ocean;
    friend Object;
 private:
    Object *object;
    Ocean *ocean;
 public:
    std::pair<int, int> crd;
    explicit Cell(std::pair<int, int> p,
                  Ocean *oc);
    Object *getObject() const;
    void setObject(Object *obj);
    Ocean *getOcean();
    bool hasObject() {return this->object != nullptr;}
};

#endif  // INCLUDE_CELL_H_
