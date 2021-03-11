#include <iostream>

#include "ocean.h"
using namespace std;
int main() {
  Ocean *oc = new Ocean;
  oc->addObjects(250, ObjType::PREY);
  oc->addObjects(800, ObjType::PREDATOR);
  oc->addObjects(200, ObjType::STONE);
  oc->run();
  return 0;
}
