// Copyright 2020 GHA Test Team
#ifndef _COMMON_H_
#define _COMMON_H_


typedef size_t coord_t;

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
  coord_t x; // 0..M-1
  coord_t y; // 0..N-1
};

const size_t N = 20;
const size_t M = 50;
#endif  // INCLUDE_COMMON_H_
