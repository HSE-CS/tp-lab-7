// Copyright 2020 GHA Test Team
#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_


// typedef size_t coord_t;

struct Pair {
  Pair() {
    x = y = 0;
  }
  Pair(unsigned x, unsigned y) {
    this->x = x;
    this->y = y;
  }
  ~Pair() = default;
  Pair(const Pair&) = default;
  Pair& operator=(const Pair&) = default;
  unsigned x;  // 0..M-1
  unsigned y;  // 0..N-1
};

const unsigned N = 20;
const unsigned M = 50;
#endif  // INCLUDE_COMMON_H_
