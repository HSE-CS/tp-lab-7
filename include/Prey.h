//  Copyright 2021 GHA created by Klykov Anton

#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include "Object.h"
//#include "Ocean.h"
#include <iostream>
#include <string>
#include <algorithm>

class Prey : public Object {
 protected:
  int lifeTime;
  int reproduceTime;
  std::string p_name;

 public:
  ~Prey() override;
  Prey(std::string name, int life,
       int reproduce, Cell* cell);
  void live() override;
  std::string getName() override;
};

#endif
