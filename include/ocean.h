#ifndef _OCEAN_H_
#define _OCEAN_H_

#include "common.h"
#include "cell.h"

class Ocean
{
private:
	std::vector<std::vector<Cell *>> cells;
	std::list<Object*> stuff;

public:
	Ocean(unsigned int x_len, unsigned int y_len);
	~Ocean();
	void print() const;
	void addObjects(std::list<Object *> lst);
	void run();
	Cell *get(unsigned int x, unsigned int y);
	unsigned int lenX();
    unsigned int lenY();
    Object *removeFromStuff(Object *obj);
};

#endif // _OCEAN_H_
