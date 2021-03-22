// Copyright 2021 Smirnov Grigory
#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include "common.h"
#include "object.h"

class Ocean;
class Cell
{
	friend Ocean;
private:
	Pair crd;
	Object* obj;
	Ocean* ocean;
public:
	explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr) :
		crd(p),
		obj(nullptr),
		ocean(oc) {}

	void init(Pair p, Ocean* oc);
	Object* getObject() const;
	void setObject(Object* o);
	void setNull();
	//Ocean* getOcean() { return ocean; };

	Cell* getTop();
	Cell* getBot();
	Cell* getLeft();
	Cell* getRight();
};

#endif // INCLUDE_CELL_H_
