#include <iostream>

#include "../include/common.h"
#include "../include/ocean.h"

int main() {
  Ocean oc;
  oc.addObjects(100, ObjType::STONE);
  oc.addObjects(400, ObjType::PREY);
  oc.addObjects(200, ObjType::PREDATOR);
  oc.run();
  return 0;
}
