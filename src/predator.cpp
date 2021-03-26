// Copyright 2021 VladimirUspensky

#include "../include/predator.h"
#include "../include/cell.h"
#include "../include/ocean.h"

Predator::Predator(Cell* c) : Prey(c) {
    type = ObjType::PREDATOR;
    remain_live = static_cast<int>(cell->getOcean()->rand()
                                   % LIVING_TIME_OF_PREDATOR);
}

void Predator::live() {
    int x = cell->getCrd().x_coord;
    int y = cell->getCrd().y_coord;
    if (remain_live-- > 0) {
        hunt();
        if (x == cell->getCrd().x_coord && y == cell->getCrd().y_coord) {
            move();
            if (!cell->getOcean()->getCells()[x][y].getObject() &&
                cell->getOcean()->rand() % 100 <
                PREDATOR_AMOUNT) {
                cell->getOcean()->getCells()[x][y].setObject(
                        new Predator{&cell->getOcean()->getCells()[x][y]});
                cell->getOcean()->temp_stuff.push_back(
                        cell->getOcean()->getCells()[x][y].getObject());
            }
        }
    }
}

void Predator::hunt() {
    int x = cell->getCrd().x_coord;
    int y = cell->getCrd().y_coord;
    std::vector<Pair> dirs;
    Object *ocean = cell->getOcean()->getCells()
            [(x + N - 1) % N][(y + M - 1) %M]
            .getObject();
    if (ocean && ocean->getType() == ObjType::PREY) {
        dirs.push_back
        (Pair{static_cast<int>(x + N - 1) % N,
              static_cast<int>(y + M - 1) % M});
    }
    ocean = cell->getOcean()->getCells()
            [(x + N + 1) % N][(y + M + 1) %M]
            .getObject();
    if (ocean && ocean->getType() == ObjType::PREY) {
        dirs.push_back
        (Pair{static_cast<int>(x + N + 1) % N,
              static_cast<int>(y + M + 1) % M});
    }
    ocean = cell->getOcean()->getCells()
            [(x + N) % N][(y + M - 1) %M]
            .getObject();
    if (ocean && ocean->getType() == ObjType::PREY) {
        dirs.push_back
        (Pair{static_cast<int>(x + N) % N,
              static_cast<int>(y + M - 1) % M});
    }
    ocean = cell->getOcean()->getCells()
            [(x + N - 1) % N][(y + M) %M]
            .getObject();
    if (ocean && ocean->getType() == ObjType::PREY) {
        dirs.push_back
        (Pair{static_cast<int>(x + N - 1) % N,
              static_cast<int>(y + M) % M});
    }
    ocean = cell->getOcean()->getCells()
            [(x + N) % N][(y + M + 1) %M]
            .getObject();
    if (ocean && ocean->getType() == ObjType::PREY) {
        dirs.push_back
        (Pair{static_cast<int>(x + N) % N,
              static_cast<int>(y + M + 1) % M});
    }
    ocean = cell->getOcean()->getCells()
            [(x + N + 1) % N][(y + M) %M]
            .getObject();
    if (ocean && ocean->getType() == ObjType::PREY) {
        dirs.push_back
        (Pair{static_cast<int>(x + N + 1) % N,
              static_cast<int>(y + M) % M});
    }
    ocean = cell->getOcean()->getCells()
            [(x + N + 1) % N][(y + M - 1) %M]
            .getObject();
    if (ocean && ocean->getType() == ObjType::PREY) {
        dirs.push_back
        (Pair{static_cast<int>(x + N + 1) % N,
              static_cast<int>(y + M - 1) % M});
    }
    ocean = cell->getOcean()->getCells()
            [(x + N - 1) % N][(y + M + 1) %M]
            .getObject();
    if (ocean && ocean->getType() == ObjType::PREY) {
        dirs.push_back
        (Pair{static_cast<int>(x + N - 1) % N,
              static_cast<int>(y + M + 1) % M});
    }
    if (!dirs.empty()) {
        Pair newDir =
                dirs[cell->getOcean()->rand() %
                     dirs.size()];
        int new_x_coord = newDir.x_coord;
        int new_y_coord = newDir.y_coord;
        Cell** cells = cell->getOcean()->getCells();
        cells[new_x_coord][new_y_coord].getObject()->setRemainLive(0);
        cells[new_x_coord][new_y_coord].setObject(this);
        cells[new_x_coord][new_y_coord]
        .getObject()->setRemainLive(
                static_cast<int>(cells[new_x_coord][new_y_coord]
                .getObject()->getRemainLive() +
                PREDATOR_EATING_REWARD));
        cells[new_x_coord][new_y_coord]
        .getObject()->setCell(&cells[new_x_coord][new_y_coord]);
        cells[x][y].killMe();
    }
}
