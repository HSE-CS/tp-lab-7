// Copyright 2021 valvarl

#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_

#include "common.h"

#define NOTHING_N '.'
#define STONE_N '#'
#define CORAL_N '*'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum class ObjType {
    CORAL,
    STONE,
    PREY,
    PREDATOR
};

class Cell;

class Object {
 protected:
    Cell *cell;
    ObjType type;
    int remain_live;
 public:
    explicit Object(Cell * = nullptr);
    Object(const Object &object) : cell(object.cell), type(object.type),
    remain_live(object.remain_live) {}
    virtual ~Object();
    virtual void live() = 0;
    void setCell(Cell* c);
    ObjType getType() const;

    int getRemainLive() const;

    void setRemainLive(int remainLive);

    Cell *getCell() const;
};

#endif  // INCLUDE_OBJECT_H_
