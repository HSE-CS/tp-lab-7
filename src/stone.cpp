// Copyright 2020 PollyllyZh
#include "stone.h"
#include "cell.h"
#include "object.h"
char Stone::get_symbol() {
    return STONE_N;
}
bool Stone::live() {
    if (!lifetime--) return false;
    return true;
}
