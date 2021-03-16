//
// Created by freeb on 15.03.2021.
//

#ifndef TP_LAB_7_OBJECT_H
#define TP_LAB_7_OBJECT_H

#include "common.h"

#define STONE_N '#'
#define CORAL_N '*'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum  class ObjType {
    STONE,
    CORAL,
    PREY,
    PREDATOR
};

class Cell;

class Object {
protected:
    Cell *cell;
public:
    Object(Cell * = nullptr);
    virtual ~Object();
    virtual void live() = 0;
    void setCell(Cell*);
};

#endif //TP_LAB_7_OBJECT_H
