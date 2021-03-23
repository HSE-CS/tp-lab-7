// Copyright 2021 valvarl

#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

#include <cstddef>
#include <random>
// #include <chrono>

typedef size_t coord_t;

struct Pair {
    coord_t x;
    coord_t y;
};

const size_t N = 43;
const size_t M = 119;

const size_t STONE_SPAWN_PROBABILITY = 37;
const size_t CORAL_SPAWN_PROBABILITY = 33;
const size_t PREY_SPAWN_PROBABILITY = 20;
const size_t PREDATOR_SPAWN_PROBABILITY = 8;

const size_t CORAL_GENERATE_PROBABILITY = 52;
const size_t PREY_GENERATE_PROBABILITY = 43;
const size_t PREDATOR_GENERATE_PROBABILITY = 21;

const size_t CORAL_LIFE_DURATION = 5;
const size_t PREY_LIFE_DURATION = 4;
const size_t PREDATOR_LIFE_DURATION = 8;

const size_t  ENTITY_SPAWN_PROBABILITY = 4;

const size_t PREDATOR_EATING_REWARD = 6;

#endif  // INCLUDE_COMMON_H_
