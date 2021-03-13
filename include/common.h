#ifndef _COMMON_H_
#define _COMMON_H_

#include <iostream>

typedef size_t coord_t;

struct Pair
{
	coord_t i; // 0..M-1
	coord_t j; // 0..N-1
};

const size_t N = 48;
const size_t M = 210;

#endif