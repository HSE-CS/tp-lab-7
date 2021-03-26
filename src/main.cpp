// Copyright 2020 Osmanov Islam
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "../include/ocean.h"

int main() {
    Ocean* ocean = new Ocean(0.05, 0.05, 0.05);
    ocean->print();
    ocean->run();
    return 0;
}
