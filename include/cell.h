// Copyright 2021 Artem Danyaev
#pragma once

#include "../include/common.h"
#include "../include/object.h"
#include "../include/ocean.h"

class Ocean;
class Object;
class Cell {
	friend Ocean;

 private:
	Pair crd;
	Object* obj = nullptr;
	Ocean* ocean;

 public:
	explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr);
	void init(Pair p, Ocean* oc);
	Object* getObject() const;
	void setObject(Object* o);
	Pair getCoords();
	Ocean* getOcean();
	// void killMe();
};
