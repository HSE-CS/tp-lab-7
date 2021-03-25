// Copyright NikDemoShow 2021
#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_
#include"prey.h"
class Predator : public Prey {
 private:
  static const unsigned int fullWeelFed{ 7 };
  unsigned int weelFed;
 public:
  explicit Predator(Cell* newCell = nullptr);
  void live() override;
};
#endif  // INCLUDE_PREDATOR_H_
