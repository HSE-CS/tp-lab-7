// Copyright 2021 VadMack

#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

#include <cstddef>
typedef size_t coord_t;

struct Pair {
  int x; // 0..M-1
  int y; // 0..N-1
};

const size_t N = 10;
const size_t M = 10;

const size_t PREYLIFECYCLE = 15;
const size_t PREYREPRODUCECYCLE = 7;

const size_t PREDATORLIFECYCLE = 10;
const size_t PREDATORREPRODUCECYCLE = 9;

#endif  // INCLUDE_COMMON_H_
