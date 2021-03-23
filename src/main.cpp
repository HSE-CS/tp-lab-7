// Copyright <Roman Balayan> @ 2021

#include <time.h>
#include <iostream>
#include <memory>

#include "../include/ocean.h"

int main() {
    srand(time(0));

    std::shared_ptr<Ocean> ocean = std::make_shared<Ocean>();
    ocean->addObjects();
    ocean->run();

    return 0;
}
