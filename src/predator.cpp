// Copyright [2020] <Olesya Nikolaeva>

#include "predator.h"
#include "cell.h"
#include "ocean.h"

void Predator::live() {
    move();
}

void Predator::move() {
    if ((hungrydays == 0)&&(timetospawn > TIME_TO_SPAWN_PREDATOR)) {
        spawn();
        timetospawn = 0;
    } else if (cell->findingPreys() == true) {
        hungrydays = 0;
        lifetimeCheck();
    } else {
        cell->movingtoNeighborhood();
        lifetimeCheck();
    }
}

void Predator::spawn() {
    Pair initial = cell->returnLocation();
    if (cell->movingtoNeighborhood() == false) {
      return;
    }
    Object* minishark = new Prey(cell->returnCellPointer(initial), ObjType::PREDATOR);
    cell->returnCellPointer(initial)->setObject(minishark);
    cell->returnOcean()->addObjects(minishark);
}

void Predator::lifetimeCheck() {
    lifetime++;
    timetospawn++;
    if (lifetime > LIFE_TIME_PREY) {
        cell->die();
    }
}
