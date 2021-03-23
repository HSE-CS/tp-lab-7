#include "common.h"
#include "predator.h"

int main() {
    srand(time(nullptr));
    auto *ocean = new Ocean(1, 2);
    ocean->run();
}
