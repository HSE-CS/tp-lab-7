// Copyright 2021 by Sid

#include <iostream>
#include "Factory.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    srand(time(NULL));
    Ocean o(40, 80);
    o.addObjects(STONE, 300);
    o.addObjects(PREY, 1200);
    o.addObjects(PREDATOR, 400);
    o.shuffle();
    o.printOcean();
    while (o.getState()) {
        o.run();
        system("cls");
        o.printOcean();
    }
}
