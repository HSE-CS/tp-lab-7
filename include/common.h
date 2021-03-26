#ifndef _INCLUDE_COMMON_H_
#define _INCLUDE_COMMON_H_

#include <iostream>
#include <typeinfo>

typedef size_t coord_t;

struct Pair {
  coord_t x;  // 0..M-1
  coord_t y;  // 0..N-1
};

const size_t N = 5;
const size_t M = 5;

#endif  // _INCLUDE_COMMON_H_