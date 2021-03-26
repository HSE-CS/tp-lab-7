// Copyright 2021 Nikolaev Ivan

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include "ocean.h"


int main() {
    setlocale(LC_ALL, "");
    Ocean ocean(30, 120, 2800, 400, 250);
    ocean.addObjects();
    ocean.run();
    return 0;
}
