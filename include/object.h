// Copyright 2020 GHA Test Team
#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "common.h"

#define STONE_N (char)254
#define EMPTY_CELL '~'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum class ObjType { STONE, PREY, PREDATOR };

class Cell;

class Object {
 protected:
	Cell* cell;
	ObjType obj_type;

 public:
	virtual ~Object() = default;
	virtual void live() = 0; // жизнь объекта
	void setCell(Cell*);
	Cell* getCell() const;
	ObjType getObjectType();
};
#endif  // INCLUDE_OBJECT_H_
