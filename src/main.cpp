#include <iostream>

#include "ocean.h"
using namespace std;
int main() {
  Ocean *oc = new Ocean;
  oc->addObjects(1, ObjType::PREY);
  oc->addObjects(1, ObjType::PREDATOR);
  oc->addObjects(0, ObjType::STONE);
  oc->run();
  return 0;
}
