// Copyright Baklanov 2021
#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include "Cell.h"
#include <list>
#include "common.h"

class Object;

class STONE : public Object {
 private:
     int fastness;
 public:
    STONE(Pair coord, Cell* cell) :
        Object(ObjType::STONE, coord, cell), fastness(10) {}
    ~STONE() {}
    void live() override;
    int getFastness() {
        return fastness;
    }
};
#endif
