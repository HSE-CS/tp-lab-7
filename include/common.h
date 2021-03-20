//// Copyright 2021 Ozhiganova Polina
#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

typedef int coord_t;

struct Pair {
  coord_t x; // 0..M-1
  coord_t y; // 0..N-1
};

/* field size */
const int N = 20;
const int M = 20;

/* breed */
const int PREY_BREED_PERIOD = 3;   // steps
const int PREDATOR_BREED_PERIOD = 2;  // eaten fish
/* life */
const int PREY_LIFE_PERIOD = 6;
const int PREDATOR_LIFE_PERIOD = 5;

#endif  //  INCLUDE_COMMON_H_
