// Copyright 2021 Krayushkina
#include <iostream>
#include "../include/ocean.h"
int main() {
    Ocean * oc = new Ocean;
    oc->addObjects(40, ObjType::PREY);
    oc->addObjects(10, ObjType::PREDATOR);
    oc->addObjects(10, ObjType::STONE);
    oc->run();
    system("pause");
    return 0;
}
