//  Copyright © 2021 Ksuvot
#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include "Common.h"
#include "Ocean.h"
#include <iostream>

class Ocean;
class Object;

class Cell {
 private:
    Pair pair_;
    Object* object_;
    Ocean* ocean_;
    bool is_empty;

 public:
    explicit Cell(Pair pair = {0, 0 }, Ocean* p_ocean = nullptr) :
        pair_(pair),
        object_(nullptr),
        is_empty(true),
        ocean_(p_ocean) {}
        friend Ocean;
    void killMe();
    bool is_Empty();
    Object* getObject();
    void setObject(Object* object);
    void init(Pair pair, Ocean* p_ocean);
};
#endif  // INCLUDE_CELL_H_
