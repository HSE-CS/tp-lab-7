// Copyright 2020 Konina Tatiana
#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_


typedef size_t coord_t;

struct Pair {
	int x;
	int y;
};

const size_t N = 50;
const size_t M = 200;

enum TimeOfLive {
	TIME_STONE = 1000,
	TIME_PREY = 20, TIME_PREDATOR = 30
};
#endif  // INCLUDE_COMMON_H_








