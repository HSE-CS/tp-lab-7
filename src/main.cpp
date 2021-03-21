#include "common.h"

int main() {
    srand(time(nullptr));

    std::list<int> l1 = {1, 2, 3, 4, 5}, l2 = {6, 7, 8};
    l1.insert(l1.end(), l2.begin(), l2.end());
    for (const auto x : l1)
        std::cout << x << " ";
}
