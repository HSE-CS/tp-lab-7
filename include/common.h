// Copyright 2021 Stifeev Nikita

#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_
#include <cstddef>
using std::size_t;

typedef size_t coord_t;

struct Pair {
    coord_t x;
    coord_t y;
};

const size_t N = 50;
const size_t M = 100;
const int PREY_DEATH = 10;
const int PREY_REPRODUCE = 3;

const int PREDATOR_DEATH = 10;
const int PREDATOR_REPRODUCE = 3;
const int PREDATOR_LIFE_WO_EATING = 7;
const int PREDATOR_REPRODUCE_WO_EATING = 5;

#endif  // INCLUDE_COMMON_H_
