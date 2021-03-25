// Copyright 2021 Tyulin Igor
#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <ctime>
#include <time.h>
#include <iterator>
#include <algorithm>
#include  <string>

typedef size_t coord_t;

struct Pair
{
	int x; 
	int y; 
};

const int LTPrey = 600;
const int LTPredator = 200;
const int LTStone = 10000;


const size_t N = 20;
const  size_t M = 50;

#endif  // INCLUDE_COMMON_H_
