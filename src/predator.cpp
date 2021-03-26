// Copyright dmitrycvetkov 2021
#include "predator.h"

#include "cell.h"

#include <algorithm>

Predator::Predator(std::weak_ptr<Cell> cell)
    : Prey(cell), health { MAX_PREDATOR_HEALTH } {
}

void Predator::live() {
    if (!hunt()) {
        --health;
        if (!health) {
            die();
        } else {
            Prey::live();
        }
    } else {
        health = (std::min)(health + 1, MAX_PREDATOR_HEALTH);
        Prey::live();
    }
}

void Predator::reproduce(const std::shared_ptr<Cell>& cell) {
    if (health > 1)
        Prey::reproduce(cell);
}

bool Predator::hunt() {
    auto adjacent = cell.lock()->getAdjacent();
    adjacent.erase(std::remove_if(adjacent.begin(), adjacent.end(),
        [](std::weak_ptr<Cell> cell) {
            auto object = cell.lock()->getObject();
        return !(object && object->type() == ObjType::PREY);
        }),
        adjacent.end());
    if (!adjacent.empty()) {
        std::weak_ptr<Cell> preyCell = *select_randomly(adjacent.begin(),
            adjacent.end());
        preyCell.lock()->killMe();
        moveToCell(preyCell);
        return true;
    } else {
        return false;
    }
}

ObjType Predator::type() const {
    return ObjType::PREDATOR;
}
