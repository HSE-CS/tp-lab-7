// Copyright 2020 PollyllyZh
#include "common.h"
#include "cell.h"
#include "object.h"
#include "predator.h"
bool Predator::live() {
    if (!lifetime--) return false;

    yum = eatTo();
    repro_time--;

    if (yum && repro_time == 0) {
        reproduce();
        repro_time = reproduce_time;
    }

    if (repro_time == 0)
        repro_time = reproduce_time;

    return true;
}
void Predator::move() {
    Cell* cell_ = cell->get_free_cell();
    if (cell_) {
        cell->set_object(nullptr);
        cell = cell_;
        cell_->set_object(this);
    }
}
void Predator::reproduce() {
    Cell* cell_ = cell->get_free_cell();
    if (cell_) {
        auto* offspring = new Predator(cell_);
        cell_->set_object(offspring);
        cell_->get_ocean()->add_stuff(offspring);
    }
}
char Predator::get_symbol() {
    return PREDATOR_N;
}
bool Predator::eatTo() {
    Cell* goal = cell->get_prey();
    if (goal) {
        goal->get_object()->set_lifetime(0);
        return true;
    }
    return false;
}
