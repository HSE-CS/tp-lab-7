// Copyright 2021 Stolbov Yaroslav

#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

struct Pair {
    int x;
    int y;
};

const int N = 50;
const int M = 200;

enum TimeOfLive {
    TIME_STONE = 500,
    TIME_PREY = 30,
    TIME_PREDATOR = 50
};
#endif  // INCLUDE_COMMON_H_
