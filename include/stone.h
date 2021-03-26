// copyright 2021 Victor Shatilov

#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include "../include/common.h"

class stone : public Object {
 public:
    explicit stone(int x, int y, int energy = -1,
                   int type = STONE, Cell *cell = nullptr);

    virtual void live();  // do nothing

    virtual Object *divide();  // do nothing

    virtual char getFiller();
};

#endif  // INCLUDE_STONE_H_
