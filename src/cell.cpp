// Copyright 2020 PollyllyZh
#include "cell.h"
void Cell::init(Pair p, Ocean* oc) {
    this->ocean = oc;
    this->crd = p;
}
Object* Cell::get_object() {
    return object;
}
Ocean* Cell::get_ocean() {
    return ocean;
}
void Cell::set_object(Object* obj) {
    object = obj;
}
void Cell::killMe() {
    if (object) {
        delete object;
        object = nullptr;
    }
}
Cell* Cell::get_free_cell() {
    return ocean->find_empty(crd);
}
Cell* Cell::get_prey() {
    return ocean->find_prey(crd);
}
