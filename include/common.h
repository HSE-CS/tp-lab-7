// Copyright 2021 Andrey Bakurskii


#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

typedef int coord_t;

struct Pair {
  coord_t x;  // 0..M-1
  coord_t y;  // 0..N-1
};

const int N = 20;
const int M = 50;

#endif  // INCLUDE_COMMON_H_
