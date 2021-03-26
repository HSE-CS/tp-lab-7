// Copyright 2020 PollyllyZh
#include "object.h"
Cell* Object::get_cell() {
    return cell;
}
ObjType Object::get_type() {
    return obj_type;
}
void Object::set_lifetime(uint lt) {
    lifetime = lt;
}
