// Copyright 2021 Galex

#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

struct Pair
{
  unsigned int x;
  unsigned int y;
};

const unsigned int ROWS = 30;  // x
const unsigned int COLUMNS = 80;  // y
const unsigned int PREY_LIFETIME = 21;
const unsigned int PREDATOR_LIFETIME = 18;
const unsigned int CREATURE_REPRODUCTION_TIME = 5;
const unsigned int PREDATOR_MAX_SATIETY = 3;
const unsigned int STONES_INIT_NUMBER = 500;
const unsigned int PREYS_INIT_NUMBER = 200;
const unsigned int PREDATORS_INIT_NUMBER = 100;
#endif  // INCLUDE_COMMON_H_
