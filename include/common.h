// Copyright 2021 ArinaMonicheva

#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

typedef size_t coord_t;

typedef struct Coords {
  coord_t x;  // 0..M-1
  coord_t y;  // 0..N-1
} coords;

const size_t N = 50;
const size_t M = 200;

#endif  // INCLUDE_COMMON_H_
