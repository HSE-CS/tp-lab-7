//  Copyright 2021 GHA created by Klykov Anton

#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_

#include "Prey.h"
#include <queue>

class Predator : public Prey {
 protected:
  int eatTime;
  std::string p_name;
  bool DoEat{false};

 public:
  ~Predator() override;
  Predator(std::string name, std::string pre_name,
           int eat, int life, int reproduce, Cell* cell);
  void live() override;
  std::string getName() override;
};

#endif
