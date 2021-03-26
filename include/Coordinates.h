// Copyright 2021 by Sid

#ifndef Coordinates_h
#define Coordinates_h
#include <vector>

typedef size_t coord_t;

struct Point {
    coord_t x, y;

    Point(coord_t x, coord_t y) : x(x), y(y) {}
};

#endif /* Coordinates_h */
