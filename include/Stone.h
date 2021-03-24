//  Copyright © 2021 Ksuvot
#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include "Cell.h"
#include "Common.h"
#include <list>

class Object;

class STONE : public Object {
 private:
     int speed;
 public:
    STONE(Pair pair, Cell* cell) :
        Object(ObjType::STONE, pair, cell), speed(10) {}
    ~STONE() override = default;
    void live() override;
    [[nodiscard]] int getSpeed() const {
        return speed;
    }
};
#endif  // INCLUDE_STONE_H_
