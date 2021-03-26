// Copyright 2021 VladimirUspensky

#include "prey.h"
#include "cell.h"
#include "ocean.h"

Prey::~Prey() {}

void Prey::live() {
    int new_x_coord = cell->getCrd().x_coord;
    int new_y_coord = cell->getCrd().y_coord;
    if (remain_live-- > 0) {
        move();
    }
    if (!cell->getOcean()->getCells()[new_x_coord][new_y_coord].getObject() &&
        cell->getOcean()->rand() % 100 < PREY_AMOUNT) {
        cell->getOcean()->getCells()[new_x_coord][new_y_coord].setObject(
                new Prey{&cell->getOcean()->getCells()[new_x_coord][new_y_coord]});
        cell->getOcean()->temp_stuff.push_back(
                cell->getOcean()->getCells()[new_x_coord][new_y_coord].getObject());
    }
}

Prey::Prey(Cell *cell) : Object(cell) {
    type = ObjType::PREY;
    remain_live = static_cast<int>(cell->getOcean()->rand()
                                   % LIVING_TIME_OF_PREY + 1);
}

void Prey::move() {
    int new_x_coord = cell->getCrd().x_coord;
    int new_y_coord = cell->getCrd().y_coord;
    std::vector<Pair> dirs;
    if (!cell->getOcean()->getCells()
        [(new_x_coord + N - 1) % N][(new_y_coord + M - 1) %M]
        .getObject()) {
        dirs.push_back
        (Pair{
            (int) (new_x_coord + N - 1) % N,
            (int) (new_y_coord + M - 1) % M});
    }
    if (!cell->getOcean()->getCells()
        [(new_x_coord + N + 1) % N][(new_y_coord + M + 1) %M]
        .getObject()) {
        dirs.push_back
        (Pair{
            (int) (new_x_coord + N + 1) % N,
            (int) (new_y_coord + M + 1) % M});
    }
    if (!cell->getOcean()->getCells()
        [(new_x_coord + N) % N][(new_y_coord + M - 1) %M]
        .getObject()) {dirs.push_back
        (Pair{
            (int) (new_x_coord + N) % N,
            (int) (new_y_coord + M - 1) % M});
    }
    if (!cell->getOcean()->getCells()
        [(new_x_coord + N - 1) % N][(new_y_coord + M) %M]
        .getObject()) {
        dirs.push_back
        (Pair{
            (int) (new_x_coord + N - 1) % N,
            (int) (new_y_coord + M) % M});
    }
    if (!cell->getOcean()->getCells()
        [(new_x_coord + N) % N][(new_y_coord + M + 1) %M]
        .getObject()) {
        dirs.push_back
        (Pair{
            (int) (new_x_coord + N) % N,
            (int) (new_y_coord + M + 1) % M});
    }
    if (!cell->getOcean()->getCells()
        [(new_x_coord + N + 1) % N][(new_y_coord + M) %M].getObject()) {
        dirs.push_back
        (Pair{
            (int) (new_x_coord + N + 1) % N,
            (int) (new_y_coord + M) % M});
    }
    if (!cell->getOcean()->getCells()
        [(new_x_coord + N + 1) % N][(new_y_coord + M - 1) %M]
        .getObject()) {
        dirs.push_back
        (Pair{
            (int) (new_x_coord + N + 1) % N,
            (int) (new_y_coord + M - 1) % M});
    }
    if (!cell->getOcean()->getCells()
        [(new_x_coord + N - 1) % N][(new_y_coord + M + 1) %M]
        .getObject()) {
        dirs.push_back
        (Pair{
            (int) (new_x_coord + N - 1) % N,
            (int) (new_y_coord + M + 1) % M});
    }
    if (!dirs.empty()) {
        Pair newDirs =
                dirs[cell->getOcean()->rand()% dirs.size()];
        int new_x = newDirs.x_coord;
        int new_y = newDirs.y_coord;
        if (new_x_coord == 14 && new_y_coord == 9) {
            Cell **_cells = cell->getOcean()->getCells();
        }
        cell->getOcean()->getCells()[new_x][new_y].setObject(this);
        this->setCell(&cell->getOcean()->getCells()[new_x][new_y]);
        cell->getOcean()->getCells()[new_x_coord][new_y_coord].killMe();
    }
}

Coral::Coral(Cell *cell) : Prey(cell) {
    type = ObjType::CORAL;
    remain_live = static_cast<int>(cell->getOcean()->rand()
                                   % LIVING_TIME_OF_CORAL);
}

void Coral::live() {
    int x_coord = cell->getCrd().x_coord;
    int y_coord = cell->getCrd().y_coord;
    if (remain_live-- > 0 &&
            cell->getOcean()->rand() % 100 <
            CORAL_AMOUNT) {
        move();
        if (x_coord != cell->getCrd().x_coord || y_coord != cell->getCrd().y_coord) {
            Cell *_cell = &cell->getOcean()->getCells()[x_coord][y_coord];
            _cell->setObject(new Coral{_cell});
            int temporary_life_duration = remain_live;
            remain_live = _cell->getObject()->getRemainLive();
            _cell->getObject()->setRemainLive(temporary_life_duration);
            cell->getOcean()->temp_stuff.push_back(_cell->getObject());
        }
    }
}
