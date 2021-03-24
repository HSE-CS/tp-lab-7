// Copyright 2021 Kasyanov
#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include <list>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "common.h"
#include "cell.h"
#include "prey.h"
#include "predator.h"

class Ocean {
    friend Prey;
    friend Predator;

 private:
    Cell **cells;

 public:
    Ocean();

    ~Ocean();

    ObjType getNear(int, int) const;

    void print() const;

    void addObjects();

    void run();
};

#endif // INCLUDE_OCEAN_H_
