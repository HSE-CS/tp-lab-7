// Copyright 2021 Tyulin Igor

#include <iostream>
#include "Ocean.h"
int main() {
    Ocean *oc = new Ocean;
    oc->addObjects(400, ObjType::PREY);
    oc->addObjects(100, ObjType::PREDATOR);
    oc->addObjects(150, ObjType::STONE);
    oc->run();
    return 0;
}
