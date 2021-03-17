// Copyright 2021 valvarl

#include "prey.h"
#include "cell.h"
#include "ocean.h"

Prey::~Prey() {

}

void Prey::live() {
    int x = cell->getCrd().x, y = cell->getCrd().y;
    if (remain_live-- > 0){
        move();
    }
    if (!cell->getOcean()->getCells()[x][y].getObject() &&
    cell->getOcean()->simple_rand() % 100 < PREY_GENERATE_PROBABILITY) {
        cell->getOcean()->getCells()[x][y].setObject(
                new Prey{&cell->getOcean()->getCells()[x][y]});
        cell->getOcean()->temporary_stuff.push_back(
                cell->getOcean()->getCells()[x][y].getObject());
    }
}

Prey::Prey(Cell *_cell) : Object(_cell) {
    type = ObjType::PREY;
    remain_live = static_cast<int>(cell->getOcean()->simple_rand()
            % PREY_LIFE_DURATION + 1);
}

void Prey::move() {
    int x = cell->getCrd().x, y = cell->getCrd().y;
    std::vector<Pair> directions;
    if (!cell->getOcean()->getCells()[(x + N - 1) % N][(y + M - 1) %
                                                       M].getObject()) {
        directions.push_back(Pair{(size_t) (x + N - 1) % N,
                                  (size_t) (y + M - 1) % M});
    }
    if (!cell->getOcean()->getCells()[(x + N + 1) % N][(y + M + 1) %
                                                       M].getObject()) {
        directions.push_back(Pair{(size_t) (x + N + 1) % N,
                                  (size_t) (y + M + 1) % M});
    }
    if (!cell->getOcean()->getCells()[(x + N) % N][(y + M - 1) %
                                                   M].getObject()) {
        directions.push_back(Pair{(size_t) (x + N) % N,
                                  (size_t) (y + M - 1) % M});
    }
    if (!cell->getOcean()->getCells()[(x + N - 1) % N][(y + M) %
                                                       M].getObject()) {
        directions.push_back(Pair{(size_t) (x + N - 1) % N,
                                  (size_t) (y + M) % M});
    }
    if (!cell->getOcean()->getCells()[(x + N) % N][(y + M + 1) %
                                                   M].getObject()) {
        directions.push_back(Pair{(size_t) (x + N) % N,
                                  (size_t) (y + M + 1) % M});
    }
    if (!cell->getOcean()->getCells()[(x + N + 1) % N][(y + M) %
                                                       M].getObject()) {
        directions.push_back(Pair{(size_t) (x + N + 1) % N,
                                  (size_t) (y + M) % M});
    }
    if (!cell->getOcean()->getCells()[(x + N + 1) % N][(y + M - 1) %
                                                       M].getObject()) {
        directions.push_back(Pair{(size_t) (x + N + 1) % N,
                                  (size_t) (y + M - 1) % M});
    }
    if (!cell->getOcean()->getCells()[(x + N - 1) % N][(y + M + 1) %
                                                       M].getObject()) {
        directions.push_back(Pair{(size_t) (x + N - 1) % N,
                                  (size_t) (y + M + 1) % M});
    }
    if (!directions.empty()) {
        Pair new_direction = directions[cell->getOcean()->simple_rand()
                                        % directions.size()];
        int new_x = new_direction.x, new_y = new_direction.y;
        if (x == 14 && y == 9) {
            Cell **_cells = cell->getOcean()->getCells();
        }
        cell->getOcean()->getCells()[new_x][new_y].setObject(this);
        this->setCell(&cell->getOcean()->getCells()[new_x][new_y]);
        cell->getOcean()->getCells()[x][y].killMe();
    }
}

Coral::Coral(Cell *_cell) : Prey(_cell) {
    type = ObjType::CORAL;
    remain_live = static_cast<int>(cell->getOcean()->simple_rand()
            % CORAL_LIFE_DURATION);
}

void Coral::live() {
    int x = cell->getCrd().x, y = cell->getCrd().y;
    if (remain_live-- > 0 &&
            cell->getOcean()->simple_rand() % 100 < CORAL_GENERATE_PROBABILITY) {
        move();
        if (x != cell->getCrd().x || y != cell->getCrd().y) {
            Cell *_cell = &cell->getOcean()->getCells()[x][y];
            _cell->setObject(new Coral{_cell});
            int temporary_life_duration = remain_live;
            remain_live = _cell->getObject()->getRemainLive();
            _cell->getObject()->setRemainLive(temporary_life_duration);
            cell->getOcean()->temporary_stuff.push_back(_cell->getObject());
        }
    }
}
