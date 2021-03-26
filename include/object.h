// Copyright 2021 Stolbov Yaroslav

#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_

#include "../include/common.h"

#define STONE_N '#'
#define PREY_N 'f'
#define PREDATOR_N 'S'

class Ocean;
class Cell;
enum class ObjType { PREY, PREDATOR, STONE };

class Object {
 protected:
    Cell* cell;
    int time_of_life;
    bool isDead;
    ObjType type;
 public:
    explicit Object(Cell*);
    virtual ~Object() {}
    virtual void live() = 0;
    void setCell(Cell*);

    virtual char getSymbol() = 0;
    void setTimeOfLive(int time);
    void die();
    Cell* getCell();
    int getState() const;
};
#endif  // INCLUDE_OBJECT_H_
