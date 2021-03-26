// Copyright 2021 by Sid

#ifndef Object_h
#define Object_h
#include "Cell.h"
#include "Settings.h"

class Cell;

class Object {
protected:
    Cell* cell;
    int lifetime;
public:
    Object(Cell* cell) : cell(cell) {}
    ~Object() {
        cell = nullptr;
    }

    virtual bool live() = 0;

    virtual char getSymbol() = 0;


    void setCell(Cell* cell) { this->cell = cell; }
    Cell* getCell() { return cell; }
    void setLifetime(int lifetime) { this->lifetime = lifetime; }

};

#endif /* Object_h */
