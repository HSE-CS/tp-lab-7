// Copyright dmitrycvetkov 2021
#include "object_factory.h"

#include "object.h"
#include "stone.h"
#include "prey.h"
#include "predator.h"

std::unique_ptr<Object> createObject(ObjType type, std::weak_ptr<Cell> cell) {
    switch (type) {
    case ObjType::STONE:
        return std::unique_ptr<Object>(new Stone(std::move(cell)));
    case ObjType::PREY:
        return std::unique_ptr<Object>(new Prey(std::move(cell)));
    case ObjType::PREDATOR:
        return std::unique_ptr<Object>(new Predator(std::move(cell)));
    }
}
