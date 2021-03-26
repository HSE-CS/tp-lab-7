// Copyright dmitrycvetkov 2021
#include "ocean.h"

#include "cell.h"
#include "object.h"
#include "stone.h"
#include "prey.h"
#include "predator.h"

#include "common.h"
#include "object_factory.h"

#include <algorithm>
#include <iostream>
#include <functional>
#include <numeric>
#include <thread>
#include <random>
#include <vector>
#include <string>

Ocean::Ocean() : cells(N) {
    for (coord_t i = 0; i < cells.size(); ++i) {
        auto& row = cells[i];
        row.resize(M);
        for (coord_t j = 0; j < row.size(); ++j) {
            auto& cell = row[j];
            cell = std::make_shared<Cell>(Pair {j, i}, this);
        }
    }
}

void Ocean::print() const {
    static std::string line(M, '-');
    std::cout << line << std::endl;
    for (const auto& row : cells) {
        for (const auto& c : row) {
            std::cout << toChar(c->getObject());
        }
        std::cout << std::endl;
    }
    std::cout << line << std::endl;
}

void Ocean::addObjects(std::size_t count) {
    std::vector<std::size_t> indices(M * N);
    std::iota(indices.begin(), indices.end(), std::size_t {});
    std::random_device rd;
    std::mt19937 gen { rd() };  // NOLINT
    std::shuffle(indices.begin(), indices.end(), gen);

    std::uniform_int_distribution<> dist {1, 100};  // NOLINT

    for (std::size_t i = 0; i < count; ++i) {
        auto idx = indices[i];
        Pair coords { idx % M, idx / M };  // NOLINT
        auto cell = cells[coords.y][coords.x];
        auto prob = dist(gen);
        std::shared_ptr<Object> object;
        if (prob > 10 && prob <= 20) {
            object = createObject(ObjType::STONE, cell);
        } else if (prob <= 60) {
            object = createObject(ObjType::PREY, cell);
        } else {
            object = createObject(ObjType::PREDATOR, cell);
        }
        stuff.push_back(object);
        cell->setObject(object);
    }
}

void Ocean::addObject(const std::shared_ptr<Object>& object) {
    stuff.push_back(object);
}

void Ocean::run(const std::size_t cycleCount) {
    for (int i = 0; i < cycleCount; ++i) {
        for (const auto& obj : stuff) {
            if (!obj->isRemoved())
                obj->live();
        }
        stuff.erase(std::remove_if(stuff.begin(), stuff.end(),
            [](const std::shared_ptr<Object> &object) {
                return object->isRemoved();
            }), stuff.end());
        print();

        if (!std::count_if(stuff.begin(), stuff.end(),
            [](const std::shared_ptr<Object>& object) {
                return object->type() == ObjType::PREDATOR;
            }) || !std::count_if(stuff.begin(), stuff.end(),
                [](const std::shared_ptr<Object>& object) {
                    return object->type() == ObjType::PREY;
            }))
            return;

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

std::vector<std::weak_ptr<Cell>> Ocean::getAdjacent(const Pair coords) const {
    std::vector<std::weak_ptr<Cell>> result;
    auto addAdjacentIfExists = [&result, this](coord_t x, coord_t y) {
        if (y >= 0 && y < N && x >= 0 && x < M)
            result.push_back(cells[y][x]);
    };
    addAdjacentIfExists(coords.x - 1, coords.y);
    addAdjacentIfExists(coords.x + 1, coords.y);
    addAdjacentIfExists(coords.x, coords.y - 1);
    addAdjacentIfExists(coords.x, coords.y + 1);

    return result;
}

void Ocean::removeObject(std::weak_ptr<Object> object) {
    object.lock()->markAsRemoved();
}
