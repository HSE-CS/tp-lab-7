//  Copyright 2021 Kartseva Masha
#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <ctime>
#include <iterator>
#include <algorithm>
#include <string>
#include <ctime>

typedef size_t coord_t;

struct Pair {
    int x;
    int y;
};

const int LTPrey = 20;
const int LTPredator = 30;
const int LTStone = 10000;


const size_t N = 20;
const  size_t M = 30;
