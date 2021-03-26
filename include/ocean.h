#ifndef _OCEAN_H_
#define _OCEAN_H_


#include "common.h"

#include "Cell.h"
#include <list>

class Ocean
{
private:
	Cell** cells;
	std::list<Object*> stuff;

public:
	Ocean(float prey, float predator, float stone);
	~Ocean();
	Cell* find();
	void print() const;
	void addObjects(Object* obj);
	void run();
};
#endif
