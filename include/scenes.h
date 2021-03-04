//
// Created by Данил on 04.03.2021.
//

#ifndef TP_LAB_7_SCENES_H
#define TP_LAB_7_SCENES_H

#include <iostream>

typedef struct Frame {
    int sizeX;

    template<std::size_t U, std::size_t V>
    Frame(int x, int y, int xp, int yp, const char(&img)[U][V]) {
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
    }

    int sizeY;
    int xPadding;
    int yPadding;
    char **image;
} Frame;

namespace __s_test {
    static int framesCount = 4;

    const char startImage[3][4] = {
        "** ",
        "*  ",
        "   ",
    };

    const char image1[3][4] = {
        "***",
        "*  ",
        "*  ",
    };

    const char image2[3][4] = {
        " **",
        "** ",
        "*  ",
    };

    const char image3[3][4] = {
        "  *",
        " **",
        "** ",
    };

    const char image4[3][4] = {
        "  *",
        "  *",
        "***",
    };

    typedef struct __s_test_1 : public Frame {
        __s_test_1() : Frame(this->sizeX, this->sizeY, this->xPadding, this->yPadding, image1) {}

        static const int sizeX = 3;
        static const int sizeY = 3;
        static const int xPadding = 0;
        static const int yPadding = 0;
    } __s_test_1;

    typedef struct __s_test_2 : public Frame {
        __s_test_2() : Frame(this->sizeX, this->sizeY, this->xPadding, this->yPadding, image2) {}

        static const int sizeX = 3;
        static const int sizeY = 3;
        static const int xPadding = 0;
        static const int yPadding = 0;
    } __s_test_2;

    typedef struct __s_test_3 : public Frame {
        __s_test_3() : Frame(this->sizeX, this->sizeY, this->xPadding, this->yPadding, image3) {}

        static const int sizeX = 3;
        static const int sizeY = 3;
        static const int xPadding = 0;
        static const int yPadding = 0;
    } __s_test_3;

    typedef struct __s_test_4 : public Frame {
        __s_test_4() : Frame(this->sizeX, this->sizeY, this->xPadding, this->yPadding, image4) {}

        static const int sizeX = 3;
        static const int sizeY = 3;
        static const int xPadding = 0;
        static const int yPadding = 0;
    } __s_test_4;
}


#endif //TP_LAB_7_SCENES_H
