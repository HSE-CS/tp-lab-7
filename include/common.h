// Copyright NikDemoShow 2021
#ifndef _COMMON_H_
#define _COMMON_H_

#define STONE_N '#'
#define CORAL_N '*'
#define PREY_N 'f'
#define PREDATOR_N 'S'


enum class ObjType { STONE, PREY, PREDATOR };

struct Pair {
  unsigned int x;
  unsigned int y;
};

const unsigned int N = 50;
const unsigned int M = 20;
const unsigned int prPrey = 80;
const unsigned int prPredator = 2;
const unsigned int prStone = 10;

#endif // _COMMON_H_
