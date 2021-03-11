#include "object.h"

Object::Object(Cell* cell) { this->cell = cell; }

void Object::setCell(Cell* cell) { this->cell = cell; }


Cell* Object::getCell() { return this->cell; }

bool Object::isLive() {
  return dead;
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

unsigned int Object::getLive()
{
	return livetime;
}
