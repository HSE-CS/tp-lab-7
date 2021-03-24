// Copyright 2021 soda

#include "../include/stone.h"

// Stone

void Stone::set_time() {
    this->time = 1;
}

void Stone::set_objType() {
    this->objType = 0;
}

void Stone::setCell(Cell* c) {
    this->cell = c;
}

void Stone::init(Cell* c) {
    this->set_time();
    this->set_objType();
    this->setCell(c);
}

void Stone::live() {
    time++;
    if (time == 100000) {
        int res = rand_r(0) % 2;
        if (res) {
            time = 1;
        } else {
            this->die();
        }
    }
}

void Stone::die() {
    this->cell->killMe(this);
    this->objType = -1;
}

void Stone::print_object() {
    std::cout << STONE_N;
}

int Stone::get_objType() {
    return this->objType;
}

char Stone::get_info_object() {
    return STONE_N;
}


// Coral

void Coral::set_time() {
    this->time = 1;
}

void Coral::set_objType() {
    this->objType = 1;
}

void Coral::setCell(Cell* c) {
    this->cell = c;
}

void Coral::setReprod() {
    this->reprod_posib = rand_r(0) % 7 + 1;
}

void Coral::init(Cell* c) {
    this->set_time();
    this->set_objType();
    this->setCell(c);
    this->setReprod();
}

// If a free cell is found nearby, we try to add a new coral once
// every 150 years
void Coral::reproduction() {
    if (this->reprod_posib > 0) {
        if (this->time > 50) {
            Pair p = this->cell->getCord();
            int suc = 0;
            for (int n = -1; n <= 1; n++) {
                for (int m = -1; m <= 1; m++) {
                    p.i += n;
                    p.j += m;
                    if ((p.i < 0 || p.i > N - 1) ||
                        (p.j < 0 || p.j > M - 1)) {
                        p.i -= n;
                        p.j -= m;
                        continue;
                    }
                    Cell* now_cell = this->cell->getOcean()->get_cell(p);
                    if (now_cell->getObject() == nullptr) {
                        size_t* pos = this->getReprod();
                        (*pos)--;
                        Coral* new_coral = new Coral;
                        new_coral->init(now_cell);
                        now_cell->setObject(new_coral);
                        this->cell->getOcean()->addObject(new_coral);
                        suc++;
                        break;
                    } else {
                        p.i -= n;
                        p.j -= m;
                        continue;
                    }
                }
                if (suc) break;
            }
        }
    }
}

// The average life time of a corolla is 300 times, which is about
// reproducing 2 descendants,
// in general, the coral colony will grow slowly, but it is
// possible that the corals will die out.

void Coral::live() {
    size_t time_for_live = (rand_r(0) % 312) + 139;
    if (time <= time_for_live) {
        time++;
        if (time % 150 == 0)
            this->reproduction();
    } else {
        this->die();
    }
}

void Coral::die() {
    this->cell->killMe(this);
    this->objType = -1;
}

int Coral::get_objType() {
    return this->objType;
}

size_t* Coral::getReprod() {
    return &(this->reprod_posib);
}

void Coral::print_object() {
    std::cout << CORAL_N;
}

char Coral::get_info_object() {
    return CORAL_N;
}
