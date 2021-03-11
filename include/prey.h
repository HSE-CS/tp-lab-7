#ifndef _PREY_H_
#define _PREY_H_

#include "cell.h"
#include "common.h"
#include "object.h"
#include "ocean.h"
class Cell;
class Ocean;

class Prey : public Object {
  friend class Cell;
  friend class Ocean;

 public:
  Prey(Cell *cell);
  ~Prey();
  void live() override;
  void move();
  void copulation();
  char getSymbol() override;
};
#endif
