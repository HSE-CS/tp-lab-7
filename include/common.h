// Copyright 2021 Schenikova
#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

#include <iostream>

typedef size_t coord_t;

struct Pair {
  coord_t x;
  coord_t y;
  Pair(int newX, int newY) :
  x(newX),
  y(newY) {}
};

const int N = 50;
const int M = 100;

#endif  // INCLUDE_COMMON_H_
