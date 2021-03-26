// Copyright 2021 mkhorosh

#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

typedef size_t coord_t;

struct Pair {
  coord_t x; // 0..M-1
  coord_t y; // 0..N-1
};

const size_t M = 100;
const size_t N = 40;

const int ST = 250;
const int P = 350;  // preys
const int PP = 700;  // predators

#endif  // INCLUDE_COMMON_H_
