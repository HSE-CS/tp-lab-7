//  Copyright © 2021 Ksuvot
#include "Ocean.h"

int main() {
    Ocean ocean(40, 80);
    ocean.addObjects(60, 10, 5);
    ocean.run();
    ocean.print();
}
