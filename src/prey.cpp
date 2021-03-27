// Copyright [2020] <Olesya Nikolaeva>

#include "prey.h"
#include "cell.h"
#include "ocean.h"

void Prey::live() {
    move();
}

void Prey::move() {
    if (timetospawn > TIME_TO_SPAWN_PREY) {
        spawn();
        timetospawn = 0;
    } else {
        cell->movingtoNeighborhood();
        lifetimeCheck();
    }
}

void Prey::spawn() {
    Pair initial = cell->returnLocation();
    if (cell->movingtoNeighborhood() == false) {
      return;
    }
    Object* minifish = new Prey(cell->returnCellPointer(initial), ObjType::PREY);
    cell->returnCellPointer(initial)->setObject(minifish);
    cell->returnOcean()->addObjects(minifish);
}

void Prey::lifetimeCheck() {
    lifetime++;
    timetospawn++;
    if (lifetime > LIFE_TIME_PREY) {
        cell->die();
    }
}
