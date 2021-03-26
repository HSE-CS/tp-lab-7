// Copyright 2021 Artem Danyaev
#pragma once

struct Pair {
  int x;  // 0..M-1
  int y;  // 0..N-1
};

const size_t N = 35;
const size_t M = 120;

const size_t numPreys = 100;
const size_t numPredators = 25;
const size_t numStones = 100;

const int preyLifetime = 10;
const int preyReprTime = 3;
const int predatorReprTime = 4;
const int predatorNeedFoodAfter = 5;
const int predatorLifetimeWithoutFood = 3;
