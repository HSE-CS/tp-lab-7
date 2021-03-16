//
// Created by freeb on 15.03.2021.
//

#ifndef TP_LAB_7_CELL_H
#define TP_LAB_7_CELL_H

#include "common.h"
#include "object.h"

class Ocean;

class Cell
{
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
    void killMe();
};

#endif //TP_LAB_7_CELL_H
