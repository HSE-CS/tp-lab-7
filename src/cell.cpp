#include "cell.h"

void Cell::init(Pair p, Ocean* oc)
{
  crd = p;
  ocean = oc;
}

Object* Cell::getObject() const
{
  return obj;
}

void Cell::setObject(Object* o)
{
  obj = o;
}

void Cell::killMe()
{
  this->obj->setCell(nullptr);
}

Cell& Cell::getN(int row, int column)
{
    // TODO: вставьте здесь оператор return
}
