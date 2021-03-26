// Copyright dmitrycvetkov 2021
#include "common.h"

#include "object.h"

char toChar(const std::shared_ptr<Object> obj) {
    if (!obj)
        return ' ';
    switch (obj->type()) {
    case ObjType::STONE:
        return STONE_N;
    case ObjType::PREY:
        return PREY_N;
    case ObjType::PREDATOR:
        return PREDATOR_N;
    }
}
