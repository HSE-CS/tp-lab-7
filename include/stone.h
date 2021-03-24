// Copyright 2021 Ilya Urtyukov
#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_
#include <list>

#include "cell.h"
#include "common.h"

class Object;

class STONE : public Object {
 private:
     int fastness;
 public:
    STONE(Pair coord, Cell* cell) :
        Object(ObjType::STONE, coord, cell) {fastness = 10;}
    ~STONE() {}
    void live() override;
    int getFastness();
};
#endif  // INCLUDE_STONE_H_
