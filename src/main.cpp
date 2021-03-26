// copyright 2021 Victor Shatilov

#include <iostream>

#include "../include/Ocean.h"

int main() {
    auto obj = new Ocean();
    obj->init(100, 150, 50);
    obj->run(100);
    return 0;
}
