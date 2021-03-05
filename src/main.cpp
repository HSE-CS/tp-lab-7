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

    Movie::setStartDisplayCondition();
    Movie::setStartDisplayColors();
    Movie::renderStartDisplay();

    Scene s(TEST);
    s.render(1000);
    Scene t(TEST);
    t.render(1000);

    return 0;
}
