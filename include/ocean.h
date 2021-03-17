//  Copyright © 2021 Ksuvot. All rights reserved.

#ifndef _OCEAN_H_
#define _OCEAN_H_

#include "common.h"
#include "Cell.h"
#include <list>

class Ocean
{

private:
	Cell **cells;
	std::list<Object*> stuff;

public:
	Ocean();
	~Ocean();
	void print() const;
	void addObjects(...);
	void run();
};
#endif
