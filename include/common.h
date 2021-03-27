// Copyright 2021 Ryzhova
#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

#define PREY_VITALITY 13
#define PREDATOR_VITALITY 21

#define PREDATOR_NEEDS 4

#define PREY_BREEDING 3
#define PREDATOR_BREEDING 5

#define STONE_N '#'
#define EMPTY_N ' '
#define PREY_N '-'
#define PREDATOR_N '*'

#define TYPE_NUM 3

#include <random>

std::random_device rd;
std::mt19937 gen(rd());

enum class ObjType {
  STONE, PREY, PREDATOR
};

struct Pair {
  unsigned int x;   // 0..M-1
  unsigned int y;   // 0..N-1
};

const unsigned int N = 20;
const unsigned int M = 50;

#endif  // INCLUDE_COMMON_H_
