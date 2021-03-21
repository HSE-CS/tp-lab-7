// Copyright 2021 BekusovMikhail

#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

typedef __size_t coord_t;

struct Pair {
    coord_t x;
    coord_t y;
};

const __size_t N = 80;
const __size_t M = 25;
const __size_t quantity = 1000;

const __size_t bounder1 = 13;
const __size_t bounder2 = 20;

const __size_t PreyLife = 9;
const __size_t PreyBirth = 2;

const __size_t PredatorLife = 4;
const __size_t PredatorBirth = 12;
const __size_t PredatorAdditionalTime = 1;
const __size_t EatenPreysToBirth = 2;


#endif  // INCLUDE_COMMON_H_
