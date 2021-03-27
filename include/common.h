//  Copyright 2021 Nikita Naumov
#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_
#include <typeinfo>
#include <cstdlib>
#include <ctime>

typedef size_t coord_t;

struct Pair {
    coord_t x;  //  0..M-1
    coord_t y;  //  0..N-1
};

const size_t N = 10;
const size_t M = 10;

#define coralTime 5
#define preyLifespan 40
#define preyBreedtime 20
#define preyBreedCooldown 10
#define predatorFullnessToBreed 70
#define predatorBreedtime 7
#define predatorFullnessAfterBreed 15
#define maxPredatorFullness 30
#endif  //  INCLUDE_COMMON_H_
