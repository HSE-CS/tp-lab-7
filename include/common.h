// Copyright 2021 SharunovEvgeny
//
// Created by sharg on 20.03.2021.
//
#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

#define STONE_N '#'
#define PREY_N 'f'
#define PREDATOR_N 'S'
#define EMPTY_N '~'

typedef int coord_t;

struct Pair {
  coord_t x;
  coord_t y;
};
const int LIFE_PREY_TIME = 2;
const int LIFE_PREDATOR_TIME = 6;

const int N = 30;
const int M = 30;



const int BREED_PREY_TIME = 4;
const int BREED_PREDATOR_TIME = 5;


#endif  //  INCLUDE_COMMON_H_
