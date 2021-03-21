// Copyright 2021 BekusovMikhail

#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

typedef size_t coord_t;

struct Pair {
    coord_t x;
    coord_t y;
};

const size_t N = 80;
const size_t M = 25;
const size_t quantity = 1000;

const size_t bounder1 = 13;
const size_t bounder2 = 20;

const size_t PreyLife = 9;
const size_t PreyBirth = 2;

const size_t PredatorLife = 4;
const size_t PredatorBirth = 12;
const size_t PredatorAdditionalTime = 1;
const size_t EatenPreysToBirth = 2;


#endif  // INCLUDE_COMMON_H_
