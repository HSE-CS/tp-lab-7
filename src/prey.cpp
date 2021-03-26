// Copyright 2020 PollyllyZh
#include "object.h"
#include "prey.h"
#include "cell.h"
bool Prey::live() {
    if (!lifetime--) return false;
    move();

    if (repro_time == 0) {
        reproduce();
        repro_time = reproduce_time;
    }

    repro_time--;
    return true;
}
void Prey::move() {
    Cell* cell_ = cell->get_free_cell();
    if (cell_) {
        cell->set_object(nullptr);
        cell = cell_;
        cell_->set_object(this);
    }
}
void Prey::reproduce() {
    Cell* cell_ = cell->get_free_cell();
    if (cell_) {
        auto* offspring = new Prey(cell_);
        cell_->set_object(offspring);
        cell_->get_ocean()->add_stuff(offspring);
    }
}
char Prey::get_symbol() {
    return PREY_N;
}
