// Copyright 2021 Smirnov Grigory
#include "../include/ocean.h"
#include <iostream>

int main() {
	//Ocean O(30, 100);
	//O.fillAll(300, 1000, 100);

	Ocean O(5, 5);
	O.fillAll(0, 0, 3);
	O.print();
	//O.print();
	O.run();
	//O.print();
}
