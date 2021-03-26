// Copyright [2020] <Olesya Nikolaeva>

#include <time.h>
#include "prey.h"
#include "cell.h"

void Prey::live() {
    move();
}

//0 - движется вверх, 1 - вправо, 2 - вниз, 3 - влево
void Prey::move() {
    unsigned int seed = time(NULL);
    bool repeat = true;
    while (repeat == true) {
        Pair initial = cell->returnLocation();
        int index = rand_r(&seed) % 4;
        switch (index) {
            case 0:
                initial = { initial.x - 1, initial.y };
                if ((initial.x > 0) && (cell->returnCellfromOcean(initial) == true)) {
                    cell->changeStatus(true);
                    this->setCell(cell->returnCellPointer(initial));
                    repeat = false;
                }
                break;
            case 1:
                initial = { initial.x, initial.y + 1 };
                if ((initial.y < M) && (cell->returnCellfromOcean(initial) == true)) {
                    cell->changeStatus(true);
                    this->setCell(cell->returnCellPointer(initial));
                    repeat = false;
                }
                break;
            case 2:
                initial = { initial.x + 1, initial.y };
                if ((initial.x < N) && (cell->returnCellfromOcean(initial) == true)) {
                    cell->changeStatus(true);
                    this->setCell(cell->returnCellPointer(initial));
                    repeat = false;
                }
                break;
            case 3:
                initial = { initial.x, initial.y - 1 };
                if ((initial.y > 0) && (cell->returnCellfromOcean(initial) == true)) {
                    cell->changeStatus(true);
                    this->setCell(cell->returnCellPointer(initial));
                    repeat = false;
                }
                break;
        }
    }
}

void Prey::spawn() {
    
}
