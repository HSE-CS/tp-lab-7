#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "common.h"

#define STONE_N '#'
#define CORAL_N '*'
#define PREY_N 'f'
#define PREDATOR_N 'S'
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
	virtual void live() = 0; // ����� �������
	virtual void print_object() = 0;
	void setCell(Cell* cl);
};
#endif
