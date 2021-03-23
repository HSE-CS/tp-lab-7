// Copyright 2021 Ilya Urtyukov
#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_
#include <iostream>

typedef size_t crd_t;

struct Pair {
  Pair() {
    x = 0;
    y = 0;
  }
  Pair(unsigned x, unsigned y) {
    this->x = x;
    this->y = y;
  }
  ~Pair() = default;
  Pair(const Pair&) = default;
  Pair& operator=(const Pair&) = default;
  crd_t x;
  crd_t y;
};

const size_t N = 20;
const size_t M = 50;
#endif  // INCLUDE_COMMON_H_
