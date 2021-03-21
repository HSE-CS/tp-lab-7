#include <iostream>
#include <list>
#include "Ocean.h"
#include "cell.h"
#include "prey.h"
#include "Predator.h"
#include "stone.h"
#include "common.h"

Ocean::Ocean(int x, int y) {
    size_x = x-1;
    size_y = y-1;
    cells = new Cell*[x];
    for (int i = 0; i < x; ++i) {
        cells[i] = new Cell[y];
    }
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            Pair coord;
            coord.x = i;
            coord.y = j;
            cells[i][j].init(coord, this);
        }
    }
}

void Ocean::addObjects(int mountprey, int mountstone, int mountpredator) {
    Pair coor;
    for (int i = 0; i < mountprey; ++i) {
        coor.x = std::rand()%this->size_x;
        coor.y = std::rand() % this->size_y;
        if (cells[coor.x][coor.y].isEmpty()) {
            Prey* a = new Prey(coor, &cells[coor.x][coor.y]);
            stuff.push_back(a);
            cells[coor.x][coor.y].setObject(a);
        }
    }
    for (int i = 0; i < mountstone; ++i) {
        coor.x = std::rand() % this->size_x;
        coor.y = std::rand() % this->size_y;
        if (cells[coor.x][coor.y].isEmpty()) {
            STONE* stone = new STONE(coor, &cells[coor.x][coor.y]);
            stuff.push_back(stone);
            cells[coor.x][coor.y].setObject(stone);
        }
    }
    for (int i = 0; i < mountpredator; ++i) {
        coor.x = std::rand() % this->size_x;
        coor.y = std::rand() % this->size_y;
        if (cells[coor.x][coor.y].isEmpty()) {
            Predator* b = new Predator(coor, &cells[coor.x][coor.y]);
            stuff.push_back(b);
            cells[coor.x][coor.y].setObject(b);
        }
    }
}


void Ocean::print() const {
    ObjType typ;
    for (int i = 0; i < size_x + 1; ++i) {
        for (int j = 0; j < size_y + 1; ++j) {
            if (cells[i][j].obj) {
                typ = cells[i][j].obj->getType();
                switch (typ) {
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
            }
            else {
                std::cout << " " << " ";
            }

        }
        std::cout << std::endl;
    }
}

void Ocean::run() {
    int i = stuff.size();
    for (Object* obj : stuff) {
        Move move = static_cast<Move>(std::rand() % 9);
        if (obj->getType() == ObjType::PREY)
            obj->PrepForMOVE(move, *this);
        else if ((obj->getType() == ObjType::PREDATOR)) {
            Object* target = dynamic_cast<Predator*>(obj)->Searching(*this);
            if (target) {
                if (dynamic_cast<Predator*>(obj)->readyForCatch) {
                    obj->setCell(&cells[target->getCoord().x][target->getCoord().y]);
                    cells[obj->getCoord().x][obj->getCoord().y].setObject(nullptr);
                    cells[target->getCoord().x][target->getCoord().y].setObject(obj);
                    dynamic_cast<Predator*>(obj)->coord = target->getCoord();
                    auto it = stuff.begin();
                    for (it = stuff.begin(); it != stuff.end(); it++) {
                        if (*it == target) {
                            it = stuff.erase(it);
                            break;
                        }
                    }
                    target->~Object();
                    delete target;
                }
            }
            
        }
        if ((obj->getMovePrep() != Move::STAY)&&(obj->getType()!=ObjType::STONE)) {
            cells[obj->getCoord().x][obj->getCoord().y].setObject(nullptr);
        }
    }
    for (auto obj = stuff.begin(); obj != stuff.end(); ++obj) {
        /*auto obj = stuff.begin();*/
        //advance(obj, i);
        if (((*obj)->getType() == ObjType::PREDATOR)
            || ((*obj)->getType() == ObjType::PREY)) {
            int randBorn = std::rand() % 25;
            if (!randBorn) {
                (*obj)->Reproduction(*this);
            }
        }
        (*obj)->live();
        if (((*obj)->getType() == ObjType::PREDATOR)
            && (dynamic_cast<Predator*>(*obj)->hunger==0)) {
            cells[(*obj)->getCoord().x][(*obj)->getCoord().y].setObject(nullptr);
            obj = stuff.erase(obj);
        } else if (((*obj)->getType() == ObjType::STONE)
            && (dynamic_cast<STONE*>(*obj)->getFastness() == 0)) {
            cells[(*obj)->getCoord().x][(*obj)->getCoord().y].setObject(nullptr);
            obj = stuff.erase(obj);
        } else if (((*obj)->getMovePrep() != Move::STAY) && ((*obj)->getType() != ObjType::STONE)) {

            cells[(*obj)->getCoord().x][(*obj)->getCoord().y].setObject(*obj);
        }
    }
}