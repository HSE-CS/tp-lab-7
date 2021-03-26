// Copyright slavokeru	2021
#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_
#include"object.h"
class Prey : public Object {
public:
	unsigned int timeToReproduction;
	unsigned int timeLive;
	unsigned int reproduction;
public:
	Prey(Cell* newCell = nullptr);
	void live() override;
};

#endif  // INCLUDE_PREY_H_