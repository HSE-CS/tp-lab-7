// Copyright GN 2021
#ifndef _STONE_H_
#define _STONE_H_

#include "common.h"
#include "object.h"
#include "cell.h"
#include "ocean.h"

class Object;
class Stone : public Object {
 public:
  void setObjectType();
    void live();
    void printObject();
    void setCell(Cell* c);
    void init(Cell* c);
    int getObjectINT();
    char getObjectChar();
};


class Coral : public Object
{
private:
    size_t time_of_life = 1;

 public:
    void setObjectType();
    void live();
    void printObject();
    void setCell(Cell* c);
    void init(Cell* c);
    int getObjectINT();
    char getObjectChar();
};
#endif
