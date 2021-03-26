// Copyright 2021 SharunovEvgeny
//
// Created by sharg on 20.03.2021.
//
#include "../include/ocean.h"

int main() {
  Ocean *oc = new Ocean();
  oc->fill();
  oc->print();
  oc->run();
}
