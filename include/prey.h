// Copyright 2021 Artem Danyaev
#pragma once

#include "../include/object.h"

class Prey : public Object {
 private:
	int lifetime = preyLifetime;
	int reprTime = preyReprTime;

 public:
	Prey(Cell* c = nullptr);
	void live();
};
