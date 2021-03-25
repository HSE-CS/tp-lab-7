//  Copyright 2021 Nikita Naumov

#include "../include/ocean.h"
#include "../include/cell.h"
#include "../include/Object.h"
#include "../include/stone.h"
#include "../include/prey.h"
#include "../include/predator.h"

int main() {

    Ocean ocean;
    ocean.print();
    //ocean.addObjects();
    ocean.run();
    return 0;
}