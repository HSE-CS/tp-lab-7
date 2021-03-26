// Copyright TimurZaytsev 2021
#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

#define STONE_N '#'
#define CORAL_N '*'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum class ObjType { STONE, PREY, PREDATOR };

struct Pair {
  unsigned int x;
  unsigned int y;
};

const unsigned int N = 100;
const unsigned int M = 40;
const unsigned int prPrey = 80;
const unsigned int prPredator = 2;
const unsigned int prStone = 10;

#endif  // INCLUDE_COMMON_H_
