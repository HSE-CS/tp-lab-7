// Copyright 2021 Tyulin Igor

#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_

#pragma once
#include "Object.h"
#include "Cell.h"
#include "Ocean.h"
#include "common.h"
class Predator : public Object
{
	friend Cell;
public:
	Predator(Cell * c);
	~Predator() {};
	void copulation();
	void live();
	void move();
	bool eat();
	char getSymbol() override;
};

#endif  // INCLUDE_PREDATOR_H_
