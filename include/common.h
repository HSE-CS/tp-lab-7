// Copyright NikDemoShow 2021
#ifndef _COMMON_H_
#define _COMMON_H_

#define STONE_N '#'
#define CORAL_N '*'
#define PREY_N 'f'
#define PREDATOR_N 'S'

typedef size_t coord_t;

enum class ObjType { STONE, PREY, PREDATOR };

struct Pair {
  coord_t x;
  coord_t y;
};

const size_t N = 50;
const size_t M = 20;
const size_t prPrey = 80;
const size_t prPredator = 2;
const size_t prStone = 10;

#endif // _COMMON_H_
