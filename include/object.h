// Copyright Mushka Nikita 2021

#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "common.h"

class Cell;
class Object {
protected:
    Cell *cell;
    char symbol{};

public:

    explicit Object(Cell * = nullptr);

    ~Object();

    Cell *getCell();

    [[nodiscard]] char getSymbol() const;

    void setSymbol(char symbol);

    virtual void step() = 0;

    void setCell(Cell *);

    void die();
};

#endif