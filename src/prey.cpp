// Copyright dmitrycvetkov 2021
#include "prey.h"
#include "cell.h"
#include "object_factory.h"

#include <algorithm>
#include <vector>

Prey::Prey(std::weak_ptr<Cell> cell) : Object(cell),
reproductionTimer {REPRODUCTION_TIMER}, age {} {
}

void Prey::live() {
    auto oldCell = move();
    reproductionTimer = (std::max)(std::size_t{}, reproductionTimer - 1);  // NOLINT
    if (!reproductionTimer && oldCell) {
        reproductionTimer = REPRODUCTION_TIMER;
        reproduce(oldCell);
    }
    if (++age == MAX_PREY_AGE)
        die();
}

ObjType Prey::type() const {
    return ObjType::PREY;
}

void Prey::reproduce(const std::shared_ptr<Cell> &cell) {
    std::shared_ptr<Object> child = createObject(type(), cell);
    cell->initChild(child);
}

void Prey::die() {
    cell.lock()->killMe();
}

std::shared_ptr<Cell> Prey::move() {
    std::vector<std::weak_ptr<Cell>> adjacent = cell.lock()->getAdjacent();
    adjacent.erase(std::remove_if(adjacent.begin(), adjacent.end(),
        [](std::weak_ptr<Cell> cell) -> bool {
            return cell.lock()->getObject().get();
        }),
        adjacent.end());
    if (!adjacent.empty()) {
        auto oldCell = this->cell.lock();
        moveToCell(*select_randomly(adjacent.begin(), adjacent.end()));
        return oldCell;
    } else {
        return {};  // NOLINT
    }
}
