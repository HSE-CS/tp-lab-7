//  Copyright 2021 Nikita Naumov
#ifndef INCLUDE_COMMON_H
#define INCLUDE_COMMON_H

typedef size_t coord_t;

struct Pair {
    coord_t x; // 0..M-1
    coord_t y; // 0..N-1
};

const size_t N = 20;
const size_t M = 50;

#endif  //  INCLUDE_COMMON_H
