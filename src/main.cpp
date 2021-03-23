// Copyright 2021 Khoroshavina Ekaterina
#include <iostream>
#include "ocean.h"

int main() {
    Ocean* oc = new Ocean;
    oc->makeOcean(100, 50, 100);
    oc->run();
    return 0;
}