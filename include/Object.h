// Copyright 2021 Tyulin Igor

#pragma once
#include <iostream>
#include "common.h"
#define STONE_N '#'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum class ObjType { STONE, PREY, PREDATOR };
class Ocean;
class Cell;
class Object {
    friend Ocean;
    friend Cell;
 protected:
    int lifetime;
    bool dead;
    Cell * cell;
    ObjType type;
 public:
    Object(Cell * = nullptr);
    virtual ~Object() {};
    void setLive(int lifetime);
    void setCell(Cell* cell);
    virtual void live() = 0;
    virtual char getSymbol() = 0;
    unsigned int getLive();
    Cell * getCell();
    bool is_live();
    void readytodie();
    ObjType getType();
};

