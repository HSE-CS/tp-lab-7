#include <iostream>

#include "ocean.h"
using namespace std;
int main() {
  Ocean *oc = new Ocean;
  oc->addObjects(40, ObjType::PREY);
  oc->addObjects(10, ObjType::PREDATOR);
  oc->addObjects(10, ObjType::STONE);
  oc->run();
  return 0;
}
