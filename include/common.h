// Copyright 2020 PollyllyZh
#pragma once
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <string>
#include <vector>
#include <ctime>
#include <time.h>

typedef unsigned int uint;
typedef size_t coord_t;

struct Pair {
    size_t x; // 0..M-1
    size_t y; // 0..N-1
};

const size_t N = 40;
const size_t M = 40;

const uint attempts = 7;
const uint reproduce_time = 4;

const uint prey_lim = 13;
const uint predator_lim = 7;
const uint stone_lim = 500;
