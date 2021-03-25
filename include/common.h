// Copyright 2021 MalininDmitry

#ifndef _COMMON_H_
#define _COMMON_H_

#include <stddef.h>

typedef size_t coord_t;

struct Pair
{
    coord_t x; // 0..M-1
    coord_t y; // 0..N-1
};

const size_t N = 70;
const size_t M = 70;
const size_t preyFatContent = 3;

#endif
