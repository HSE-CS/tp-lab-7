#ifndef _OCEAN_H_
#define _OCEAN_H_


#include "common.h"

#include "Cell.h"
#include <list>
#include "object.h"

class Ocean
{
private:
	Cell** cells;
	list<Object*> stuff;

public:
	Ocean(float stone, float prey, float predator);
	~Ocean();
	Cell* find(Cell*);
	void print() const;
	void addObjects(Object* obj);
	void run();
};
#endif
