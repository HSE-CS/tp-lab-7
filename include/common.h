// Copyright 2021 Igumnova Natasha
#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_
#include <iostream>
#include <string>
#include <vector>

struct Pair {
    int x;
    int y;
};
const size_t N = 20;
const size_t M = 50;
const int num_breed = 10;

#define STONE_N '#'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum ObjType { STONE, CORAL, PREY, PREDATOR };

#endif  // INCLUDE_COMMON_H_
