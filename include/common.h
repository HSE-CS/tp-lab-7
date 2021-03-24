// Copyright 2020 Vadukk
#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_



struct Pair {
  int x;
  int y;
};

const int N = 50;
const int M = 200;

enum TimeOfLive {
  TIME_STONE = 1000,
  TIME_PREY = 20, TIME_PREDATOR = 30
};
#endif  // INCLUDE_COMMON_H_
