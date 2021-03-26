// Copyright 2021 Kuznetsov Mikhail
#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_

#include "common.h"

class Cell;
class Ocean;

class Object {
 protected:
    Cell* cell;
    NATURE nature;
    unsigned int age;
 public:
    explicit Object(Cell* _cell = nullptr,
                    NATURE _nature = NATURE::UNKNOWN,
                    unsigned int _age = 0);
    virtual ~Object() = 0;
    void setCell(Cell* _cell);
    void setNature(NATURE _nature);
    void setAge(unsigned int _age);
    Cell* getCell();
    NATURE getNature();
    unsigned int getAge();
    virtual void live();
};

#endif  // INCLUDE_OBJECT_H_
