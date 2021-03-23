// Copyright 2021 Dmitry Vargin
#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <cmath>
#include <utility>

enum class ObjectType {
    STONE = -1,
    OBJECT = 0,
    PREY = 1,
    PREDATOR = 2,
};

const int ObjectTypeLen = 4;

#endif  // INCLUDE_COMMON_H_
