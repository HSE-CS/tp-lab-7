// Copyright <Roman Balayan> @ 2021

#include <chrono>
#include <thread>
#include <algorithm>

#include "ocean.h"
#include "cell.h"
#include "common.h"
#include "prey.h"
#include "predator.h"

Ocean::Ocean() {
}

void Ocean::print() const {
    //system("cls");
    for (const auto& row : this->cells) {
        for (const auto& cell : row) {
            if (cell->getObjType() == ObjType::EMPTY) {
                std::cout << ".";
            } else if (cell->getObjType() == ObjType::STONE) {
                std::cout << "#";
            } else if (cell->getObjType() == ObjType::PREY) {
                std::cout << "f";
            } else if (cell->getObjType() == ObjType::PREDATOR) {
                std::cout << "S";
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void Ocean::addObjects() {
    std::shared_ptr<Cell> cell;
    std::shared_ptr<Object> object;
    for (unsigned int i{ 0 }; i < Constants::Y; ++i) {
        std::vector<std::shared_ptr<Cell> > row;
        for (unsigned int j{ 0 }; j < Constants::X; ++j) {
            int casino = rand() % 100;
            cell = std::make_shared<Cell>(Pair(j, i), shared_from_this());
            if (casino <= 30) {
                object = std::make_shared<Object>(cell);
            } else if (casino <= 35) {
                object = std::make_shared<Stone>(cell);
            } else if (casino <= 90) {
                object = std::make_shared<Prey>(cell);
            } else {
                object = std::make_shared<Predator>(cell);
            }
            cell->setObject(object);
            row.push_back(cell);
            this->stuff.push_back(object);
        }
        this->cells.push_back(row);
    }
}

void Ocean::addObject(std::shared_ptr<Object> obj) {
    this->stuff.push_back(obj);
}

void Ocean::removeObject(std::shared_ptr<Object> obj) {
    this->stuff.remove(obj);
}

void Ocean::resetObject(std::shared_ptr<Object> target,
                        std::shared_ptr<Object> newObj) {
    for (auto& obj : this->stuff)
        if (obj == target) {
            obj = newObj;
            break;
        }
}

void Ocean::run() {
    char c;
    this->print();
    int i = 0;
    while (1) {
        for (auto& obj : this->stuff)
        {
            if (obj)
                obj->live();
        }
        this->print();
        std::cout << i++ << " iter\n";
        //std::cin >> c;
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    }
}

std::shared_ptr<Cell> Ocean::getEmptyCell() {
    for (const auto& cell : this->cells) {
        auto result = std::find_if(cell.begin(),
                                   cell.end(),
                                   [](std::shared_ptr<Cell> cellI) {
                return cellI->getObjType() == ObjType::EMPTY;
            });
        if (result != cell.end())
            return *result;
    }
    return nullptr;
}

std::shared_ptr<Cell> Ocean::getEmptyCellAround(std::shared_ptr<Cell> target)
{
    return std::shared_ptr<Cell>();
    auto x = target->coords.first;
    auto y = target->coords.second;
    for(int i = -1; i <= 1; ++i)
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0)
                continue;
            auto cell = getCell(x + i, y + j);
            if (cell && cell->getObjType() == ObjType::EMPTY)
                return cell;
        }
    return nullptr;
}

std::shared_ptr<Cell> Ocean::getCell(int x, int y) {
    if(x >= 0 && x < Constants::X && y >= 0 && y < Constants::Y)
        return this->cells[y][x];
    return nullptr;
}
