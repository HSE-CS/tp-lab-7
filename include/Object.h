// Copyright 2021 Vlad
#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_
#include "Pair.h"
#include "Cell.h"
class Cell;
enum class ObjType { STONE, CORAL, PREY, PREDATOR };
class Object {
 protected:
    Cell* cell;
    ObjType type;
 public:
    explicit Object(Cell* cell = nullptr, ObjType type = ObjType::STONE) {
        this->cell = cell;
        this->type = type;
    }
    virtual ~Object() {}
    virtual void live() = 0;
    void setCell(Cell* cell);
    virtual void move();
    Cell* getCell();
    ObjType getType();
    Cell* getNewCell(Pair pair);
    Cell* reproduct();
};
#endif  // INCLUDE_OBJECT_H_
