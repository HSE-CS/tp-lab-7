// Copyright [2020] <Olesya Nikolaeva>

#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "common.h"

#define STONE_N '#'
#define PREY_N 'f'
#define PREDATOR_N 'S'
#define EMPTY_N ' '

enum class ObjType {
    STONE,
    PREY,
    PREDATOR,
    EMPTY
};

class Cell;

class Object {
 private:
    ObjType type;

 protected:
    Cell *cell;

 public:
    explicit Object(ObjType type, Cell *cl = nullptr);
    virtual ~Object();
    virtual void live() = 0; // жизнь объекта
    void setCell(Cell*);
    void setObjType(ObjType);
    ObjType getObjType();
};

#endif  //  INCLUDE_OBJECT_H_
