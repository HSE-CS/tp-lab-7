// Copyright 2021 Smirnov Grigory
#include "../include/stone.h"
#include "../include/cell.h"
#include <random>

Stone::Stone(Cell* c = nullptr) : Object(c) {
	std::random_device seed;
	durability = 10 + (seed() % 200);
}

void Stone::live() {
	durability--;
	if (durability <= 0) {
		cell->killMe();
		cell = nullptr;
	}
}
