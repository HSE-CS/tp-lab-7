//  Copyright 2021 Nikita Naumov

#include "../include/ocean.h"
#include "../include/cell.h"
#include "../include/Object.h"
#include "../include/stone.h"
#include "../include/prey.h"
#include "../include/predator.h"
#include "../include/common.h"

int main() {
    srand(time(NULL));
    Ocean ocean;
    ocean.run(2,2,2,2);
    return 0;
}