// Copyright 2020 PollyllyZh
#include "../include/stone.h"
#include "../include/cell.h"
#include "../include/object.h"
char Stone::get_symbol() {
    return STONE_N;
}
bool Stone::live() {
    if (!lifetime--) return false;
    return true;
}
