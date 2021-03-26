// Copyright 2021 Bogomazov
#ifndef _COMMON_H_
#define _COMMON_H_

typedef size_t coord_t;

struct Pair {
    coord_t x;  // 0..M-1
    coord_t y;  // 0..N-1
};

const size_t N = 20;
const size_t M = 50;

const int M = 60;
const int N = 70;
const int number_objects = 3000;

const int probability_border_up = 60;
const int probability_border_down = 40;

#endif  //  _COMMON_H_
