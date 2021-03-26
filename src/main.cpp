// Copyright 2020 PollyllyZh
#include "../include/ocean.h"
int main() {
    Ocean ocean;
    Ocean* pOcean = &ocean;
    pOcean->add_objects(ObjType::STONE, 50);
    pOcean->add_objects(ObjType::PREY, 130);
    pOcean->add_objects(ObjType::PREDATOR, 20);

    std::cout << "\n\n" << std::endl;

    for (int i = 0; i < attempts; i++) {
        pOcean->run();
        std::cout << "\n" << std::endl;
        pOcean->print();
    }
    delete pOcean;
    return 0;
}
