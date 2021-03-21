#ifndef _CELL_H_
#define _CELL_H_

#include "common.h"
#include "Ocean.h"
#include <iostream>

class Ocean;
class Object;

class Cell
{
    friend Ocean;
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
    };
    void setObject(Object* a) {
        obj = a;
        if (a)
            isempty = false;
        else
            isempty=true;

    };
    bool isEmpty() {
        return isempty;
    };
    void killMe() {
        isempty = true;
        delete obj;
    }

};
#endif