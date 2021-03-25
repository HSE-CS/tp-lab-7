// Copyright Gn 2021
#ifndef _CELL_H_
#define _CELL_H_

#include "common.h"
#include "Object.h"

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
	Pair getCoordinates();
	void setObject(Object*);
	void init(Pair p, Ocean* ocn);
	Object* getObject() const;
	Ocean* getOcean();
	void killMe(Object*);
	void delObj();
};
#endif
