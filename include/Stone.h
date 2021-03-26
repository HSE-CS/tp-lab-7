// Copyright 2021 Krayushkina
#pragma once

#include "Object.h"
#include "Cell.h"
#include "Ocean.h"
#include "common.h"
class Stone : public Object
{
	friend Cell;
public:
	Stone(Cell * c);
	~Stone() {};
	void live();
	char getSymbol() override;
};