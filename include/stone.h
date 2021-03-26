// Copyright 2020 PollyllyZh
#pragma once
#include "object.h"
#include "cell.h"
#include "ocean.h"
#include "common.h"

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
