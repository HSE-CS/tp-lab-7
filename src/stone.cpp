#include "stone.h"
#include "cell.h"

Stone::Stone(Cell* _cell) {
    cell = _cell;
    type = ObjType::STONE;
    life = 100;
}
void Stone::live() {
    if (life == 0) {
        this->cell->killMe();
    }
    --life;
}
