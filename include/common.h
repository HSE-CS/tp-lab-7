#ifndef _COMMON_H_
#define _COMMON_H_

#include <iostream>

typedef size_t coord_t;

struct Pair
{
	coord_t i;
	coord_t j;
};

//Equal to the size of my full-screen terminal window
const size_t N = 48;
const size_t M = 210;

#endif