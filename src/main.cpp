// Copyright 2021 Ilya Urtyukov
#include <iostream>
#include <cstdlib>
#include <list>

#include "cell.h"
#include "ocean.h"
#include "predator.h"
#include "prey.h"
#include "stone.h"
#include "common.h"



int main() {
    Ocean a(20, 40);
    a.addObjects(60, 20, 10);
    int PreyCounter = 0;
    int PredatorCounter = 0;
    for (int i = 0; i < 100; ++i) {
        a.run();
        a.print();
        for (Object* obj : a.getStuff()) {
            if (obj->getType() == ObjType::PREY)
                ++PreyCounter;
            else if (obj->getType() == ObjType::PREDATOR)
                ++PredatorCounter;
        }
        std::cout << PreyCounter << "-----" << PredatorCounter << std::endl;
        std::cout << i << std::endl;
        if (!PreyCounter) {
            std::cout << "There's no more preyers" << std::endl;
            break;
        } else if (!PredatorCounter) {
            std::cout << "There's no more predators" << std::endl;
            break;
        }
        PredatorCounter = 0;
        PreyCounter = 0;
    }
}
