// Copyright 2021 Dumarevskaya
#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

// typedef size_t coord_t;

struct Pair {
  int x;  // 0..M-1
  int y;  // 0..N-1
};

const int N = 100;
const int M = 100;
const int PREY_LIFE = 20;
const int PREY_BREED = 10;
const int PREDATOR_LIFE = 30;
const int PREDATOR_BREED = 15;

#endif  // INCLUDE_COMMON_H
