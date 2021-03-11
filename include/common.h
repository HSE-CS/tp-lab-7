#ifndef _COMMON_H_
#define _COMMON_H_

#include <string>
#include <vector>
#include <ctime>
#include <time.h>
#include <iostream>
// typedef size_t coord_t;

struct Pair {
  int x;  // 0..M-1
  int y;  // 0..N-1
};

const int N = 3;
const int M = 3;

const int LTPrey = 10;
const int LTPredator = 30;
const int LTStone = 10000;

#endif
