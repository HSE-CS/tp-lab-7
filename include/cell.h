// Copyright 2020 PollyllyZh
#pragma once
#include "object.h"
#include "ocean.h"
class Cell {
    friend Ocean;

private:
    Pair crd;
    Object* object;
    Ocean* ocean;

public:
    explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr) :
        crd(p),
        object(nullptr),
        ocean(oc) {}
    void init(Pair p, Ocean* oc);
    Object* get_object();
    Ocean* get_ocean();
    void set_object(Object*);
    void killMe();
    Cell* get_free_cell();
    Cell* get_prey();
};
