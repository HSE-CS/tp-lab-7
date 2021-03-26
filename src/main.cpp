// Copyright dmitrycvetkov 2021
#include "ocean.h"

int main() {
    auto ocean = std::make_unique<Ocean>();
    ocean->addObjects(900);
    ocean->print();
    ocean->run(100);
}
