#include "../include/stone.h"

Stone::Stone(Cell* cell_) : Object(cell_, ObjType::STONE){};

void Stone::live() { return; }
