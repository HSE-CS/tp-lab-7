// Copyright 2021 Khoroshavina Ekaterina
#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_
#include "../include/common.h"

#define STONE_N '#'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum class ObjType { STONE, EMPTY, PREY, PREDATOR };

class Cell;
class Object {
 protected:
    Cell* cell;
    ObjType objType;
    bool alive;
    int hp;
 public:
    explicit Object(ObjType newObjType, Cell* cell = nullptr);
    virtual ~Object();
    virtual void live() = 0;
    void setCell(Cell*);
    void death();
    Cell* getCell();
    ObjType getType();
    bool isAlive() const;
};
#endif // INCLUDE_OCEAN_H_
