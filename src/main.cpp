#include <iostream>

#include "ocean.h"
using namespace std;
int main() {
  Ocean *oc = new Ocean;
  oc->addObjects(700, ObjType::PREY);
  oc->addObjects(1500, ObjType::PREDATOR);
  oc->addObjects(200, ObjType::STONE);
  oc->run();
  return 0;
}
