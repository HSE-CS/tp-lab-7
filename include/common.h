// Copyright 2021 soda

#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

#include <iostream>

typedef size_t coord_t;

struct Pair {
    coord_t i;
    coord_t j;
};

// Equal to the size of my full-screen terminal window
const size_t N = 48;
const size_t M = 210;

#endif  // INCLUDE_COMMON_H_
