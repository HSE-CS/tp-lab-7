// Copyright 2021 Schenikova

#include "predator.h"
#include "prey.h"
#include "ocean.h"
#include "stone.h"
#include <vector>

int main() {
    Ocean* ocean = new Ocean;
    std::vector<Object*> objects;
    for (size_t i = 0; i < 200; i++) {
        objects.push_back(new Prey);
        objects.push_back(new Stone);
        objects.push_back(new Predator);
    }
    
    // for (size_t i = 0; i < 20; i++) {
        ocean->addObjects(objects);
    // }

    
    ocean->run();
}


