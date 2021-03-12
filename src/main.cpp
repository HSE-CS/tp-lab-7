// copyright 2021 JediCouncil

#include <windows.h>
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
    system("color 07");

    Movie::setStartDisplayCondition();
    Movie::setStartDisplayColors();
    Movie::renderStartDisplay();
    playMusicFile("cxx_intro_1.wav");
    Movie::wait(1.25);
    Scene s(INTRO);
    s.render(10, true);
    Movie::wait(1.75);
    Scene l(LIGHTSABER);
    stopMusic();
    playMusicFile("saber_on_1.wav");
    l.render(10, true);
    Movie::wait(2);
    stopMusic();
    Scene f(ALONGTIMEAGO);
    f.render(3 * 1000, true);
    Movie::renderStartDisplay();
    Movie::setDisplayToSpace();
    Movie::renderSpaceDisplay();
    Scene sw(STARWARSTITLE);
    playMusicFile("starwars_theme.wav");
    sw.render(450, true);
    Movie::setAreaToNormalCondition(93, 28, 102, 32);
    Scene st(STARTCREDITS);
    st.render(500, true);
    Movie::setAreaToNormalCondition(80, 25, 120, 35);
    Movie::wait(30);

//    Scene t(TEST);
//    t.render(1000, false);

    system("color 07");
    return 0;
}

// g++ -std=c++17 src/main.cpp include/scenes.h include/common.h include/Objects.h include/Space.h src/Objects.cpp src/Space.cpp -o main -w -pthread -lWinmm
