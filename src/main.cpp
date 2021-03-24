// copyright 2021 JediCouncil

#include <windows.h>
#include <ctime>
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

void genSpace() {
    std::random_device gen;
    for (int i = 0; i < displayHeight; ++i) {
        for (int j = 0; j < displayWidth; ++j) {
            displayColor[i][j] = cc(black, white);
            if (gen() % 20 == 0) {
                startSpacePicture[i][j] = '*';
            } else {
                startSpacePicture[i][j] = ' ';
            }
        }
    }
}

void intro() {
    ShowConsoleCursor(false);

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
    system("color 07");
}

void game() {
    genSpace();
    srand(time(NULL));
    ShowConsoleCursor(false);
    std::random_device gen;
    std::mt19937 gen2(rand());
//    Movie::setDisplayToSpace();
//    Movie::renderSpaceDisplay();
    Space s;
    s.generateAsteroidField(20);
    for (auto x : *s.getObjects()) {
        x->render(x->getPosX(), x->getPosY());
        s.setCellsForObject(x);
    }
    s.generateArmy(5, 5);
    for (int i = 0; i < 1000; ++i) {
        for (auto x : *s.getObjects()) {
            s.move(x, i);
            if (gen2() % 20 == 0 && x->getSpeed() != SUPER && x->getSpeed() != ULTRA_LOW)
                x->turn(gen2() % 3 - 1);
            if (x->getEnergy() <= 0)
                s.destroyWithExplosion(x);
            if (x->getSpeed() == SUPER) {
                auto t = s.scan(x);
                if (t != nullptr) {
                    s.destroy(x);
                    t->setEnergy(t->getEnergy() - 1000);
                }
            }
        }
        for (auto x : *s.getObjects()) {
            if (x->getSpeed() != SUPER && x->getSpeed() != ZERO_SPEED) {
                auto t = s.scan(x, 20);
                if (t != nullptr) {
                    if (t->getSpeed() != SUPER) {
                        auto w = Space::shoot(x);
                        w->setEnergy(30);
                        s.addObject(w);
                        if (t->getDirection() == (x->getDirection() + 2) % 4 && t->getSpeed() != ZERO_SPEED) {
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
        Movie::wait(0.01);
        if (s.countSideObject(REBELS) == 0) {
            playMusicFile("imperytheme.wav");
            Movie::renderImperyWin();
            break;
        } else if (s.countSideObject(IMPERY) == 0) {
            playMusicFile("rebelstheme2.wav");
            Movie::renderRebelsWin();
            break;
        }
    }
}

signed main() {
    intro();
    game();
    Movie::wait(30);

    return 0;
}

// g++ -std=c++17 src/main.cpp include/scenes.h include/common.h include/Objects.h include/Space.h src/Objects.cpp src/Space.cpp -o main -w -pthread -lWinmm
