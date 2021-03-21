// Copyright 2021 Rogov Andrey

#include <string>
#include "../include/ocean.h"

int main() {
	unsigned seed = 13;
	Ocean* my_ocean = new Ocean({ 20, 20 });
	my_ocean->createInitial(0.2, 0.025, 0.1, &seed);
	my_ocean->print();
	my_ocean->run();
}
