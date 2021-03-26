// Copyright 2021 Nikolaev Ivan

#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_
#include <random>

struct Pair {
    int x;
    int y;
};

static std::random_device rd;
static std::mt19937 gen(rd());

#endif  // INCLUDE_COMMON_H_
