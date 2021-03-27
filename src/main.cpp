// Copyright [2020] <Olesya Nikolaeva>

#include "predator.h"
#include "cell.h"
#include "ocean.h"

int main() {
    Ocean *ocean = new Ocean();
    ocean->createOcean(100, 20, 10);
    ocean->print();
    ocean->run();
    return 0;
}
