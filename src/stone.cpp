#include "stone.h"

void Stone::set_time() {
    this->time = 1;
}

void Stone::set_objType() {
    this->objType = 0;
}

int Stone::get_objType() {
    return this->objType;
}


// жизнь объекта
void Stone::live() {
    time++;
    if (time == 100000) {
        int res = rand() % 2;
        if (res)
            time = 1;
        else {
            this->die();
        }
    }
}

void Stone::print_object() {
    std::cout << STONE_N;
}

void Stone::setCell(Cell* c) {
    this->cell = c;
}

void Stone::init(Cell* c) {
    this->set_time();
    this->set_objType();
    this->setCell(c);
}

void Stone::die() {
    this->cell->killMe(this);
    this->objType = -1;
}


void Coral::set_time() {
    this->time = 1;
}

void Coral::set_objType() {
    this->objType = 1;
}

int Coral::get_objType() {
    return this->objType;
}


void Coral::reproduction() {
    if (this->reprod_posib > 0) {
        if (this->time > 50) {
            Pair p = this->cell->getCord();
            int suc = 0;
            for (int n = -1; n <= 1; n++) {
                for (int m = -1; m <= 1; m++) {
                    p.i += n;
                    p.j += m;
                    if ((p.i < 0 || p.i > N - 1) || (p.j < 0 || p.j > M - 1)) {
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
                    }
                    else {
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

// жизнь объекта
void Coral::live() {
    size_t time_for_live = rand() % 151 + 301;
    if (time <= time_for_live) {
        time++;
        if (time % 150 == 0)
            this->reproduction();
    }
    else {
        this->die();
    }
}

void Coral::print_object() {
    std::cout << CORAL_N;
}

void Coral::setCell(Cell* c) {
    this->cell = c;
}

void Coral::setReprod() {
    this->reprod_posib = rand() % 7 + 1;
}

void Coral::init(Cell* c) {
    this->set_time();
    this->set_objType();
    this->setCell(c);
    this->setReprod();
}

size_t* Coral::getReprod() {
    return &(this->reprod_posib);
}

void Coral::die() {
    this->cell->killMe(this);
    this->objType = -1;
}