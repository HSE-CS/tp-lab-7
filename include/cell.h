//  Copyright 2021 Nikita Naumov
#ifndef INCLUDE_CELL_H
#define INCLUDE_CELL_H

#include "../include/ocean.h"
#include "../include/common.h"
#include "../include/Object.h"

class Ocean;
class Object;

class Cell {
    friend Ocean;
 private:
    Pair coordinates;
    Object* object;
    Ocean* ocean;

 public:
    explicit Cell(Pair p = {0, 0}, Ocean* ocean = nullptr) :
                        coordinates(p), object(nullptr), ocean(ocean) {};
    void init(Pair p, Ocean* ocean);
    Object* getObject() const;
    void setObject(Object*);
    void killMe();
    bool isFree();
    coord_t getX();
    coord_t getY();
    Ocean* getCurrentOcean();
};

#endif  //  INCLUDE_CELL_H
