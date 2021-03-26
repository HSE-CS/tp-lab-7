// Copyright 26.03.21 DenisKabanov

#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

#include <cstddef>
typedef size_t coord_t;

struct Pair {
  int x;
  int y;
};

const size_t N = 10;
const size_t M = 10;

const size_t PREYLIFECYCLE = 20;
const size_t PREYREPRODUCECYCLE = 4;

const size_t PREDATORLIFECYCLE = 8;
const size_t PREDATORREPRODUCECYCLE = 6;

#endif  // INCLUDE_COMMON_H_
