//  Copyright © 2021 Ksuvot
#include "Stone.h"

void STONE::live() {
  speed -= std::rand() % 1;
    if (speed == 0) {
        cell->setObject(nullptr);
    }
}
