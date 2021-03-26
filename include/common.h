// Copyright 2020 Osmanov Islam
#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

#define STONE_N '#'
#define PREY_N 'f'
#define PREDATOR_N 'S'
#define EMPTY_N '-'

enum ObjType { PREY,
               CORAL,
               STONE,
               PREDATOR };

struct Pair {
    int x;
    int y;
};
const size_t N = 5;
const size_t M = 5;
#endif // INCLUDE_COMMON_H_
