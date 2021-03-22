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
	void print();
    void addObject(Object * object);
	void addObjects(std::list<Object *> lst);
	void run();
	Cell *get(unsigned int x, unsigned int y);
    void setObjectOnCell(Object *object, Cell *cell);
    void setObjectOnCell(Object *object, int i, int j);
	unsigned int lenX();
    unsigned int lenY();
    Object *removeFromStuff(Object *obj);
    std::map<ObjectType, unsigned int> getObjectsCount();
};

#endif // _OCEAN_H_
