// Copyright 2021 Dumarevskaya
#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

#include <random>

struct Pair {
  int x;  // 0..M-1
  int y;  // 0..N-1
};

static std::random_device rd;
static std::mt19937 gen(rd());

const int N = 100;
const int M = 30;
const int PREY_LIFE = 20;
const int PREY_BREED = 10;
const int PREDATOR_LIFE = 30;
const int PREDATOR_BREED = 15;
const int STONE_NUM = 100;
const int PREY_NUM = 1000;
const int PREDATOR_NUM = 1000;

#endif  // INCLUDE_COMMON_H_
