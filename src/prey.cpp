// Copyright 2021 soda

#include "prey.h"
#include "object.h"

void Prey::set_time() {
    this->time = 1;
}

void Prey::set_objType() {
    this->objType = 2;
}

void Prey::setCell(Cell* c) {
    this->cell = c;
}

void Prey::setGender() {
    size_t gend = rand_r(0) % 2 + 1;
    this->gender = gend;
}

void Prey::setPosib() {
    if (this->gender == 1) {
        this->reprod_posib = 0;
    } else {
        this->reprod_posib = rand_r(0) % 9 + 1;
    }
}

void Prey::init(Cell* c) {
    this->set_time();
    this->set_objType();
    this->setCell(c);
    this->setGender();
    this->setPosib();
}

// If a fish of the opposite gender is found nearby, ready for reproduction,
// then we try to create a new representative of the Prey class
void Prey::reproduction() {
    if (this->getGender() == 2) {
        if (this->reprod_posib > 0) {
            if (this->time > 30) {
                Pair p = this->cell->getCord();
                int fishes = 0;
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
                        if (now_cell->getObject() != nullptr) {
                            if (now_cell->getObject()->get_objType() == 2) {
                                Prey* fish = reinterpret_cast
                                    <Prey*>(now_cell->getObject());

                                if (fish->getGender() == 1 &&
                                    fish->time > 30) {

                                    fishes++;
                                    break;

                                } else {
                                    p.i -= n;
                                    p.j -= m;
                                    continue;
                                }
                            } else {
                                p.i -= n;
                                p.j -= m;
                                continue;
                            }
                        } else {
                            p.i -= n;
                            p.j -= m;
                            continue;
                        }
                    }
                    if (fishes)
                        break;
                }
                if (fishes) {
                    size_t* pos = this->get_posib();
                    int suc = 0;
                    Pair p = this->cell->getCord();
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
                            Cell* now_cell =
                                this->cell->getOcean()->get_cell(p);

                            if (now_cell->getObject() == nullptr) {
                                suc = 1;
                                break;
                            } else {
                                p.i -= n;
                                p.j -= m;
                            }
                        }
                        if (suc)
                            break;
                    }
                    if (suc) {
                        (*pos)--;
                        Cell* now_cell = this->cell->getOcean()->get_cell(p);
                        Prey* new_fish = new Prey;
                        new_fish->init(now_cell);
                        now_cell->setObject(new_fish);
                        this->cell->getOcean()->addObject(new_fish);
                    }
                }
            }
        }
    }
}

// Attempt to move to a random cell nearby
void Prey::move() {
    Pair p = this->cell->getCord();
    for (int n = 0; n <= 8; n++) {
        int i = rand_r(0) % 3 - 1;
        int j = rand_r(0) % 3 - 1;
        p.i += i;
        p.j += j;

        if ((p.i < 0 || p.i > N - 1) || (p.j < 0 || p.j > M - 1)) {
            p.i -= i;
            p.j -= j;
            continue;
        } else {
            Cell* now_cell = this->cell->getOcean()->get_cell(p);
            if (now_cell->getObject() == nullptr) {
                now_cell->setObject(this);
                this->cell->delObj();
                this->setCell(now_cell);
                break;
            } else {
                p.i -= i;
                p.j -= j;
                continue;
            }
        }
    }
}

// Movement and reproduction of fish with an average life time of 75 times,
// if they get together in flocks, they form a large colony.
void Prey::live() {
    size_t time_for_live = rand_r(0) % 50 + 50;
    if (time <= time_for_live) {
        this->move();
        this->reproduction();
        time++;
    } else {
        this->die();
    }
}

void Prey::die() {
    this->cell->killMe(this);
    this->objType = -1;
}

int Prey::get_objType() {
    return objType;
}

size_t Prey::getGender() {
    return this->gender;
}

size_t* Prey::get_posib() {
    return &(this->reprod_posib);
}

char Prey::get_info_object() {
    return PREY_N;
}

void Prey::print_object() {
    std::cout << PREY_N;
}
