// Copyright 2021 FOM
#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

typedef size_t coord_t;

struct Pair {
    coord_t x;
    coord_t y;
};

const size_t M = 60;
const size_t N = 70;
const size_t number_objects = 3000;

const size_t probability_border_up = 60;
const size_t probability_border_down = 40;

#endif  // INCLUDE_COMMON_H_
