#include "object.h"

Object::Object(Cell* cell) { this->cell = cell; }

void Object::setCell(Cell* cell) { this->cell = cell; }

int Object::getLiveTime()
{ return this->livetime; }

Cell* Object::getCell() { return this->cell; }

bool Object::isLive() {
  if (this->dead == true) return false;
  return true;
}
void Object::setLive(int lifetime)
{
	this->livetime = lifetime;
}

void Object::readytodie()
{
	dead = true;
}

ObjType Object::getType() { return this->type; }
