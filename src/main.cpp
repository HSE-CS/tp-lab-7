#include "common.h"
#include "predator.h"

int main() {
    srand(time(nullptr));
    auto *ocean = new Ocean(70, 70);
    ocean->run();
}
