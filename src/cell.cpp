//// Copyright 2021 Lukicheva Polina
#include "../include/cell.h"
#include "../include/object.h"

void Cell::init(Pair p, Ocean* oc)
{
  crd = p;
  ocean = oc;
}

Object* Cell::getObject() const
{
  return obj;
}

Ocean* Cell::getOcean() const
{
  return ocean;
}

void Cell::setObject(Object* o)
{
  obj = o;
}

int Cell::getX() const
{
  return crd.x;
}

int Cell::getY() const
{
  return crd.y;
}

void Cell::killMe()
{
  this->obj->setCell(nullptr);
}

bool Cell::isEmpty() const
{
  return obj == nullptr;
}

