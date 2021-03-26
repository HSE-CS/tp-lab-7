// Copyright 2020 Uskova
#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

struct Pair {
  int x;  // 0..M-1
  int y;  // 0..N-1
};

const int N = 10;
const int M = 15;

const int PREY_LIFETIME = 10;
const int PREDATOR_LIFETIME = 8;
const int PREY_BREEDING = 4;
const int PREDATOR_BREEDING = 5;
const int HUNGRY = 5;

const double PREDATORS = 0.3;
const double PREYS = 0.2;
const double STONES = 0.08;

#endif  //  INCLUDE_COMMON_H_
