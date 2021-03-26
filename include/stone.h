// Copyright 2020 PollyllyZh

#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include "../include/object.h"
#include "../include/cell.h"
#include "../include/ocean.h"
#include "../include/common.h"

class Stone : public Object {
public:
    Stone(Cell* cell) : Object(cell) {
        obj_type = ObjType::STONE;
        lifetime = stone_lim;
    };
    ~Stone() = default;
    bool live() override;
    char get_symbol() override;
};
#endif  // INCLUDE_STONE_H_