// Copyright 2021 by me
#include <iostream>

#include "../include/common.h"
#include "../include/ocean.h"

int main() {
  Ocean oc;
  oc.addObjects(1000, ObjType::STONE);
  oc.addObjects(3000, ObjType::PREY);
  oc.addObjects(1500, ObjType::PREDATOR);
  oc.run();
  return 0;
}
