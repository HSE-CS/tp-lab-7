#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_

#include "../include/cell.h"
#include "../include/prey.h"
class Predator : public Prey {
 public:
  explicit Predator(Cell *cell);
  void live() override;
  void reproduce() override;
};

#endif  // INCLUDE_PREDATOR_H_