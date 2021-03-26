#include <iostream>

#include "../include/common.h"
#include "../include/ocean.h"

int main() {
  Ocean oc;
  oc.addObjects(4, ObjType::STONE);
  oc.addObjects(4, ObjType::PREY);
  std::vector<Cell*> thing(oc.emptyCells(Pair{2,2}));
  for (auto i : thing) {
  }
  oc.print();
  return 0;
}