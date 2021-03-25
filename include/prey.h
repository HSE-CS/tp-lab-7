// Copyright GN 2021

#ifndef _PREY_H_
#define _PREY_H_
INCLUDE_PREY_H_
#include "common.h"
#include "Object.h"
#include "cell.h"
#include "ocean.h"

// class Predator;
// class Object;
class Prey : public Object{
 protected:
    int time_of_life = 1;

 public:
    virtual void move();
  virtual void die();
    virtual void live();
  virtual void setObjectType();
    virtual void reproduction();
  virtual void printObject();
    virtual void setCell(Cell* c);
  virtual void init(Cell* c);
    virtual int getObjectINT();
  virtual char getObjectChar();
};
#endif  // INCLUDE_PREY_H_
