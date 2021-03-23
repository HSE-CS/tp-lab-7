#ifndef _COMMON_H_
#define _COMMON_H_

#include <time.h>

#include <algorithm>
#include <ctime>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <vector>

typedef size_t coord_t;

struct Pair {
  int x;
  int y;
};

const int LTPrey = 20;
const int LTPredator = 30;
const int LTStone = 10000;

const size_t N = 50;
const size_t M = 60;

#endif
