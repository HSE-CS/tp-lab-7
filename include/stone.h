#ifndef _STONE_H_
#define _STONE_H_

#include "cell.h"
#include "common.h"
#include "object.h"
#include "ocean.h"
class Stone : public Object {
  friend Cell;

 public:
  Stone(Cell *c);
  ~Stone(){};
  void live() override;
  char getSymbol() override;
};
#endif
