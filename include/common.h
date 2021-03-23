// Copyright by Egor Bodrov 2021

#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

typedef size_t coord_t;

struct pair {
  unsigned x;
  unsigned y;
};

const size_t N = 50;
const size_t M = 80;

const unsigned PreyLife = 6;
const unsigned PreyReproduce = 2;

const unsigned PredLife = 5;
const unsigned PredReproduce = 4;
const unsigned PredUpgrade = 2;

#define PRED_N 'S'
#define PREY_N 'f'
#define STONE_N '#'
#define EMPTY_N '.'

#endif  // INCLUDE_COMMON_H_
