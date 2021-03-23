// Copyright 2021 Dmitry Vargin
#include "../include/common.h"
#include "../include/predator.h"

int main() {
    auto *ocean = new Ocean(25, 200);
    ocean->run();
}
