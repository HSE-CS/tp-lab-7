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
/*    ocean.addObjects(2,2,2,2);
    std::vector<Cell> a = ocean.getNearbyCells(2,3);
    for (auto j : a) {
        std::cout << (int)j.getObject()->getType() << std::endl;
        std::cout << j.getPair().x << " "<< j.getPair().y << std::endl;
    }*/
    ocean.run(2,2,2,2);
    return 0;
}