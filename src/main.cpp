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
    playMusicFile("cxx_intro_1.wav");
    Scene s(INTRO);
    s.render(1, true);
    Movie::wait(2);

    Scene l(LIGHTSABER);
    stopMusic();
    playMusicFile("saber_on_1.wav");
    l.render(10, true);
    Movie::wait(1.5);
    stopMusic();
    Scene f(ALONGTIMEAGO);
    f.render(3 * 1000, true);
    Movie::renderStartDisplay();
    Movie::setDisplayToSpace();
    Movie::renderSpaceDisplay();
    Scene sw(STARWARSTITLE);
    playMusicFile("starwars_theme.wav");
    sw.render(10000, true);


//    Movie::wait(3);

//    Movie::renderStartDisplay();

//    Scene t(TEST);
//    t.render(1000, false);

    system("color 07");
    return 0;
}

// g++ -std=c++17 src/main.cpp include/scenes.h include/common.h include/Objects.h include/Space.h src/Objects.cpp src/Space.cpp -o main -w -pthread -lWinmm
