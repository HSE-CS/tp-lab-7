#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "common.h"

#define STONE_N '#'
#define CORAL_N '*'
#define PREY_N 'O'
#define PREDATOR_N '0'
#define WALL_NW '|'
#define WALL_NG '~'

enum class ObjType { STONE, CORAL, PREY, PREDATOR, WALL_W, WALL_G };

class Cell;
class Object
{
protected:
	Cell* cell;
	int objType;
public:
	Object() {
		cell = nullptr;
		objType = -1;
	}
	~Object() {
		cell = nullptr;
		objType = -1;
	};
	virtual void live() = 0; // жизнь объекта
	virtual void print_object() = 0;
	virtual char get_info_object() = 0;
	void setCell(Cell* cl);
	virtual int get_objType() = 0;
};
#endif
