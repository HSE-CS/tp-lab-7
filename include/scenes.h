//
// Created by Данил on 04.03.2021.
//

#ifndef TP_LAB_7_SCENES_H
#define TP_LAB_7_SCENES_H

#include <iostream>

static const int displayHeight = 60;
static const int displayWidth = 200;

//static const int displayHeight = 30;
//static const int displayWidth = 50;

enum SceneNumber {
    TEST,
    INTRO,
    ALONGTIMEAGO,
    STARWARSTITLE,
    STARTCREDITS,
    ENDCREDITS,
};

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

    static const char light_saber[6][60 + 1]{
        "                                                            ",
        "    cc         cc                                           ",
        "    ccabbaaabbacc                                           ",
        "    ccabbbbbbbacc                                           ",
        "    cc         cc                                           ",
        "                                                            ",
    };

    static const char plasma[6][6 + 1] {
        "cccc  ",
        "bbbcc ",
        "aabbcc",
        "aabbcc",
        "bbbcc ",
        "cccc  ",
    };

    static int sceneNumber = 0;
    static int angleProp = 1;

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
            for (int j = sceneNumber; j > sceneNumber - 3; --j) {
                if (j > -1 && j + i / angleProp < sizeX) {
                    if (cxx_logo[i][j + i / angleProp] == bodySymbol) {
                        scene[i][j + i / angleProp] = filler;
                        color[i][j + i / angleProp] = c1;
                    }
                }
            }
            for (int j = sceneNumber - 3; j > sceneNumber - 6; --j) {
                if (j > -1 && j + i / angleProp < sizeX) {
                    if (cxx_logo[i][j + i / angleProp] == bodySymbol) {
                        scene[i][j + i / angleProp] = filler;
                        color[i][j + i / angleProp] = c2;
                    }
                }
            }
            for (int j = sceneNumber - 6; j > sceneNumber - 9; --j) {
                if (j > -1 && j + i / angleProp < sizeX) {
                    if (cxx_logo[i][j + i / angleProp] == bodySymbol) {
                        scene[i][j + i / angleProp] = filler;
                        color[i][j + i / angleProp] = c3;
                    }
                }
            }
            for (int j = sceneNumber - 9; j > sceneNumber - 12; --j) {
                if (j > -1 && j + i / angleProp < sizeX) {
                    if (cxx_logo[i][j + i / angleProp] == bodySymbol) {
                        scene[i][j + i / angleProp] = filler;
                        color[i][j + i / angleProp] = c4;
                    }
                }
            }
            for (int j = sceneNumber - 12; j > sceneNumber - 15; --j) {
                if (j > -1 && j + i / angleProp < sizeX) {
                    if (cxx_logo[i][j + i / angleProp] == bodySymbol) {
                        scene[i][j + i / angleProp] = filler;
                        color[i][j + i / angleProp] = c5;
                    }
                }
            }
            for (int j = sceneNumber - 15; j > sceneNumber - 18; --j) {
                if (j > -1 && j + i / angleProp < sizeX) {
                    if (cxx_logo[i][j + i / angleProp] == bodySymbol) {
                        scene[i][j + i / angleProp] = filler;
                        color[i][j + i / angleProp] = c6;
                    }
                }
            }
            for (int j = sceneNumber - 18; j > -1; --j) {
                if (cxx_logo[i][j + i / angleProp] == bodySymbol) {
                    scene[i][j + i / angleProp] = filler;
                    color[i][j + i / angleProp] = c7;
                }
            }
        }
        sceneNumber++;
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
    __s_intro_() : Frame(this->sizeX, this->sizeY, this->xPadding, this->yPadding, image, color) {}

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
