// Copyright 2021 Schenikova
#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include "common.h"
#include "ocean.h"

#define STONE_N '#'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum class ObjType {STONE,CORAL,PREY,PREDATOR};

class Object;
class Ocean;
class Prey;
class Predator;

class Cell {
  friend Ocean;
  friend Prey;
  friend Predator;
 private:
	Pair coords;
	Object *object;
	Ocean *ocean;
 public:
	explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr) :
		coords(p),
		object(nullptr),
		ocean(oc) {}
	void init(Pair p, Ocean* oc);
	Object* getObject() const;
	void setObject(Object* );
	void killMe();
};

class Object {
 protected:
	Cell *cell;
 public:
	Object(Cell *myCell = nullptr) :
    cell(myCell) {}
	virtual ~Object() {}
	virtual void live() = 0; // жизнь объекта
	virtual bool IsPrey() {return false;}
	virtual bool IsPredator() {return false;}
	void setCell(Cell*);
  virtual void printInfo() = 0;
};
#endif  // INCLUDE_CELL_H_
