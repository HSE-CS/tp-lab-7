#include "common.h"
#include "predator.h"

int main() {
    srand(time(nullptr));

    auto *ocean = new Ocean(25, 200);
    ocean->run();
}
