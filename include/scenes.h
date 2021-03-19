//
// Created by Данил on 04.03.2021.
//

#ifndef TP_LAB_7_SCENES_H
#define TP_LAB_7_SCENES_H

#include <iostream>
#include <map>
#include <string>
#include <random>
#include <windows.h>
#include <MMSystem.h>

static const int displayHeight = 60;
static const int displayWidth = 200;

//static const int displayHeight = 30;
//static const int displayWidth = 50;

static void playMusicFile(char *name) {
    PlaySound(name, NULL, SND_FILENAME | SND_ASYNC);
}

static void stopMusic() {
    PlaySound(NULL, 0, 0);
}

enum SceneNumber {
    TEST,
    INTRO,
    LIGHTSABER,
    ALONGTIMEAGO,
    STARWARSTITLE,
    STARTCREDITS,
    ENDCREDITS,
};

static std::string to_dos(std::string from) {
    char buffer[1000];
    OemToCharA(from.c_str(), buffer);
    return buffer;
}

enum Color {
    black = 0,
    dark_blue = 1,
    dark_green = 2,
    dark_aqua, dark_cyan = 3,
    dark_red = 4,
    dark_purple = 5, dark_pink = 5, dark_magenta = 5,
    dark_yellow = 6, orange = 6,
    dark_white = 7,
    gray = 8,
    blue = 9,
    green = 10,
    aqua = 11, cyan = 11,
    red = 12,
    purple = 13, pink = 13, magenta = 13,
    yellow = 14,
    white = 15
};

static int cc(int background, int foreground) {
    return abs((background << 4) + foreground);
}

static int _c_bl_bl = cc(0, 0);
static int _c_bl_wh = cc(0, 0xf);
static int _c_bl_lgr = cc(0, 0x7);
static int _c_bl_gr = cc(0, 0x8);
static int _c_bl_ye = cc(0, 0xe);

namespace __s_logo_back {

    static char starWarsLogo[37][169] = {
        "                             xxxxXXXxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxXX      XXXXXXXXXXXX           XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX                         ",
        "                            xxxxxXXXxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxXX     XXXXXXXXXXXXXX          XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX                        ",
        "                           xxxxxxXXXxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxXX     XXXXXXXXXXXXXX          XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX                       ",
        "                          xxxxxxxXXXxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxXX    XXXXXXXXXXXXXXXX         XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX                      ",
        "                         xxxxxxxxXXXxxxx              XXXXXXXXXX                       XXXXXXXXXXXXXXXX         XXXXXXXXX                 XXXXXXXXX                     ",
        "                         xxxxxxxxXXXxx                XXXXXXXXXX                      XXXXXXXXXXXXXXXXXX        XXXXXXXXX                  XXXXXXXX                     ",
        "                         xxxxxxxxXXXxxx               XXXXXXXXXX                      XXXXXXXX  XXXXXXXX        XXXXXXXXX                 XXXXXXXXX                     ",
        "                          xxxxxxxXXXxxxx              XXXXXXXXXX                     XXXXXXXXX  XXXXXXXXX       XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX                      ",
        "                           xxxxxxXXXxxxxx             XXXXXXXXXX                     XXXXXXXX    XXXXXXXX       XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX                       ",
        "                            xxxxxXXXxxxxxx            XXXXXXXXXX                    XXXXXXXXX    XXXXXXXXX      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX                        ",
        "                             xxxxXXXxxxxxxx           XXXXXXXXXX                    XXXXXXXX      XXXXXXXX      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX                         ",
        "                              xxxXXXxxxxxxxx          XXXXXXXXXX                   XXXXXXXXXXXXXXXXXXXXXXXX     XXXXXXXXXXXXXXXXXXXX                                    ",
        "                               xxXXXxxxxxxxx          XXXXXXXXXX                   XXXXXXXXXXXXXXXXXXXXXXXX     XXXXXXXXXXXXXXXXXXXXXXX                                 ",
        "                              xxxXXXxxxxxxxx          XXXXXXXXXX                  XXXXXXXXXXXXXXXXXXXXXXXXXX    XXXXXXXXX XXXXXXXXXXXXXXXX                              ",
        "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxXXXxxxxxxx           XXXXXXXXXX                  XXXXXXXX          XXXXXXXX    XXXXXXXXX    XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
        "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxXXXxxxxxx            XXXXXXXXXX                 XXXXXXXXX          XXXXXXXXX   XXXXXXXXX       XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
        "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxXXXxxxxx             XXXXXXXXXX                 XXXXXXXX            XXXXXXXX   XXXXXXXXX          XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
        "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxXXXxxxx              XXXXXXXXXX                 XXXXXXXX            XXXXXXXX   XXXXXXXXX             XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
        "                                                                                                                                                                        ",
        "XXXXXXXXX            XXXXXXXXXXXXXX            XXXXXXXXX        XXXXXXXXXXXX           XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX           xxxXXXxxxxxxxxxXXXXXXXXXXXXXXXXXXXXXXXX",
        "XXXXXXXXXX          XXXXXXXXXXXXXXXX          XXXXXXXXXX       XXXXXXXXXXXXXX          XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX         xxxxXXXxxxxxxxxxXXXXXXXXXXXXXXXXXXXXXXXX",
        "XXXXXXXXXX          XXXXXXXXXXXXXXXX          XXXXXXXXXX       XXXXXXXXXXXXXX          XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX       xxxxxXXXxxxxxxxxxXXXXXXXXXXXXXXXXXXXXXXXX",
        " XXXXXXXXXX         XXXXXXXXXXXXXXXXX         XXXXXXXXX       XXXXXXXXXXXXXXXX         XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX     xxxxxxXXXxxxxxxxxxXXXXXXXXXXXXXXXXXXXXXXXX",
        " XXXXXXXXXX        XXXXXXXXXXXXXXXXXX        XXXXXXXXXX       XXXXXXXXXXXXXXXX         XXXXXXXXX                 XXXXXXXXX   xxxxxxxXXXxxxxx                            ",
        "  XXXXXXXXXX      XXXXXXXXXXXXXXXXXXXX      XXXXXXXXXX       XXXXXXXXXXXXXXXXXX        XXXXXXXXX                  XXXXXXXX   xxxxxxxXXXxxx                              ",
        "  XXXXXXXXXX      XXXXXXXXXXXXXXXXXXXX      XXXXXXXXXX       XXXXXXXX  XXXXXXXX        XXXXXXXXX                 XXXXXXXXX   xxxxxxxXXXxxxx                             ",
        "   XXXXXXXXXX    XXXXXXXXXX  XXXXXXXXXX    XXXXXXXXXX       XXXXXXXXX  XXXXXXXXX       XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX     xxxxxxXXXxxxxx                            ",
        "   XXXXXXXXXX    XXXXXXXXXX  XXXXXXXXXX    XXXXXXXXXX       XXXXXXXX    XXXXXXXX       XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX       xxxxxXXXxxxxxx                           ",
        "    XXXXXXXXXX  XXXXXXXXXX    XXXXXXXXXX  XXXXXXXXXX       XXXXXXXXX    XXXXXXXXX      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX         xxxxXXXxxxxxxx                          ",
        "    XXXXXXXXXX  XXXXXXXXXX    XXXXXXXXXX  XXXXXXXXXX       XXXXXXXX      XXXXXXXX      XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX           xxxXXXxxxxxxxx                         ",
        "     XXXXXXXXXXXXXXXXXXXX      XXXXXXXXXXXXXXXXXXXX       XXXXXXXXXXXXXXXXXXXXXXXX     XXXXXXXXXXXXXXXXXXXX                       xxXXXxxxxxxxxx                        ",
        "     XXXXXXXXXXXXXXXXXXXX      XXXXXXXXXXXXXXXXXXXX       XXXXXXXXXXXXXXXXXXXXXXXX     XXXXXXXXXXXXXXXXXXXXXXX                     xXXXxxxxxxxxx                        ",
        "      XXXXXXXXXXXXXXXXXX        XXXXXXXXXXXXXXXXXX       XXXXXXXXXXXXXXXXXXXXXXXXXX    XXXXXXXXX XXXXXXXXXXXXXXXX                 xxXXXxxxxxxxxx                        ",
        "      XXXXXXXXXXXXXXXXXX        XXXXXXXXXXXXXXXXXX       XXXXXXXX          XXXXXXXX    XXXXXXXXX    XXXXXXXXXXXXXXXXXXXXXXxxxxxxxxxxXXXxxxxxxxx                         ",
        "       XXXXXXXXXXXXXXXX          XXXXXXXXXXXXXXXX       XXXXXXXXX          XXXXXXXXX   XXXXXXXXX       XXXXXXXXXXXXXXXXXXXxxxxxxxxxxXXXxxxxxxx                          ",
        "       XXXXXXXXXXXXXXXX          XXXXXXXXXXXXXXXX       XXXXXXXX            XXXXXXXX   XXXXXXXXX          XXXXXXXXXXXXXXXXxxxxxxxxxxXXXxxxxxx                           ",
        "        XXXXXXXXXXXXXX            XXXXXXXXXXXXXX        XXXXXXXX            XXXXXXXX   XXXXXXXXX             XXXXXXXXXXXXXxxxxxxxxxxXXXxxxxx                            ",
    };

    static char startCredits[30][130 + 1]{
        "                                                                                                                                  ",
        "                                                                                                                                  ",
        "                              xxxxxx                xxxxx                  xx              xxx     xxx                            ",
        "                              xxxxxx           xx  xxxxxxx                 xx   xxxxx       xxx   xxx                             ",
        "                              xx      xx xxx       xx        xxxxxx    xxx xx  xxxxxxx       xxx xxx                              ",
        "                              xxxxx   xxxxxxx  xx  xxxxxx   xxxxxxxx  xxxxxxx  xx   xx        xxxxx                               ",
        "                              xxxxx   xxx  xx  xx   xxxxxx  xx    xx  xx   xx  xxxxxx         xxxxx                               ",
        "                              xx      xxxxxxx  xx       xx  xx    xx  xx   xx  xx            xxx xxx                              ",
        "                              xxxxxx  xxxxxx   xx  xxxxxxx  xxxxxxxx  xxxxxxx  xxxxxxx      xxx   xxx                             ",
        "                              xxxxxx  xx       xx   xxxxx    xxxxxx    xxxxxx   xxxxx      xxx     xxx                            ",
        "                                      xx                                                                                          ",
        "                                      xx                                                                                          ",
        "                                                                                                                                  ",
        "                                                                                                                                  ",
        "xxxxxx   xxxxxx xx   xx xxxxxx xxx   xx xxxxxxx xxxxxx    xxxxx  xxxxxx   xxxxxxxx xx  xx xxxxxx    xxxxx   xxxxx  xxxxxx   xxxxxx",
        "xxxxxxx  xxxxxx xx   xx xxxxxx xxxx  xx xxxxxxx xxxxxx   xxxxxxx xxxxxx   xxxxxxxx xx  xx xxxxxx   xxxxxxx xxxxxxx xxxxxxx  xxxxxx",
        "xx   xx  xx     xx   xx xx     xxxx  xx xx      xx       xx   xx xx          xx    xx  xx xx       xx   xx xx   xx xx  xxx  xx    ",
        "xxxxxxx  xxxxx  xx   xx xxxxx  xxxxx xx xx      xxxxx    xx   xx xxxxx       xx    xxxxxx xxxxx    xx      xx   xx xx   xxx xxxxx ",
        "xxxxxx   xxxxx   xx xx  xxxxx  xx xxxxx xx  xxx xxxxx    xx   xx xxxxx       xx    xxxxxx xxxxx    xx      xx   xx xx   xxx xxxxx ",
        "xxxxx    xx      xx xx  xx     xx  xxxx xx   xx xx       xx   xx xx          xx    xx  xx xx       xx   xx xx   xx xx  xxx  xx    ",
        "xx xxx   xxxxxx  xxxxx  xxxxxx xx  xxxx xxxxxxx xxxxxx   xxxxxxx xx          xx    xx  xx xxxxxx   xxxxxxx xxxxxxx xxxxxxx  xxxxxx",
        "xx  xxxx xxxxxx   xxx   xxxxxx xx   xxx xxxxxxx xxxxxx    xxxxx  xx          xx    xx  xx xxxxxx    xxxxx   xxxxx  xxxxxx   xxxxxx",
        "                                                                                                                                  ",
        "                                                                                                                                  ",
    };

    static char bodySymbol = 'a';

    static char filler = 'X';

    static const char cxx_logo[20][60 + 1]{
        "                                                            ",
        "      aaaaaaaaaa                                            ",
        "     aaaaaaaaaaaa                                           ",
        "    aaaaaaaaaaaaa           aaa                aaa          ",
        "    aaaa      aaa           aaa                aaa          ",
        "    aaa                     aaa                aaa          ",
        "    aaa                aaaaaaaaaaaaa      aaaaaaaaaaaaa     ",
        "    aaa                aaaaaaaaaaaaa      aaaaaaaaaaaaa     ",
        "    aaa                aaaaaaaaaaaaa      aaaaaaaaaaaaa     ",
        "    aaa                     aaa                aaa          ",
        "    aaaa      aaa           aaa                aaa          ",
        "    aaaaaaaaaaaaa           aaa                aaa          ",
        "     aaaaaaaaaaaa                                           ",
        "      aaaaaaaaaa                                            ",
        "                                                            ",
    };

    static char farFar[displayHeight][displayWidth + 1] = {
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                   xxx                  x  x       xxx               x                         x x                                                                      ",
        "                                                   x x  x xxx xxx xxx  xxx   xxxxx x x  xxx xxx xxx    xxx  xxx  xxx xxx x xxx x x x x  xxx xxx x x                                                     ",
        "                                                   xxx  x x x x x x x   x  x x x x xxx  x x x x x x  x x x  x x  x x x x x x x  x  x x  x   x x xx                                                      ",
        "                                                   x x  x x x x x xxx   x  x x x x x    xxx xxx x x  x x x  xxx  xxx xxx x xxx x x xxx  xx  xxx x                                                       ",
        "                                                   x x  x xxx x x   x   xx x x x x xxx  x x   x xxx  x x x  x x    x x x x x x x x   x  x   x x x   x                                                   ",
        "                                                                  xxx                       xxx                  xxx               xxx              x                                                   ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                   xxx xxx x x  xxx x   x xxx x x                                                                                                                       ",
        "                                                   x   x x xx   x x x x x x x x x                                                                                                                       ",
        "                                                   xx  xxx x    xxx x x x xxx xxx                                                                                                                       ",
        "                                                   x   x x x    x x xxxxx x x   x x x x                                                                                                                 ",
        "                                                                              xxx                                                                                                                       ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
        "                                                                                                                                                                                                        ",
    };

    static const char light_saber[6][60 + 1]{
        "                                                            ",
        "    cc         cc                                           ",
        "    ccabbaaabbacc                                           ",
        "    ccabbbbbbbacc                                           ",
        "    cc         cc                                           ",
        "                                                            ",
    };

    static const char plasma[6][6 + 1]{
        "cccc  ",
        "bbbcc ",
        "aabbcc",
        "aabbcc",
        "bbbcc ",
        "cccc  ",
    };

    static std::string introduction[14]{
        "SESSION! Software engineering shudders under attack",
        "ruthless master of algorithms, Count BYCHKOV.",
        "Students fight on both sides.",
        "Deadlines are everywhere.",
        "",
        "Backed by an army of undergraduates, the merciless",
        "General FEDOTKIN infiltrated the capital of HSE - Rodionova",
        "and stole all the grades -",
        "last hope for a SKIDKA",
        " ",
        "While the undergraduate army tries to hide",
        "from the building on Rodionova Street,",
        "2 DSC KNIGHTS aboard 'Fusion-1' perform",
        "mission to rescue lost credits...",
    };


    static int sceneNumber = 0;
    static int lsSceneNumber = 0;
    static int SWSceneNumber = 0;
    static int STSceneNumber = 0;

    static int angleProp = 100;

    static int c1 = cc(gray, dark_white);
    static int c2 = cc(dark_white, white);
    static int c3 = cc(white, green);
    static int c4 = cc(green, dark_green);
    static int c5 = cc(dark_green, gray);
    static int c6 = cc(gray, black);
    static int c7 = cc(black, gray);

    template<std::size_t U, std::size_t V>
    static void changeLogoCondition(
        char (&scene)[U][V],
        int (&color)[U][V], int sizeX
    ) {
        for (int i = 0; i < 15; ++i) {
            for (int j = sceneNumber + i; j > sceneNumber - 3; --j) {
                if (j > -1 && j + i / angleProp < sizeX) {
                    if (cxx_logo[i][j + i / angleProp] == bodySymbol) {
                        scene[i][j + i / angleProp] = filler;
                        color[i][j + i / angleProp] = c1;
                    }
                }
            }
            for (int j = sceneNumber - 3 + i; j > sceneNumber - 6; --j) {
                if (j > -1 && j + i / angleProp < sizeX) {
                    if (cxx_logo[i][j + i / angleProp] == bodySymbol) {
                        scene[i][j + i / angleProp] = filler;
                        color[i][j + i / angleProp] = c2;
                    }
                }
            }
            for (int j = sceneNumber - 6 + i; j > sceneNumber - 9; --j) {
                if (j > -1 && j + i / angleProp < sizeX) {
                    if (cxx_logo[i][j + i / angleProp] == bodySymbol) {
                        scene[i][j + i / angleProp] = filler;
                        color[i][j + i / angleProp] = c3;
                    }
                }
            }
            for (int j = sceneNumber - 9 + i; j > sceneNumber - 12; --j) {
                if (j > -1 && j + i / angleProp < sizeX) {
                    if (cxx_logo[i][j + i / angleProp] == bodySymbol) {
                        scene[i][j + i / angleProp] = filler;
                        color[i][j + i / angleProp] = c4;
                    }
                }
            }
            for (int j = sceneNumber - 12 + i; j > sceneNumber - 15; --j) {
                if (j > -1 && j + i / angleProp < sizeX) {
                    if (cxx_logo[i][j + i / angleProp] == bodySymbol) {
                        scene[i][j + i / angleProp] = filler;
                        color[i][j + i / angleProp] = c5;
                    }
                }
            }
            for (int j = sceneNumber - 15 + i; j > sceneNumber - 18; --j) {
                if (j > -1 && j + i / angleProp < sizeX) {
                    if (cxx_logo[i][j + i / angleProp] == bodySymbol) {
                        scene[i][j + i / angleProp] = filler;
                        color[i][j + i / angleProp] = c6;
                    }
                }
            }
            for (int j = sceneNumber - 18 + i; j > -1; --j) {
                if (cxx_logo[i][j + i / angleProp] == bodySymbol) {
                    scene[i][j + i / angleProp] = filler;
                    color[i][j + i / angleProp] = c7;
                }
            }
        }
        sceneNumber++;
    }

    template<std::size_t U, std::size_t V>
    static void setLightsaberCondition(
        char (&scene)[U][V],
        int (&color)[U][V], int sizeX
    ) {
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < sizeX; ++j) {
                if (light_saber[i][j] == 'a') {
                    color[i][j] = cc(gray, black);
                }
                if (light_saber[i][j] == 'b') {
                    color[i][j] = cc(dark_white, black);
                }
                if (light_saber[i][j] == 'c') {
                    color[i][j] = cc(white, black);
                }
            }
        }
    }

    static std::map<char, int> lColor{
        {'a', cc(white, black)},
        {'b', cc(red, black)},
        {'c', cc(dark_red, black)}
    };

    template<std::size_t U, std::size_t V>
    static void changeLightsaberCondition(
        char (&scene)[U][V],
        int (&color)[U][V], int sizeX
    ) {
        if (lsSceneNumber == 0) {
            lsSceneNumber++;
            setLightsaberCondition(scene, color, sizeX);
            return;
        }
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 6; ++j) {
                color[i][j + 17 + lsSceneNumber] = lColor[plasma[i][j]];
            }
        }
        lsSceneNumber++;
    }

    template<std::size_t U, std::size_t V>
    static void setFarFarAway(
        char (&scene)[U][V],
        int (&color)[U][V], int sizeX
    ) {

        for (int i = 0; i < displayHeight; ++i) {
            for (int j = 0; j < displayWidth; ++j) {
                if (farFar[i][j] == 'x') {
                    // scene[i][j];
                    color[i][j] = cc(blue, black);
                } else {
                    color[i][j] = cc(black, black);
                }
                // scene[i][j] = ' ';
            }
        }
    }

    template<std::size_t U, std::size_t V>
    static void reduceStarWarsLogo(
        char (&scene)[U][V],
        int (&color)[U][V], int framesCount
    ) {
        if (SWSceneNumber == 0) {
            SWSceneNumber++;
            return;
        }
        int newX = (168 * (framesCount - SWSceneNumber)) / framesCount;
        int newY = (37 * (framesCount - SWSceneNumber)) / framesCount;
        for (int i = 0; i < U; ++i) {
            for (int j = 0; j < V - 1; ++j) {
                color[i][j] = -1;
            }
        }
        int paddingX, paddingY;
        paddingY = 18 - (18 * (framesCount - SWSceneNumber)) / framesCount;
        paddingX = 84 - (84 * (framesCount - SWSceneNumber)) / framesCount;
        for (int i = 0; i < newY; ++i) {
            for (int j = 0; j < newX; ++j) {
                int indI = (i * (37 - 1)) / newY;
                int indJ = (j * (168 - 1)) / newX;
                char s = starWarsLogo[indI][indJ];
                if (s == 'X' or s == 'x') {
                    color[(i + paddingY) % 37][(j + paddingX) % 168] = cc(yellow, black);
                } else {
                    color[(i + paddingY) % 37][(j + paddingX) % 168] = -1;
                }
            }
        }
        SWSceneNumber++;
    }

    template<std::size_t U, std::size_t V>
    static void setStarWars(
        char (&scene)[U][V],
        int (&color)[U][V], int sizeX
    ) {
        if (SWSceneNumber == 0) {
            for (int i = 0; i < displayHeight; ++i) {
                for (int j = 0; j < displayWidth; ++j) {
                    if (starWarsLogo[i][j] == 'x' or starWarsLogo[i][j] == 'X') {
                        color[i][j] = cc(yellow, black);
                    } else {
                        color[i][j] = -1;
                    }
                }
            }
        }
        reduceStarWarsLogo(scene, color, 20);
    }

    static char bigTitle[60][260];


    template<std::size_t U, std::size_t V>
    static void reduceStartTitle(
        char (&scene)[U][V],
        int (&color)[U][V], int framesCount
    ) {
        if (STSceneNumber == 0) {
            {
                for (int i = 0; i < 60; ++i) {
                    for (int j = 0; j < 200; ++j) {
                        scene[i][j] = ' ';
                        color[i][j] = -1;
                    }
                }
            }
            for (int i = 0; i < 60; ++i) {
                for (int j = 0; j < 260; ++j) {
                    if (startCredits[i / 2][j / 2] == 'x') {
                        bigTitle[i][j] = 'x';
                    } else bigTitle[i][j] = ' ';
                }
            }
        } else {
            for (int i = 0; i < 60; ++i) {
                for (int j = 0; j < 200; ++j) {
                    color[i][j] = -1;
                }
            }
            int newX, newY;
            newX = ((200 * (framesCount - STSceneNumber)) / framesCount) * 1.5;
            newY = ((60 * (framesCount - STSceneNumber)) / framesCount) * 1.5;
            for (int i = 0; i < newY; ++i) {
                for (int j = 0; j < newX; ++j) {
                    int indI, indJ;
                    indI = (i * (60 - 1)) / newY;
                    indJ = (j * (260 - 1)) / newX;
                    char c = bigTitle[indI][indJ];
                    if (c == 'x') {
//                        scene[i][j];
                        int indI2 = i + 25 - (STSceneNumber * 25) / 30;
                        int indJ2 = j - 45 + (STSceneNumber - 1) * 4.5;
                        if (indI2 < 60 && indJ2 < 200 && indJ2 > -1) {
                            color[indI2][indJ2] = cc(yellow, black);
                        }
                    }
                }
            }
        }
        STSceneNumber++;
    }

}

typedef struct Frame {
    int sizeX;
    int sizeY;
    int xPadding;
    int yPadding;
    char **image;
    int **color;

    template<std::size_t U, std::size_t V>
    Frame(int x, int y, int xp, int yp, char(&img)[U][V], int (&col)[U][V], int scene) {

        if (scene == INTRO) {
            __s_logo_back::changeLogoCondition(img, col, x);
        }

        if (scene == LIGHTSABER) {
            __s_logo_back::changeLightsaberCondition(img, col, x);
        }

        if (scene == ALONGTIMEAGO) {
            __s_logo_back::setFarFarAway(img, col, x);
        }

        if (scene == STARWARSTITLE) {
            __s_logo_back::setStarWars(img, col, x);
        }

        if (scene == STARTCREDITS) {
            __s_logo_back::reduceStartTitle(img, col, 30);
        }

        this->sizeX = x;
        this->sizeY = y;
        this->xPadding = xp;
        this->yPadding = yp;
        this->image = new char *[y];
        for (int i = 0; i < y; ++i) {
            this->image[i] = new char[x + 1];
            for (int j = 0; j < x; ++j) {
                this->image[i][j] = img[i][j];
            }
        }
        this->color = new int *[y];
        for (int i = 0; i < y; ++i) {
            this->color[i] = new int[x + 1];
            for (int j = 0; j < x; ++j) {
                this->color[i][j] = col[i][j];
            }
        }
    }
} Frame;

namespace __s_test {
    static int framesCount = 4;

    static char image1[3][4] = {
        "***",
        "*  ",
        "*  ",
    };

    static int color1[3][4] = {
        {_c_bl_ye,        _c_bl_ye, cc(dark_green, cyan),},
        {_c_bl_ye,        -1,       -1},
        {cc(green, cyan), -1,       -1},
    };

    static char image2[3][4] = {
        " **",
        "** ",
        "*  ",
    };

    static int color2[3][4] = {
        {-1,             _c_bl_ye, cc(dark_purple, cyan),},
        {_c_bl_ye,       _c_bl_ye, -1,},
        {cc(pink, cyan), -1,       -1,},
    };

    static char image3[3][4] = {
        "  *",
        " **",
        "** ",
    };

    static int color3[3][4] = {
        {-1,             -1,       cc(dark_blue, cyan),},
        {-1,             _c_bl_ye, _c_bl_ye,},
        {cc(blue, cyan), _c_bl_ye, -1,},
    };

    static char image4[3][4] = {
        "  *",
        "  *",
        "***",
    };

    static int color4[3][4] = {
        {-1,                 -1,       cc(red, cyan),},
        {-1,                 -1,       _c_bl_ye,},
        {cc(dark_red, cyan), _c_bl_ye, _c_bl_ye,},
    };


    typedef struct __s_test_1 : public Frame {
        __s_test_1() : Frame(this->sizeX, this->sizeY, this->xPadding, this->yPadding, image1, color1, TEST) {}

        static const int sizeX = 3;
        static const int sizeY = 3;
        static const int xPadding = 1;
        static const int yPadding = 1;
    } __s_test_1;

    typedef struct __s_test_2 : public Frame {
        __s_test_2() : Frame(this->sizeX, this->sizeY, this->xPadding, this->yPadding, image2, color2, TEST) {}

        static const int sizeX = 3;
        static const int sizeY = 3;
        static const int xPadding = 2;
        static const int yPadding = 2;
    } __s_test_2;

    typedef struct __s_test_3 : public Frame {
        __s_test_3() : Frame(this->sizeX, this->sizeY, this->xPadding, this->yPadding, image3, color3, TEST) {}

        static const int sizeX = 3;
        static const int sizeY = 3;
        static const int xPadding = 3;
        static const int yPadding = 3;
    } __s_test_3;

    typedef struct __s_test_4 : public Frame {
        __s_test_4() : Frame(this->sizeX, this->sizeY, this->xPadding, this->yPadding, image4, color4, TEST) {}

        static const int sizeX = 3;
        static const int sizeY = 3;
        static const int xPadding = 4;
        static const int yPadding = 4;
    } __s_test_4;
}

namespace __s_intro {
    static int framesCount = 81;

    /*
const char image[][] = {

};

const int color[][] = {
};

typedef struct __s_intro_ : public Frame {
    __s_intro_() : Frame(this->sizeX, this->sizeY, this->xPadding, this->yPadding, image, color, type) {}

    static const int sizeX = ;
    static const int sizeY = ;
    static const int xPadding = ;
    static const int yPadding = ;
} __s_intro_;
     */

    static char image1[20][60 + 1]{};

    static int color1[20][60 + 1] = {
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
    };

    typedef struct __s_intro_ : public Frame {
        __s_intro_() : Frame(this->sizeX, this->sizeY, this->xPadding, this->yPadding, image1, color1, INTRO) {}

        static const int sizeX = 60;
        static const int sizeY = 20;
        static const int xPadding = 70;
        static const int yPadding = 20;
    } __s_intro_;

}

namespace __s_light_saber {
    static int framesCount = 38;

    static char image1[6][60 + 1]{};

    static int color1[6][60 + 1] = {
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
    };

    typedef struct __s_light_saber_ : public Frame {
        __s_light_saber_() : Frame(this->sizeX, this->sizeY, this->xPadding, this->yPadding, image1, color1,
                                   LIGHTSABER) {}

        static const int sizeX = 60;
        static const int sizeY = 6;
        static const int xPadding = 68;
        static const int yPadding = 37;
    } __s_light_saber_;
}

namespace __s_far_far_away {
    static int framesCount = 1;

    static char image1[displayHeight][displayWidth + 1]{};

    static int color1[displayHeight][displayWidth + 1] = {
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
    };

    typedef struct __s_far_far_away_ : public Frame {
        __s_far_far_away_() : Frame(this->sizeX, this->sizeY, this->xPadding, this->yPadding, image1, color1,
                                    ALONGTIMEAGO) {}

        static const int sizeX = displayWidth;
        static const int sizeY = displayHeight;
        static const int xPadding = 0;
        static const int yPadding = 0;
    } __s_far_far_away_;
}
namespace __s_star_wars_title {
    static int framesCount = 20;

    static char image1[displayHeight][displayWidth + 1]{};

    static int color1[displayHeight][displayWidth + 1] = {
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,},
    };

    typedef struct __s_star_wars_title_ : public Frame {
        __s_star_wars_title_() : Frame(this->sizeX, this->sizeY, this->xPadding, this->yPadding, image1, color1,
                                       STARWARSTITLE) {}

        static const int sizeX = 168;
        static const int sizeY = 37;
        static const int xPadding = 15;
        static const int yPadding = 10;
    } __s_star_wars_title_;
}

namespace __s_start_credits {
    static int framesCount = 30;

    static char image1[60][200 + 1]{' '};

    static int color1[60][200 + 1] = {-1};

    typedef struct __s_start_credits_ : public Frame {
        __s_start_credits_() : Frame(this->sizeX, this->sizeY, this->xPadding, this->yPadding, image1, color1,
                                     STARTCREDITS) {}

        static const int sizeX = 200;
        static const int sizeY = 35;
        static const int xPadding = 0;
        static const int yPadding = 25;
    } __s_start_credits_;
}

static char display[displayHeight][displayWidth + 1]{};

static int displayColor[displayHeight][displayWidth + 1]{};

static const char startSpacePicture[displayHeight + 150][displayWidth + 1 + 150] = {
    /* 0 */
    "                *            ***                      *                        *                 *             *  *    *       *      *       *                       *      *            *             ",
    /* 1 */
    "                     *                                    *                   *                     *                                    *  *     *                                                     ",
    /* 2 */
    "    *                *                   *      *          *                                                                                                          *                                 ",
    /* 3 */
    "                                                                                                 **                              *                                  **                  *               ",
    /* 4 */
    "                    *   *         *                                                  *            *                             *                                                                    *  ",
    /* 5 */
    "             *                  *                                 *                              *                         *  *                                             *                           ",
    /* 6 */
    "           *                                                           *                                           * *      *                              *  *                   * *                   ",
    /* 7 */
    "               *                    *              *     *                                                                                              **                                  *           ",
    /* 8 */
    "                 *                       *          *              *                 *         *     *       *             *                        *    *     *                         *              ",
    /* 9 */
    "     *                         *                          **     * *                                                                                                                                    ",
    /* 10 */
    "  *                                  * *                                                                         *           *  *        *                *                                            *",
    /* 11 */
    "       *               *         **     *                                    *    *                           *                       *            *              *    *                *       *       ",
    /* 12 */
    "      *                                               *          *                *                 *                            *                   *                                                  ",
    /* 13 */
    "     *        *                                *   *                 *                            *                            *             * *                                 *  *        *      *   ",
    /* 14 */
    " ** *              *                      *                                                                               *                          * *                           *                 *  ",
    /* 15 */
    "           *                                                *                       *                        *                   *         * *       *          *                                       ",
    /* 16 */
    "  * **                     *                            *                         *   *                                   *                                   *         *          *       *          **",
    /* 17 */
    "                *              *                                                                       *        *                   *             *                    *                                ",
    /* 18 */
    "                            *             *   *      *  *                                   *     *   *                                       *        ***         *         *                     *    ",
    /* 19 */
    "                          *          *           *               *       *     * *      *       *                                *   *                                        *                         ",
    /* 20 */
    "                    *         *                                                                            *            *             *         *                                               *     * ",
    /* 21 */
    "                           *             **      *         *           *                         *               *                          *    *      *                   *                    *      ",
    /* 22 */
    "                         *               *   *                       *               *   *         *                  *            *                    *                       *  *                *   ",
    /* 23 */
    " *                                                            *               **             *                             *            **               *     **       *               *    * * *      ",
    /* 24 */
    "               * *                                    *                   *     *       *                        *                      *   *            *           *                     * *          ",
    /* 25 */
    "    *                 *    *                               *           * *     *         **                                                                     **           **         *           *   ",
    /* 26 */
    "   *                                                        *             *      *                                                                   * *       *      *               *                 ",
    /* 27 */
    "                         *       *                *                                  **                   *                  *                 *             *                                          ",
    /* 28 */
    "                  * *   *      *    *                              *                          *  *                 *               *                       *                                 *  *    *  ",
    /* 29 */
    "                          *                                           *                  *                                      *                                                            *   *      ",
    /* 30 */
    "     *           *                                    *              *                              *                     *               *                    *       *        *  *    * *             ",
    /* 31 */
    "                         **  *              *                                            *      *    *                                  *                             *                 *             * ",
    /* 32 */
    "       *          *             *           *                 *  *                      *              *    *          *    *          *         *                       **                             ",
    /* 33 */
    "   *              *                                                  *                                 *        *            *                *     *         *         *                          *  * ",
    /* 34 */
    " *         *                             *                                    *  *                         *                                           *       *                           *        *   ",
    /* 35 */
    "   *              *                **   **                                                        *                                                       *                                             ",
    /* 36 */
    "          *  **     * *         *             *                                              *                         *                       * *  *                                                   ",
    /* 37 */
    "                                *  *  *        * *                                *                                                                                                             *       ",
    /* 38 */
    "                  *        **                                *                         *    *          *   *     **                       *            *  **    *                     *   *     *       ",
    /* 39 */
    " *      *                           *                  *     *         *                                  *   *                                                                         *               ",
    /* 40 */
    "            *                                                *      *                      *       *      *                       *  *              *                                               *   ",
    /* 41 */
    "    *                    *               *                  *                             *                  *            *               *   *   *                    *                                ",
    /* 42 */
    "                                               *                                *                     *                     *                                  *                            * *         ",
    /* 43 */
    "                                                                           *               **                                         *          *            *                                **       ",
    /* 44 */
    "            *                  *                     *   *   *  *          *     * *    *            *                           *                                *                       **            ",
    /* 45 */
    "                             *    **                          *     *               *        *                                                                *                 *      *                ",
    /* 46 */
    "*                        *                                                 *                                  *                *            *                                                           ",
    /* 47 */
    "               *    *                                   *       *                   *      *                *                                                              *     *                      ",
    /* 48 */
    "                                                            *                                                 *                                  *                    *        *              *         ",
    /* 49 */
    "           *     *                             *                    *                      *                       *  **           *         *               *                         *            *   ",
    /* 50 */
    "           *                       **                             *      *                 *  *                         *               *                *    *                          *  **          ",
    /* 51 */
    "               *                            *         **      **                             *      *      *                                                  * ***    *                                ",
    /* 52 */
    "                                       **                                                                           *                              *  *                                      *          ",
    /* 53 */
    "                             *              *               *                *  *                *               *                     *                          *     *        *                      ",
    /* 54 */
    "                         **    *    *                                                         *    *                   * * *                                        * *                        *        ",
    /* 55 */
    "                             *               **                                 *                      * *        *  *                                      *        *                                  ",
    /* 56 */
    "                *  *      *  *            *    *               *            *          *          * *                                              *                                *                   ",
    /* 57 */
    "*            *                       *                                                        **    *                                *      *                                                           ",
    /* 58 */
    "           * *                          *       *        *                  *     *  **                                                               **                                                ",
    /* 59 */
    "    *      *                                  *   *                  *                      *    *                                     *      *                       *                *    *  *       *",
};


#endif //TP_LAB_7_SCENES_H
