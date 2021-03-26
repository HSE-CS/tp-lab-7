#include "object.h"

Object::Object(ObjType type, Cell* cell)
{
  this->type = type;
  this->cell = cell;
}

void Object::setCell(Cell* cell)
{
  this->cell = cell;
}

void Object::move()
{

}

Cell* Object::getCell()
{
  return cell;
}

void Object::die()
{
  dead = true;
  cell = nullptr;
}

ObjType Object::getType()
{
  return type;
}
