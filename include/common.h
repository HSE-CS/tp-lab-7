// Copyright 2021 VladimirUspensky

#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

#include <cstddef>
#include <random>


struct Pair {
    int x_coord;
    int y_coord;
};

const int N = 56;
const int M = 110;
const int ENTITY_CREATION = 5;
const int PREY_CREATION = 18;
const int PREDATOR_CREATION = 4;
const int STONE_CREATION = 45;
const int CORAL_CREATION = 30;
const int CORAL_AMOUNT = 32;
const int PREY_AMOUNT = 45;
const int PREDATOR_AMOUNT = 19;
const int LIVING_TIME_OF_CORAL = 4;
const int LIVING_TIME_OF_PREY = 3;
const int LIVING_TIME_OF_PREDATOR = 9;
const int PREDATOR_EATING_REWARD = 9;

#endif  // INCLUDE_COMMON_H_
