// Copyright Baklanov 2021
#ifndef _STONE_H_
#define _STONE_H_

#include "common.h"
#include "Cell.h"
#include <list>

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
