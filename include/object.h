//// Copyright 2021 Lukicheva Polina

#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "common.h"

#define STONE_N '#'
#define CORAL_N '*'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum class ObjType { STONE, CORAL, PREY, PREDATOR };

class Cell;
class Object
{
protected:
	Cell* cell;
	ObjType type;
	size_t lifeTime;
public:
	explicit Object(Cell* cl = nullptr);
	virtual ~Object();
	virtual void live() = 0; // жизнь объекта
	void setCell(Cell*);
	virtual Cell* getCell();
	virtual ObjType getType();
};
#endif