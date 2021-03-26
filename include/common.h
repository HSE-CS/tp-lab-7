// Copyright 2021 Bogomazov
#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

struct Pair {
    int x;  // 0..M-1
    int y;  // 0..N-1
};

const int M = 60;
const int N = 70;
const int number_objects = 3000;

const int probability_border_up = 60;
const int probability_border_down = 40;

#endif  // INCLUDE_COMMON_H_
