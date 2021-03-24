//  Copyright © 2021 Ksuvot
#include "Cell.h"
#include "Prey.h"
#include "Ocean.h"
#include "Stone.h"
#include "Common.h"
#include "Predator.h"
#include <iostream>
#include <list>

Ocean::Ocean(int x, int y) {
  x = x-1;
  y = y-1;
    cells = new Cell*[x];
    for (int i = 0; i < x; ++i) {
        cells[i] = new Cell[y];
    }
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            Pair pair{};
            pair.x = i;
            pair.y = j;
            cells[i][j].init(pair, this);
        }
    }
}

void Ocean::addObjects(int prey, int stone, int predator) {
    Pair pair;
    for (int i = 0; i < prey; ++i) {
      pair.x = std::rand()%this->x;
      pair.y = std::rand() % this->y;
        if (cells[pair.x][pair.y].is_Empty()) {
            Prey* a = new Prey(pair, &cells[pair.x][pair.y]);
            stuff.push_back(a);
            cells[pair.x][pair.y].setObject(a);
        }
    }
    for (int i = 0; i < stone; ++i) {
      pair.x = std::rand() % this->x;
      pair.y = std::rand() % this->y;
        if (cells[pair.x][pair.y].is_Empty()) {
            auto* stone = new STONE(pair, &cells[pair.x][pair.y]);
            stuff.push_back(stone);
            cells[pair.x][pair.y].setObject(stone);
        }
    }
    for (int i = 0; i < predator; ++i) {
      pair.x = std::rand() % this->x;
      pair.y = std::rand() % this->y;
        if (cells[pair.x][pair.y].is_Empty()) {
            auto* b = new Predator(pair, &cells[pair.x][pair.y]);
            stuff.push_back(b);
            cells[pair.x][pair.y].setObject(b);
        }
    }
}


void Ocean::print() const {
    ObjType obj_type;
    for (int i = 0; i < x + 1; ++i) {
        for (int j = 0; j < y + 1; ++j) {
            if (cells[i][j].object_) {
              obj_type = cells[i][j].object_->getType();
                switch (obj_type) {
                case ObjType::PREY:
                    std::cout << PREY_N << " ";
                    break;
                case ObjType::PREDATOR:
                    std::cout << PREDATOR_N << " ";
                    break;
                case ObjType::STONE:
                    std::cout << STONE_N << " ";
                    break;
                case ObjType::CORAL:
                    std::cout << CORAL_N << " ";
                    break;
                }
            } else {
                std::cout << " " << " ";
            }
        }
        std::cout << std::endl;
    }
}

void Ocean::run() {
    for (Object* obj : stuff) {
        Move move = static_cast<Move>(std::rand() % 9);
        if (obj->getType() == ObjType::PREY) {
            obj->PrepForMOVE(move, this);
        } else if ((obj->getType() == ObjType::PREDATOR)) {
            Object* p_object = dynamic_cast<Predator*>(obj)->Searching(this);
            if (p_object) {
                if (dynamic_cast<Predator*>(obj)->eating) {
                    obj->setCell(&cells[p_object->getPair().x]
                        [p_object->getPair().y]);
                    cells[obj->getPair().x]
                        [obj->getPair().y].setObject(nullptr);
                    cells[p_object->getPair().x]
                        [p_object->getPair().y].setObject(obj);
                    dynamic_cast<Predator*>(obj)->pair_ = p_object->getPair();
                    auto it = stuff.begin();
                    for (it = stuff.begin(); it != stuff.end(); it++) {
                        if (*it == p_object) {
                            it = stuff.erase(it);
                            break;
                        }
                    }
                    p_object->~Object();
                    delete p_object;
                }
            }
        }
        if ((obj->getMove() != Move::STAY)
            &&(obj->getType() != ObjType::STONE)) {
            cells[obj->getPair().x][obj->getPair().y].setObject(nullptr);
        }
    }
    for (auto obj = stuff.begin(); obj != stuff.end(); ++obj) {
        if (((*obj)->getType() == ObjType::PREDATOR)
            || ((*obj)->getType() == ObjType::PREY)) {
            int randBorn = std::rand() % 25;
            if (!randBorn) {
                (*obj)->Reproduction(this);
            }
        }
        (*obj)->live();
        if (((*obj)->getType() == ObjType::PREDATOR)
            && (dynamic_cast<Predator*>(*obj)->eat == 0)) {
            cells[(*obj)->getPair().x][(*obj)->
                getPair().y].setObject(nullptr);
            obj = stuff.erase(obj);
        } else if (((*obj)->getType() == ObjType::STONE)
            && (dynamic_cast<STONE *>(*obj)->getSpeed() == 0)) {
            cells[(*obj)->getPair().x][(*obj)->
                getPair().y].setObject(nullptr);
            obj = stuff.erase(obj);
        } else if (((*obj)->getMove() != Move::STAY)
            && ((*obj)->getType() != ObjType::STONE)) {
            cells[(*obj)->getPair().x][(*obj)->getPair().y].setObject(*obj);
        }
    }
}
