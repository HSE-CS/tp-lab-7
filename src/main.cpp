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

void movie() {
    /*ShowConsoleCursor(false);-

    setlocale(LC_ALL, "Russian");

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
    st.render(400, true);
    Movie::setAreaToNormalCondition(80, 25, 120, 35);
    Movie::renderIntroduction();
    ShowConsoleCursor(true);
    system("color 07");*/
}

signed main() {
    // movie();
    Movie::setDisplayToSpace();
    Movie::renderSpaceDisplay();
    Space s;
    Object a(XWing(), HIGH_SPEED);
    Object b(TieFighter(), MEDIUM_SPEED);
    a.setPosX(10);
    b.setPosX(10);
    a.setPosy(50);
    b.setPosy(10);
    b.setDirection(DOWN);
    s.addObject(&a);
    s.addObject(&b);
    for (int i = 0; i < 120; ++i) {
//        if (i == 55) {
//            setCursorPosition(0, 0);
//            setConsoleColour(cc(black, white));
//            for (int j = 0; j < displayHeight; j++) {
//                for (int k = 0; k < displayWidth; ++k) {
//                    if (s.getCell(k, j)->getObject() == nullptr) {
//                        std::cout << ".";
//                    } else
//                        std::cout << "#";
//                }
//                std::cout << "\n";
//            }
//            throw;
        for (auto x : *s.getObjects()) {
            s.move(x, i);
            if (x->getEnergy() <= 0)
                s.removeObject(x);
            if (x->getSpeed() == SUPER) {
                auto t = s.scan(x);
                if (t != nullptr) {
                    s.hit(x, t);
                }
            }
        }
        for (auto x : *s.getObjects()) {
            if (x->getSpeed() != SUPER) {
                auto t = s.scan(x, 20);
                if (t != nullptr) {
                    if (t->getSpeed() != SUPER) {
                        auto w = Space::shoot(x);
                        w->setEnergy(30);
                        s.addObject(w);
                        if (t->getDirection() == (x->getDirection() + 2) % 4) {
                            w = Space::shoot(t);
                            w->setEnergy(50);
                            s.addObject(w);
                        }
                        x->turn(1);
                        break;
                    }
                }
            }
        }
        Movie::wait(0.1);
    }


    return 0;
}

// g++ -std=c++17 src/main.cpp include/scenes.h include/common.h include/Objects.h include/Space.h src/Objects.cpp src/Space.cpp -o main -w -pthread -lWinmm
