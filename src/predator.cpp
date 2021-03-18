#include "predator.h"
#include "object.h"

void Predator::set_time() {
    this->time = 1;
}

void Predator::set_objType() {
    this->objType = 3;
}

void Predator::setHuger(size_t hung) {
    this->hunger = hung;
}

int Predator::get_objType() {
    return objType;
}

size_t Predator::getGender() {
    return this->gender;
}

void Predator::setPosib() {
    if (this->gender == 1)
        this->reprod_posib = 0;
    else
        this->reprod_posib = rand() % 3 + 1;
}

size_t* Predator::get_posib() {
    return &(this->reprod_posib);
}

void Predator::reproduction() {
    if (this->getGender() == 2) {
        if (this->reprod_posib > 0) {
            if (this->time > 50) {
                if (this->hunger <= 40) {
                    Pair p = this->cell->getCord();
                    int fishes = 0;
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
                            if (now_cell->getObject() != nullptr) {
                                if (now_cell->getObject()->get_objType() == 3) {
                                    Predator* fish = reinterpret_cast<Predator*>(now_cell->getObject());
                                    if (fish->getGender() == 1 && fish->time > 50) {
                                        fishes++;
                                        break;
                                    }
                                    else {
                                        p.i -= n;
                                        p.j -= m;
                                        continue;
                                    }
                                }
                                else {
                                    p.i -= n;
                                    p.j -= m;
                                    continue;
                                }
                            }
                            else {
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
                                if ((p.i < 0 || p.i > N - 1) || (p.j < 0 || p.j > M - 1)) {
                                    p.i -= n;
                                    p.j -= m;
                                    continue;
                                }
                                Cell* now_cell = this->cell->getOcean()->get_cell(p);
                                if (now_cell->getObject() == nullptr) {
                                    suc = 1;
                                    break;
                                }
                                else {
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
                            Predator* new_fish = new Predator;
                            new_fish->init(now_cell);
                            now_cell->setObject(new_fish);
                            this->cell->getOcean()->addObject(new_fish);
                        }
                    }
                }
            }
        }
    }
}


void Predator::hant() {
    Pair p = this->cell->getCord();
    int fishes = 0;
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
            if (now_cell->getObject() != nullptr) {
                if (now_cell->getObject()->get_objType() == 2) {
                    fishes++;
                    break;
                }
                else {
                    p.i -= n;
                    p.j -= m;
                    continue;
                }
            }
            else {
                p.i -= n;
                p.j -= m;
                continue;
            }
        }
        if (fishes)
            break;
    }
    if (fishes) {
        Cell* now_cell = this->cell->getOcean()->get_cell(p);
        Prey* fish = reinterpret_cast<Prey*>(now_cell->getObject());
        fish->die();
        int hug = this->getHunger();
        hug -= 10;
        if (hug < 0)
            hug = 0;
        this->setHuger(hug);
        if (now_cell->getObject() == nullptr) {
            now_cell->setObject(this);
            this->cell->delObj();
            this->setCell(now_cell);
        }
    }
    else if (!fishes) {
        for (int n = -2; n <= 2; n++) {
            for (int m = -2; m <= 2; m++) {
                p.i += n;
                p.j += m;
                if ((p.i < 0 || p.i > N - 1) || (p.j < 0 || p.j > M - 1)) {
                    p.i -= n;
                    p.j -= m;
                    continue;
                }
                Cell* now_cell = this->cell->getOcean()->get_cell(p);
                if (now_cell->getObject() != nullptr) {
                    if (now_cell->getObject()->get_objType() == 2) {
                        fishes++;
                        break;
                    }
                    else {
                        p.i -= n;
                        p.j -= m;
                        continue;
                    }
                }
                else {
                    p.i -= n;
                    p.j -= m;
                    continue;
                }
            }
            if (fishes)
                break;
        }
        if (fishes) {
            Cell* now_cell = this->cell->getOcean()->get_cell(p);
            Pair my_cord = this->cell->getCord();
            Pair vect = my_cord;

            if (my_cord.i < p.i)
                vect.i++;
            else if (my_cord.i == p.i)
                vect.i = p.i;
            else
                vect.i--;

            if (my_cord.j < p.j)
                vect.j++;
            else if (my_cord.j == p.j)
                vect.j = p.j;
            else
                vect.j--;


            Cell* new_cell = this->cell->getOcean()->get_cell(p);
            if (now_cell->getObject() == nullptr) {
                now_cell->setObject(this);
                this->cell->delObj();
                this->setCell(now_cell);
            }

            else if (now_cell->getObject() != nullptr) {
                Pair chek = vect;
                int flag = 0;
                for (int i = -1; i <= 1; i++) {
                    for (int j = -1; j <= 1; j++) {
                        if (std::abs((int)chek.i + i - (int)my_cord.i) == 1) {
                            if (std::abs((int)chek.j + j - (int)my_cord.j) == 1) {
                                chek.i += i;
                                chek.j += j;
                                if ((chek.i < 0 || chek.i > N - 1) || (chek.j < 0 || chek.j > M - 1)) {
                                    chek.i -= i;
                                    chek.j -= j;
                                    continue;
                                }

                                Cell* new_cell_try = this->cell->getOcean()->get_cell(chek);
                                if (new_cell_try->getObject() == nullptr) {
                                    new_cell_try->setObject(this);
                                    this->cell->delObj();
                                    this->setCell(new_cell_try);
                                    flag = 1;
                                    break;
                                }
                            }
                        }
                    }
                    if (flag) break;
                }
            }
        }
        else this->move();
    }
}


void Predator::move() {
    Pair p = this->cell->getCord();
    for (int n = 0; n <= 8; n++) {
        int i = rand() % 3 - 1;
        int j = rand() % 3 - 1;
        p.i += i;
        p.j += j;

        if ((p.i < 0 || p.i > N - 1) || (p.j < 0 || p.j > M - 1)) {
            p.i -= i;
            p.j -= j;
            continue;
        }
        else {
            Cell* now_cell = this->cell->getOcean()->get_cell(p);
            if (now_cell->getObject() == nullptr) {
                now_cell->setObject(this);
                this->cell->delObj();
                this->setCell(now_cell);
                break;
            }
            else {
                p.i -= i;
                p.j -= j;
                continue;
            }
        }
    }
}

// жизнь объекта
void Predator::live() {
    size_t time_for_live = rand() % 100 + 150;
    if (time <= time_for_live && this->getHunger() < 60) {
        if (this->getHunger() <= 4) {
            this->move();
        }
        else
            this->hant();
        this->reproduction();
        time++;
        hunger++;
    }
    else if (this->getHunger() >= 60) {
        this->die();
    }
    else {
        this->die();
    }
}

void Predator::print_object() {
    std::cout << PREDATOR_N;
}

char Predator::get_info_object() {
    return PREDATOR_N;
}

void Predator::setCell(Cell* c) {
    this->cell = c;
}

void Predator::setGender() {
    size_t gend = rand() % 2 + 1;
    this->gender = gend;
}

void Predator::init(Cell* c) {
    this->set_time();
    this->set_objType();
    this->setCell(c);
    this->setGender();
    this->setPosib();
    this->setHuger(0);
}

size_t Predator::getHunger() {
    return this->hunger;
}

void Predator::die() {
    this->cell->killMe(this);
    this->objType = -1;
}