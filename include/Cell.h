// Copyright JMax 2021
#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include "../include/Common.h"
#include "../include/Object.h"
#include "../include/Ocean.h"

class Ocean;

class Cell {
    friend Ocean;

 private:
    Pair crd;
    Object *object;
    objectType type;
    int killedObjects = 0;
    Ocean *ocean;

 public:
    explicit Cell(Pair crd = {0, 0}, Ocean* ocean = nullptr) :
            crd(crd),
            object(nullptr),
            ocean(ocean),
            type(NOTHING) {}
    void init(Pair crd, Ocean* ocean);
    Object* getObject() const;
    void setObject(Object*);
    void killMe();
    void clearMe();
    Pair getCoordinates() const;
    Cell* getCell(Pair crd) const;
    objectType getType() const;
    char getSymbol() const;
    void addToStuff(Object* object);
    ~Cell();
};

#endif  // INCLUDE_CELL_H_
