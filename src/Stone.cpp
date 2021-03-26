// Copyright JMax 2021

#include "../include/Stone.h"

void Stone::live() {
    if (isAlive()) {
        increaseAge();
        if (!checkAge()) {
            death();
        }
    }
}

bool Stone::checkAge() {
    return age < deathAge;
}
