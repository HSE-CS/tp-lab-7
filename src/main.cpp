#include "ocean.h"
#include "cell.h"
#include <iostream>
#include <string>
#include <fstream>

int main() {
  Ocean* ocean = new Ocean(0.2, 0.2, 0.1);
  ocean->print();
}