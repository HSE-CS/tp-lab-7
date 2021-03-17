// Copyright 2021 valvarl

#include "predator.h"
#include "cell.h"
#include "ocean.h"

Predator::Predator(Cell* _cell) : Prey(_cell) {
    type = ObjType::PREDATOR;
    remain_live = static_cast<int>(cell->getOcean()->simple_rand()
            % PREDATOR_LIFE_DURATION);
}

void Predator::live() {
    int x = cell->getCrd().x, y = cell->getCrd().y;
    if (remain_live-- > 0)
    {
        hunt();
        if (x == cell->getCrd().x && y == cell->getCrd().y) {
            move();
            if (!cell->getOcean()->getCells()[x][y].getObject() &&
            cell->getOcean()->simple_rand() % 100 < PREDATOR_GENERATE_PROBABILITY) {
                cell->getOcean()->getCells()[x][y].setObject(
                        new Predator{&cell->getOcean()->getCells()[x][y]});
                cell->getOcean()->temporary_stuff.push_back(
                        cell->getOcean()->getCells()[x][y].getObject());
            }
        }
    }
}

void Predator::hunt() {
    int x = cell->getCrd().x, y = cell->getCrd().y;
    std::vector<Pair> directions;
    Object *o = cell->getOcean()->getCells()[(x + N - 1) % N][(y + M - 1) %
                                                              M].getObject();
    if (o && o->getType() == ObjType::PREY) {
        directions.push_back(Pair{(size_t) (x + N - 1) % N,
                                  (size_t) (y + M - 1) % M});
    }
    o = cell->getOcean()->getCells()[(x + N + 1) % N][(y + M + 1) %
                                                      M].getObject();
    if (o && o->getType() == ObjType::PREY) {
        directions.push_back(Pair{(size_t) (x + N + 1) % N,
                                  (size_t) (y + M + 1) % M});
    }
    o = cell->getOcean()->getCells()[(x + N) % N][(y + M - 1) %
                                                  M].getObject();
    if (o && o->getType() == ObjType::PREY) {
        directions.push_back(Pair{(size_t) (x + N) % N,
                                  (size_t) (y + M - 1) % M});
    }
    o = cell->getOcean()->getCells()[(x + N - 1) % N][(y + M) %
                                                      M].getObject();
    if (o && o->getType() == ObjType::PREY) {
        directions.push_back(Pair{(size_t) (x + N - 1) % N,
                                  (size_t) (y + M) % M});
    }
    o = cell->getOcean()->getCells()[(x + N) % N][(y + M + 1) %
                                                  M].getObject();
    if (o && o->getType() == ObjType::PREY) {
        directions.push_back(Pair{(size_t) (x + N) % N,
                                  (size_t) (y + M + 1) % M});
    }
    o = cell->getOcean()->getCells()[(x + N + 1) % N][(y + M) %
                                                      M].getObject();
    if (o && o->getType() == ObjType::PREY) {
        directions.push_back(Pair{(size_t) (x + N + 1) % N,
                                  (size_t) (y + M) % M});
    }
    o = cell->getOcean()->getCells()[(x + N + 1) % N][(y + M - 1) %
                                                      M].getObject();
    if (o && o->getType() == ObjType::PREY) {
        directions.push_back(Pair{(size_t) (x + N + 1) % N,
                                  (size_t) (y + M - 1) % M});
    }
    o = cell->getOcean()->getCells()[(x + N - 1) % N][(y + M + 1) %
                                                      M].getObject();
    if (o && o->getType() == ObjType::PREY) {
        directions.push_back(Pair{(size_t) (x + N - 1) % N,
                                  (size_t) (y + M + 1) % M});
    }
    if (!directions.empty()) {
        Pair new_direction = directions[cell->getOcean()->simple_rand()
                                        % directions.size()];
        int new_x = new_direction.x, new_y = new_direction.y;
        Cell** _cells = cell->getOcean()->getCells();
        _cells[new_x][new_y].getObject()->setRemainLive(0);
        _cells[new_x][new_y].setObject(this);
        _cells[new_x][new_y].getObject()->setRemainLive(
                static_cast<int>(_cells[new_x][new_y].getObject()->
                getRemainLive() + PREDATOR_EATING_REWARD));
        _cells[new_x][new_y].getObject()->setCell(&_cells[new_x][new_y]);
        _cells[x][y].killMe();
    }
}
