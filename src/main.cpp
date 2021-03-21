#include "cell.h"
#include "common.h"
#include "Ocean.h"
#include "Predator.h"
#include "prey.h"
#include "stone.h"
#include <iostream>
#include <cstdlib>
#include <list>
#include "windows.h"

int main() {
    Ocean a(40, 80);
    a.addObjects(60, 10, 5);
    HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hd, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hd, &structCursorInfo);
    COORD cd;
    cd.X = 0;
    cd.Y = 0;
    int PreyCounter = 0;
    int PredatorCounter = 0;
    for (int i = 0; i < 100; ++i) {
        a.run();
        a.print();
        for (Object* obj : a.getStuff()) {
            if (obj->getType() == ObjType::PREY)
                ++PreyCounter;
            else if (obj->getType() == ObjType::PREDATOR)
                ++PredatorCounter;
        }
        std::cout << PreyCounter << "-----" << PredatorCounter << std::endl;
        std::cout << i << std::endl;
        if (!PreyCounter) {
            std::cout << "There's no more preyers" << std::endl;
            break;
        }
        else if (!PredatorCounter) {
            std::cout << "There's no more predators" << std::endl;
            break;
        }
        PredatorCounter = 0;
        PreyCounter = 0;
        Sleep(200);
        SetConsoleCursorPosition(hd, cd);
    }
    /*std::list<int> a{ 1,10,12,124,3,215,2,5,346,35 };
    for (auto it = a.begin(); it != a.end(); ++it) {
        if(*it==10)
            it = a.erase(it);
    }
    for (auto it : a) {
        std::cout << it << std::endl;
    }*/
}