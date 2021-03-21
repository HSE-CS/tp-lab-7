// Copyright Baklanov 2021
#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include "Common.h"
#include "Ocean.h"
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
    explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr) :
        coord(p),
        obj(nullptr),
        isempty(true),
        ocean(oc) {}
    void init(Pair p, Ocean* oc);
    Object* getObject() {
        return obj;
    }
    void setObject(Object* a) {
        obj = a;
        if (a)
            isempty = false;
        else
            isempty = true;
    }
    bool isEmpty() {
        return isempty;
    }
    void killMe() {
        isempty = true;
        delete obj;
    }
    friend Ocean;
};
#endif  // INCLUDE_CELL_H_
