//// Copyright 2021 Lukicheva Polina

#ifndef OBJECT_H_
#define OBJECT_H_

#include "../include/common.h"
#include "../include/ocean.h"
#include "../include/object.h"
#include "../include/cell.h"

#define STONE_N '#'
#define CORAL_N '*'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum class ObjType { STONE, CORAL, PREY, PREDATOR };

#endif  // OBJECT_H_
