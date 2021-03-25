// Copyright 2021 Tyulin Igor

#include "Stone.h"
Stone::Stone(Cell * c) :Object(c)
{
	this->lifetime = LTStone;
	type = ObjType::STONE;
};
void Stone::live()
{
	lifetime--;
};
char Stone::getSymbol()
{
	return STONE_N;
};

