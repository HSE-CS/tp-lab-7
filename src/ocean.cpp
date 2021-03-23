
#include "../include/ocean.h"
#include "predator.h"
#include "stone.h"

Ocean::Ocean(unsigned int x_len, unsigned int y_len) {
    if (x_len < 1 || y_len < 1) {
        throw "X or Y out of range";
    }
    this->cells.resize(x_len);
    for (auto &a : this->cells) {
        a.resize(y_len);
    }
    for (int i = 0; i < x_len; ++i) {
        for (int j = 0; j < y_len; ++j) {
            cells[i][j] = new Cell(std::pair<int, int>{i, j}, this);
        }
    }
}

Ocean::~Ocean() {
    for (auto & cell : this->cells) {
        for (auto & j : cell) {
            delete j;
        }
    }
    for (Object *a: this->stuff) {
        delete a;
    }
}

void Ocean::addObject(Object *object) {
    if (object != nullptr)
        this->stuff.insert(this->stuff.end(), object);
}

void Ocean::addObjects(std::list<Object *> lst) {
    for (auto &obj : lst) {
        if (obj != nullptr) {
            this->stuff.insert(this->stuff.end(), obj);
        }
    }
}

Cell * Ocean::get(unsigned int x, unsigned int y) {
    if (x < 0 || y < 0 ||
    x >= this->cells.size() || y >= this->cells[0].size()) {
        throw "X or Y out of range";
    }
    return this->cells[x][y];
}

void Ocean::setObjectOnCell(Object *object, Cell *cell) {
    if (cell->ocean != this) {
        throw "Cell is not in ocean";
    }
    cell->object = object;
    object->cell = cell;
}

void Ocean::setObjectOnCell(Object *object, int i, int j) {
    if (cells[i][j]->object != nullptr) {
        delete removeFromStuff(cells[i][j]->object);
    }
    cells[i][j]->object = object;
    if (object != nullptr)
        object->cell = cells[i][j];
    addObject(object);
}

unsigned int Ocean::lenX() {
    return this->cells.size();
}

unsigned int Ocean::lenY() {
    return this->cells[0].size();
}

Object * Ocean::removeFromStuff(Object *obj) {
    Object *tmp = nullptr;
    for (auto &x : this->stuff)
        if (x == obj)
            tmp = x;
    this->stuff.remove(tmp);
    return tmp;
}

void Ocean::print() {
    for (int i = 0; i < lenX() * lenY(); ++i) {
        std::cout << "\n";
    }
    std::cout << "------------\nOCEAN\n";
    for (auto &rows : cells) {
        for (auto &x : rows) {
            if (x->getObject() != nullptr) {
                std::cout << x->getObject()->getCharacter();
            } else {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
}

void Ocean::run() {
    int max_cells = this->lenX() * this->lenY();
    int r;
    for (int i = 0; i < lenX(); ++i) {
        for (int j = 0; j < lenY(); ++j) {
            switch (rand() % ObjectTypeLen-1) {
                case -1:
                    setObjectOnCell(new Stone(get(i, j)), i, j);
                    break;
                case 1:
                    setObjectOnCell(
                            new Prey(get(i, j),
                                     Prey::std_life_time), i, j);
                    break;
                case 2:
                    setObjectOnCell(
                            new Predator(get(i, j),
                                         Prey::std_life_time), i, j);
                    break;
                default:
                    setObjectOnCell(
                            nullptr, i, j);
                    break;
            }
        }
    }

    std::map<ObjectType, unsigned int> m = getObjectsCount();
    while (m[ObjectType::PREY] > 0 && m[ObjectType::PREDATOR] > 0) {
        print();
        for (auto &x : stuff) {
            x->live();
        }
        m = getObjectsCount();
    }
}

std::map<ObjectType, unsigned int> Ocean::getObjectsCount() {
    std::map<ObjectType, unsigned int> m = {
            {ObjectType::STONE, 0},
            {ObjectType::OBJECT, 0},
            {ObjectType::PREY, 0},
            {ObjectType::PREDATOR, 0}};
    for (auto x : stuff) {
        ++m.at(x->getType());
    }
    return m;
}
