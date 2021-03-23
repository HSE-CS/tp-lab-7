// Copyright 2021 Dev-will-work
#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

typedef size_t coord_t;

struct Pair {
  coord_t x;  // 0..M-1
  coord_t y;  // 0..N-1
};

const size_t N = 25;
const size_t M = 80;
const size_t PREY_LIFE = 20;
const size_t STONE_LIFE = 30;
const size_t PREDATOR_LIFE = 15;
const size_t STARVING = 5;

#endif  // INCLUDE_COMMON_H_
