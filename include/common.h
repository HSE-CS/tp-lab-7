// Copyright 2021 Dev-will-work
#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

struct Pair {
  int x;  // 0..M-1
  int y;  // 0..N-1
};

const int N = 25;
const int M = 80;
const int PREY_LIFE = 20;
const int STONE_LIFE = 30;
const int PREDATOR_LIFE = 15;
const int STARVING = 5;

#endif  // INCLUDE_COMMON_H_
