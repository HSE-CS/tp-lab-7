#include "..\include\cell.h"

void Cell::init(Pair p, Ocean* oc) {
  crd = p;
  ocean = oc;
}

Object* Cell::getObject() const { return obj; }

Ocean* Cell::getOcean() { return ocean; }

void Cell::setObject(Object* ob) { this->obj = ob; }

void Cell::print() {
  if (obj) {
    obj->print();
  } else {
    std::cout << '.';
  }
}

void Cell::killMe(){
  delete obj;
  this->obj = nullptr;
}
Pair Cell::getCoord() { return crd; };
