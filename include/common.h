// Copyright 2021 Khoroshavina Ekaterina
#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

typedef int coord_t;

struct Pair {
    coord_t x;
    coord_t y;
};

const int N = 20;
const int M = 50;
const int HP_STONE = 500;
const int HP_PREY = 25;
const int HP_PREDATOR = 40;
#endif