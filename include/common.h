#ifndef TP_LAB_7_COMMON_H
#define TP_LAB_7_COMMON_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <cmath>
#include <unistd.h>

#include <stdio.h>
#include <stdarg.h>

enum class ObjectType {
    STONE = -1,
    OBJECT = 0,
    PREY = 1,
    PREDATOR = 2,
};

const int ObjectTypeLen = 4;

const std::size_t N = 20;
const std::size_t M = 50;

#endif //TP_LAB_7_COMMON_H
