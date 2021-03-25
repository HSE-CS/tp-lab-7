// Copyright 2021 MalininDmitry
#include <unistd.h>
#include <iostream>
#include "ocean.h"
#include "object.h"
#include "cell.h"
#include "stone.h"
#include "prey.h"
#include "common.h"

int main() {
    srand(0);
    Ocean oc1(25, 670, 49, 5, 2, 3, -3);
    oc1.print();
    std::cout << "-------" << std::endl;
    for (int i = 0; i < 1000; i++) {
        oc1.run();
        oc1.print();
        std::cout << "-------" << std::endl;
        usleep(1000000);
    }
    return 0;
}
