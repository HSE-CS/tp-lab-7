// Copyright 2021 Stifeev Nikita

#include <iostream>
#include <ctime>
#include "../include/ocean.h"
using std::cout;
using std::endl;

int main() {
    srand(unsigned(time(0)));
    Ocean* ocean = new Ocean();
    ocean->addObjects(ObjType::STONE, 400);
    ocean->addObjects(ObjType::PREDATOR, 60);
    ocean->addObjects(ObjType::PREY, 30);
    ocean->print();
    ocean->run();
    ocean->print();
}
