//  Copyright 2021 Nikita Naumov

#include "../include/ocean.h"
#include "../include/common.h"
#include "../include/Object.h"
#include "../include/cell.h"
#include "../include/predator.h"
#include "../include/prey.h"
#include "../include/stone.h"
#include "../include/None.h"

Ocean::Ocean() {
    Pair p_new = {0,0};
    this->cells = new Cell* [N];
    for (size_t i = 0; i < N; ++i) {
        this->cells[i] = new Cell [M];
    }
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < M; ++j) {
            p_new.x = i; p_new.y = j;
            this->cells[i][j] = Cell(p_new, this);
        }
    }
}

Ocean::~Ocean() {
    for (size_t i = 0; i < N; ++i) {
        delete[] this->cells[i];
    }
    delete[] this->cells;
}

void Ocean::run(int amountOfPredators, int amountOfPreys, int amountOfStones, int amountOfCorals) {
    this->addObjects(amountOfPredators,amountOfPreys,amountOfStones, amountOfCorals);
    int shift = 0;
    unsigned iteration = 0;
    while (this->isTherePredatorsOrPreys()) {
        ++iteration;
        for (size_t i = 0; i < this->stuff.size(); ++i) {
            this->stuff[(i+shift) % (this->stuff.size())]->live();
        }
        ++shift;
        std::cout << iteration << std::endl;
        this->print();
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
}
void Ocean::addObjects(int amountOfPredators, int amountOfPreys, int amountOfStones, int amountOfCorals) {
    for (size_t i = 0; i < (N*M); ++i) {
        bool flag = false;
        while (!flag) {
            flag = false;
            coord_t x = std::rand() % N;
            coord_t y = std::rand() % M;
            if (amountOfStones) {
                if (this->cells[x][y].isFree()) {
                    this->cells[x][y].setObject(new Stone(&cells[x][y]));
                    --amountOfStones;
                    flag = true;
                }
            } else if (amountOfCorals) {
                if (this->cells[x][y].isFree()) {
                    this->cells[x][y].setObject(new Coral(&cells[x][y]));
                    --amountOfCorals;
                    flag = true;
                }
            } else if (amountOfPreys) {
                if (this->cells[x][y].isFree()) {
                    this->cells[x][y].setObject(new Prey(&cells[x][y]));
                    --amountOfPreys;
                    flag = true;
                }
            } else if (amountOfPredators) {
                if (this->cells[x][y].isFree()) {
                    this->cells[x][y].setObject(new Predator(&cells[x][y]));
                    --amountOfPredators;
                    flag = true;
                }
            } else if (!(amountOfPredators) && !(amountOfStones) &&
                        !(amountOfCorals) && !(amountOfPreys)) {
                break;
            }
        }
        if (!amountOfPredators && !amountOfStones && !amountOfCorals && !amountOfPreys) {
            break;
        }
    }
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < M; ++j) {
            if (this->cells[i][j].isFree()){
                this->cells[i][j].setObject(new None(&(this->cells[i][j])));
            }
        }
    }
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < M; ++j) {
            if (!(cells[i][j].isFree())) {
                stuff.push_back(cells[i][j].getObject());
            }
        }
    }
}

void Ocean::print() const {
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < M; ++j) {
            Object* object = this->cells[i][j].getObject();
            ObjType curType = object->getType();
            switch(curType) {
                case ObjType::NONE:
                    std::cout << NONE_SYM;
                    break;
                case ObjType::STONE:
                    std::cout << STONE_SYM;
                    break;
                case ObjType::CORAL:
                    std::cout << CORAL_SYM;
                    break;
                case ObjType::PREY:
                    std::cout << PREY_SYM;
                    break;
                case ObjType::PREDATOR:
                    std::cout << PREDATOR_SYM;
                    break;
            }
        }
        std::cout << std::endl;
    }
}

std::vector<Cell> Ocean::getNearbyCells(int i, int j) {
    std::vector<Cell> nearby;
    if ( i == 0 ) {
        if (j == 0) {
            nearby.push_back(this->cells[i+1][j]);
            nearby.push_back(this->cells[i+1][j+1]);
            nearby.push_back(this->cells[i][j+1]);
        } else if ( j == (M-1)) {
            nearby.push_back(this->cells[i+1][j]);
            nearby.push_back(this->cells[i+1][j-1]);
            nearby.push_back(this->cells[i][j-1]);
        } else {
            nearby.push_back(this->cells[i][j-1]);
            nearby.push_back(this->cells[i][j+1]);
            nearby.push_back(this->cells[i+1][j-1]);
            nearby.push_back(this->cells[i+1][j]);
            nearby.push_back(this->cells[i+1][j+1]);
        }
    } else if ( i == (N-1)) {
        if (j == 0) {
            nearby.push_back(this->cells[i-1][j]);
            nearby.push_back(this->cells[i-1][j+1]);
            nearby.push_back(this->cells[i][j+1]);
        } else if ( j == (M-1)) {
            nearby.push_back(this->cells[i-1][j]);
            nearby.push_back(this->cells[i-1][j-1]);
            nearby.push_back(this->cells[i][j-1]);
        } else {
            nearby.push_back(this->cells[i][j-1]);
            nearby.push_back(this->cells[i][j+1]);
            nearby.push_back(this->cells[i-1][j-1]);
            nearby.push_back(this->cells[i-1][j]);
            nearby.push_back(this->cells[i-1][j+1]);
        }
    } else if (j == 0 ) {
        if ((i > 0)  && (i < (N-1))) {
            nearby.push_back(this->cells[i - 1][j]);
            nearby.push_back(this->cells[i + 1][j]);
            nearby.push_back(this->cells[i - 1][j + 1]);
            nearby.push_back(this->cells[i][j + 1]);
            nearby.push_back(this->cells[i + 1][j + 1]);
        }
    } else if (j == (M-1)) {
        if ((i > 0)  && (i < (N-1))) {
            nearby.push_back(this->cells[i-1][j]);
            nearby.push_back(this->cells[i+1][j]);
            nearby.push_back(this->cells[i-1][j-1]);
            nearby.push_back(this->cells[i][j-1]);
            nearby.push_back(this->cells[i+1][j-1]);
        }
    } else if ((i > 0) && (i < (N-1)) && (j > 0) && (j < (M-1))) {
        nearby.push_back(this->cells[i-1][j-1]);
        nearby.push_back(this->cells[i-1][j]);
        nearby.push_back(this->cells[i-1][j+1]);
        nearby.push_back(this->cells[i][j-1]);
        nearby.push_back(this->cells[i][j+1]);
        nearby.push_back(this->cells[i+1][j-1]);
        nearby.push_back(this->cells[i+1][j]);
        nearby.push_back(this->cells[i+1][j+1]);
    }
    return nearby;
}
void Ocean::setObjectToCell(Object* object, int i, int j) {
    this->cells[i][j].setObject(object);
}

Cell* Ocean::getCell(int i, int j) {
    return &(this->cells[i][j]);
}
bool Ocean::isTherePredatorsOrPreys() {
    int predCounter = 0;
    int preyCounter = 0;
    for (auto objectOnMap : this->stuff) {
        if (objectOnMap->getType() == ObjType::PREY) {
            ++preyCounter;
        }
        if (objectOnMap->getType() == ObjType::PREDATOR) {
            ++predCounter;
        }
    }
    if ((predCounter * preyCounter) == 0) {
        return false;
    }
    return true;
}