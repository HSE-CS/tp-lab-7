// Copyright 2021 Krayushkina
#pragma once

#include "Object.h"
#include "Cell.h"
#include "Ocean.h"
#include "common.h"
class Cell;
class Ocean;
class Prey : public Object
{
	friend Cell;
	friend Ocean;
public:
	Prey(Cell * c);
	~Prey() {};
	void live();
	void move();
	void copulation();
	char getSymbol() override;
};