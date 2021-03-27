// Copyright [2020] <Olesya Nikolaeva>

#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

#include <iostream>

typedef int coord_t;

struct Pair {
  coord_t x;  //  0..N-1
  coord_t y;  //  0..M-1
};

const int N = 20;
const int M = 20;

const int LIFE_TIME_PREDATOR = 15;
const int TIME_TO_SPAWN_PREDATOR = 3;
const int TIME_TO_DIE_WITHOUT_FOOD = 3;

const int LIFE_TIME_PREY = 10;
const int TIME_TO_SPAWN_PREY = 3;

#endif  //  INCLUDE_COMMON_H_
