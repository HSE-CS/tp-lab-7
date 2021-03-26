// Copyright 2021 Artem Danyaev
#pragma once

struct Pair {
  int x;  // 0..M-1
  int y;  // 0..N-1
};

const int N = 35;
const int M = 120;

const int numPreys = 100;
const int numPredators = 25;
const int numStones = 100;

const int preyLifetime = 10;
const int preyReprTime = 3;
const int predatorReprTime = 4;
const int predatorNeedFoodAfter = 5;
const int predatorLifetimeWithoutFood = 3;
