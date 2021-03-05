//
// Created by Данил on 04.03.2021.
//

#ifndef TP_LAB_7_SCENES_H
#define TP_LAB_7_SCENES_H

#include <iostream>

//static const int displayHeight = 60;
//static const int displayWidth = 200;

static const int displayHeight = 30;
static const int displayWidth = 50;

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


typedef struct Frame {
    int sizeX;
    int sizeY;
    int xPadding;
    int yPadding;
    char **image;
    int **color;

    template<std::size_t U, std::size_t V>
    Frame(int x, int y, int xp, int yp, const char(&img)[U][V], const int (&col)[U][V]) {
        this->sizeX = x;
        this->sizeY = y;
        this->xPadding = xp;
        this->yPadding = yp;
        this->image = new char *[y];
        for (int i = 0; i < x; ++i) {
            this->image[i] = new char[x + 1];
            for (int j = 0; j < y; ++j) {
                this->image[i][j] = img[i][j];
            }
        }
        this->color = new int *[y];
        for (int i = 0; i < x; ++i) {
            this->color[i] = new int[x + 1];
            for (int j = 0; j < y; ++j) {
                this->color[i][j] = col[i][j];
            }
        }
    }
} Frame;

namespace __s_test {
    static int framesCount = 4;

    const char image1[3][4] = {
        "***",
        "*  ",
        "*  ",
    };

    const int color1[3][4] = {
        {_c_bl_ye, _c_bl_ye, cc(dark_green, cyan),},
        {_c_bl_ye, -1, -1},
        {cc(green, cyan), -1, -1},
    };

    const char image2[3][4] = {
        " **",
        "** ",
        "*  ",
    };

    const int color2[3][4] = {
        {-1, _c_bl_ye, cc(dark_purple, cyan),},
        {_c_bl_ye, _c_bl_ye, -1,},
        {cc(pink, cyan), -1, -1,},
    };

    const char image3[3][4] = {
        "  *",
        " **",
        "** ",
    };

    const int color3[3][4] = {
        {-1, -1, cc(dark_blue, cyan),},
        {-1, _c_bl_ye, _c_bl_ye,},
        {cc(blue, cyan), _c_bl_ye, -1,},
    };

    const char image4[3][4] = {
        "  *",
        "  *",
        "***",
    };

    const int color4[3][4] = {
        {-1, -1, cc(red, cyan),},
        {-1, -1, _c_bl_ye,},
        {cc(dark_red, cyan), _c_bl_ye, _c_bl_ye,},
    };


    typedef struct __s_test_1 : public Frame {
        __s_test_1() : Frame(this->sizeX, this->sizeY, this->xPadding, this->yPadding, image1, color1) {}

        static const int sizeX = 3;
        static const int sizeY = 3;
        static const int xPadding = 1;
        static const int yPadding = 1;
    } __s_test_1;

    typedef struct __s_test_2 : public Frame {
        __s_test_2() : Frame(this->sizeX, this->sizeY, this->xPadding, this->yPadding, image2, color2) {}

        static const int sizeX = 3;
        static const int sizeY = 3;
        static const int xPadding = 2;
        static const int yPadding = 2;
    } __s_test_2;

    typedef struct __s_test_3 : public Frame {
        __s_test_3() : Frame(this->sizeX, this->sizeY, this->xPadding, this->yPadding, image3, color3) {}

        static const int sizeX = 3;
        static const int sizeY = 3;
        static const int xPadding = 3;
        static const int yPadding = 3;
    } __s_test_3;

    typedef struct __s_test_4 : public Frame {
        __s_test_4() : Frame(this->sizeX, this->sizeY, this->xPadding, this->yPadding, image4, color4) {}

        static const int sizeX = 3;
        static const int sizeY = 3;
        static const int xPadding = 4;
        static const int yPadding = 4;
    } __s_test_4;
}

static char display[displayHeight][displayWidth + 1]{};

static int displayColor[displayHeight][displayWidth + 1]{};

static const char startSpacePicture[displayHeight+150][displayWidth + 1+150] = {
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
