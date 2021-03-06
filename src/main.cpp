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

    Scene s(INTRO);
    s.render(1, true);

    Movie::renderStartDisplay();

//    Scene t(TEST);
//    t.render(1000, false);

    system("color 07");
    return 0;
}

// g++ -std=c++17 src/main.cpp include/scenes.h include/common.h include/Objects.h include/Space.h src/Objects.cpp src/Space.cpp -o main -w
