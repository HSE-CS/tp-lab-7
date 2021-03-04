// copyright 2021 JediCouncil

#include "../include/Objects.h"

/*

 common.h: all trash
 Space: class
 Objects: class set
 main.cpp

 */

template<typename T>
void print(T t) {
    std::cout << t << '\n';
}

signed main() {
//    TestShip t;
//
//    Object o(t);
//    print(o.getColors()[0][1]);

    Scene s(TEST);
    s.rawOut();

    return 0;
}