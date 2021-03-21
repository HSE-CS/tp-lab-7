// Copyright 2021 BekusovMikhail

#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

struct Pair {
    unsigned int x;
    unsigned int y;
};

const unsigned int N = 80;
const unsigned int M = 25;
const unsigned int quantity = 1000;

const unsigned int bounder1 = 13;
const unsigned int bounder2 = 20;

const unsigned int PreyLife = 9;
const unsigned int PreyBirth = 2;

const unsigned int PredatorLife = 4;
const unsigned int PredatorBirth = 12;
const unsigned int PredatorAdditionalTime = 1;
const unsigned int EatenPreysToBirth = 2;


#endif  // INCLUDE_COMMON_H_
