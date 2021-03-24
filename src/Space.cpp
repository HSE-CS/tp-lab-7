//
// Created by Данил on 04.03.2021.
//

#include <random>
#include <thread>

#include "../include/Space.h"
#include "../include/Objects.h"

Cell::~Cell() {
    this->object = nullptr;
}

char Cell::getFiller() {
    return this->filler;
}

void Cell::setFiller(char c) {
    this->filler = c;
}

Object *Cell::getObject() {
    return this->object;
}

void Cell::setObject(Object *object1) {
    this->object = object1;
}

int Cell::getSymbolColor() const {
    return symbolColor;
}

void Cell::setSymbolColor(int color) {
    this->symbolColor = color;
}

int Cell::getBackgroundColor() const {
    return backgroundColor;
}

void Cell::setBackgroundColor(int color) {
    this->backgroundColor = color;
}

Cell::Cell(int X,
           int Y,
           char filler1,
           int backgroundColor1,
           int symbolColor1) {
    this->posX = X;
    this->posY = Y;
    this->filler = filler1;
    this->backgroundColor = backgroundColor1;
    this->symbolColor = symbolColor1;
    this->object = nullptr;
    this->priority = LOW_PRIORITY;
}

Space::Space() {
    this->prevCondition.resize(displayHeight);
    this->space.resize(displayHeight);
    for (int i = 0; i < displayHeight; ++i) {
        for (int j = 0; j < displayWidth; ++j) {
            this->prevCondition[i].push_back(startSpacePicture[i][j]);
        }
    }
    this->nextCondition.resize(displayHeight);
    for (int i = 0; i < displayHeight; ++i) {
        for (int j = 0; j < displayWidth; ++j) {
            this->nextCondition[i].push_back(startSpacePicture[i][j]);
        }
    }
    for (int i = 0; i < displayHeight; ++i) {
        for (int j = 0; j < displayWidth; ++j) {
            int bcolor = black;
            int scolor = black;
            if (startSpacePicture[i][j] == '*') {
                scolor = white;
            }
            Cell *cell = new Cell(j, i, this->prevCondition[i][j], bcolor, scolor);
            this->space[i].push_back(cell);
        }
    }
}

void Space::setCell(int x, int y, Cell *cell) {
    this->space[y][x] = cell;
}

Cell *Space::getCell(int x, int y) {
    return this->space[y][x];
}

void Space::move(Object *object, int iteration) {
    if (object->getSpeed() == SUPER) {
        relativeMove(object);
        relativeMove(object);
    }
    if (object->getSpeed() == HIGH_SPEED) {
        relativeMove(object);
    }
    if (object->getSpeed() == MEDIUM_SPEED) {
        if (iteration % 2 == 0) {
            relativeMove(object);
        }
    }
    if (object->getSpeed() == LOW_SPEED) {
        if (iteration % 3 == 0) {
            relativeMove(object);
        }
    }
    if (object->getSpeed() == ULTRA_LOW) {
        if (iteration % 10 == 0) {
            relativeMove(object);
        }
    }
}

void Space::relativeMove(Object *object) {
    object->setEnergy(object->getEnergy() - 1);
    Movie::setAreaToNormalCondition(
        object->getPosX(),
        object->getPosY(),
        object->getPosX() + object->getSizeX(),
        object->getPosY() + object->getSizeY()
    );
    switch (object->getDirection()) {
        case UP:
            moveUp(object);
            break;
        case DOWN:
            moveDown(object);
            break;
        case LEFT:
            moveLeft(object);
            break;
        case RIGHT:
            moveRight(object);
            break;
    }
}

void Space::moveUp(Object *object) {
    object->render(object->getPosX(), (object->getPosY() - 1 + displayHeight) % displayHeight);
    object->setPosy((object->getPosY() - 1 + displayHeight) % displayHeight);
    for (int i = object->getPosX(); i < object->getPosX() + object->getSizeX(); ++i) {
        this->space[object->getPosY()][i % displayWidth]->setObject(object);
        this->space[(object->getPosY() + object->getSizeY()) % displayHeight][i % displayWidth]->setObject(nullptr);
    }
}

void Space::moveDown(Object *object) {
    object->render(object->getPosX(), (object->getPosY() + 1) % displayHeight);
    object->setPosy((object->getPosY() + 1) % displayHeight);
    for (int i = object->getPosX(); i < object->getPosX() + object->getSizeX(); ++i) {
        this->space[(object->getPosY() - 1 + displayHeight) % displayHeight][i % displayWidth]->setObject(nullptr);
        this->space[(object->getPosY() + object->getSizeY() - 1) % displayHeight][i % displayWidth]->setObject(object);
    }
}

void Space::moveLeft(Object *object) {
    object->setPosX((object->getPosX() - 1 + displayWidth) % displayWidth);
    object->render(object->getPosX(), object->getPosY());
    for (int i = object->getPosY(); i < object->getPosY() + object->getSizeY(); ++i) {
        this->space[i % displayHeight][(object->getPosX() + object->getSizeX() + 1) % displayWidth]->setObject(nullptr);
        this->space[i % displayHeight][object->getPosX()]->setObject(object);
    }
}

void Space::moveRight(Object *object) {
    object->setPosX((object->getPosX() + 1) % displayWidth);
    object->render(object->getPosX(), object->getPosY());
    for (int i = object->getPosY(); i < object->getPosY() + object->getSizeY(); ++i) {
        this->space[i % displayHeight][(object->getPosX() + object->getSizeX()) % displayWidth]->setObject(object);
        this->space[i % displayHeight][(object->getPosX() - 1 + displayWidth) %
                                       displayWidth]->setObject(nullptr);
    }
}

Object *Space::shoot(Object *ship) {
    Object *whizzbang;
    if (ship->getSide() == REBELS) {
        whizzbang = new Object(WhizzbangRebels(), SUPER);
        playMusicFile("rebelsfire.wav", 1);
    } else if (ship->getSide() == IMPERY) {
        whizzbang = new Object(WhizzbangImpery(), SUPER);
        playMusicFile("imperyfire.wav", 1);
    }
    whizzbang->setDirection(ship->getDirection());
    whizzbang->setPosX((ship->getPosX() + ship->getSizeX() / 2 - 1) % displayWidth);
    whizzbang->setPosy((ship->getPosY() + ship->getSizeY() / 2 - 1) % displayHeight);
    return whizzbang;
}

void Space::destroy(Object *object) {
    this->removeObject(object);
}

void Space::destroyWithExplosion(Object *object) {
    this->removeObject(object);
    explode(object->getPosX() + object->getSizeX() / 2,
            object->getPosY() + object->getSizeY() / 2,
            object->getSizeX());
}

void Space::explode(int x, int y, int radius) {
    int colors[3] = {
        cc(black, yellow),
        cc(black, orange),
        cc(black, red),
    };
    std::random_device gen;
    for (int i = y - radius; i < y + radius; ++i) {
        for (int j = x - radius; j < x + radius; ++j) {
            int newI = (i + displayHeight) % displayHeight;
            int newJ = (j + displayWidth) % displayWidth;
            if (dist(x, y, newJ, newI) < radius) {
                setCursorPosition(newJ, newI);
                setConsoleColour(colors[gen() % 3]);
                std::cout << "# H + @ * "[gen() % 10];
            }
        }
    }
    playMusicFile("explode.wav", 1);
    Movie::wait(0.1);
    Movie::setAreaToNormalCondition(x - radius, y - radius, x + radius, y + radius);
}

Object *Space::scan(Object *ship, int depth) {
    if (ship->getDirection() == UP) {
        for (int i = ship->getPosY() - 1; i > ship->getPosY() - 1 - depth; --i) {
            for (int j = ship->getPosX(); j < ship->getPosX() + ship->getSizeX(); ++j) {
                auto obj = this->space[(i + displayHeight) % displayHeight][j % displayWidth]->getObject();
                if (obj != nullptr) {
                    if (obj->getSide() != ship->getSide() && !obj->destroyed) {
                        return obj;
                    }
                }
            }
        }
    }
    if (ship->getDirection() == DOWN) {
        for (int i = ship->getPosY() + ship->getSizeY(); i < ship->getPosY() + ship->getSizeY() + depth; ++i) {
            for (int j = ship->getPosY(); j < ship->getPosX() + ship->getSizeX(); ++j) {
                auto obj = this->space[(i + displayHeight) % displayHeight][j % displayWidth]->getObject();
                if (obj != nullptr) {
                    if (obj->getSide() != ship->getSide() && !obj->destroyed) {
                        return obj;
                    }
                }
            }
        }
    }
    if (ship->getDirection() == RIGHT) {
        for (int i = ship->getPosY(); i < ship->getPosY() + ship->getSizeY(); ++i) {
            for (int j = ship->getPosX() + ship->getSizeX(); j < ship->getPosX() + ship->getSizeX() + depth; ++j) {
                auto obj = this->space[i % displayHeight][j % displayWidth]->getObject();
                if (obj != nullptr) {
                    if (obj->getSide() != ship->getSide() && !obj->destroyed) {
                        return obj;
                    }
                }
            }
        }
    }
    if (ship->getDirection() == LEFT) {
        for (int i = ship->getPosY(); i < ship->getPosY() + ship->getSizeY(); ++i) {
            for (int j = ship->getPosX() - 1; j > ship->getPosX() - depth; --j) {
                auto obj = this->space[i % displayHeight][(j + displayWidth) % displayWidth]->getObject();
                if (obj != nullptr) {
                    if (obj->getSide() != ship->getSide() && !obj->destroyed) {
                        return obj;
                    }
                }
            }
        }
    }
    return nullptr;
}

void Space::addObject(Object *obj) {
    this->objects.push_back(obj);
}

void Space::removeObject(Object *obj) {
    obj->destroyed = true;
    for (uint_fast32_t i = 0; i < this->objects.size(); ++i) {
        if (objects[i] == obj) {
            objects.erase(objects.begin() + i);
            Movie::setAreaToNormalCondition(obj->getPosX(),
                                            obj->getPosY(),
                                            obj->getPosX() + obj->getSizeX(),
                                            obj->getPosY() + obj->getSizeY());
            for (int k = obj->getPosY(); k < obj->getPosY() + obj->getSizeY(); ++k) {
                for (int j = obj->getPosX(); j < obj->getPosX() + obj->getSizeX(); ++j) {
                    space[k % displayHeight][j % displayWidth]->setObject(nullptr);
                }
            }
            break;
        }
    }
}

std::vector<Object *> *Space::getObjects() {
    return &objects;
}

Object *Space::scan(Object *whizzbang) {
    for (int i = (whizzbang->getPosY() - 1 + displayHeight) % displayHeight;
         i < (whizzbang->getPosY() - 1 + 5 + displayHeight) % displayHeight; ++i) {
        for (int j = (whizzbang->getPosX() - 1 + displayWidth) % displayWidth;
             j < (whizzbang->getPosX() - 1 + 5 + displayWidth) % displayWidth; ++j) {
            auto obj = space[i % displayHeight][j % displayWidth]->getObject();
            if (obj != nullptr) {
                if (obj->getSide() != whizzbang->getSide() && obj->getSpeed() != SUPER) {
                    return obj;
                }
            }
        }
    }
    return nullptr;
}

void Space::hit(Object *whizzbang, Object *target) {
    destroy(whizzbang);
    destroyWithExplosion(target);
}

double Space::dist(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int Space::countSideObject(int side) {
    int counter = 0;
    for (auto x : objects) {
        if (x->getSide() == side) {
            counter++;
        }
    }
    return counter;
}

void Space::generateAsteroidField(int count) {
    std::random_device gen;
    for (int i = 0; i < count; ++i) {
        auto asteroid = new Object(Asteroid(), ZERO_SPEED);
        asteroid->setPosX(gen() % 40 + 80);
        asteroid->setPosy(gen() % 60);
        asteroid->setDirection(NONE);
        objects.push_back(asteroid);
    }
}

void Space::setCellsForObject(Object *obj) {
    for (int i = obj->getPosY(); i < obj->getPosY() + obj->getSizeY(); ++i) {
        for (int j = obj->getPosX(); j < obj->getPosX() + obj->getSizeX(); ++j) {
            this->space[i % displayHeight][j % displayWidth]->setObject(obj);
        }
    }
}

void Space::generateArmy(int rebels, int impery) {
    std::random_device gen;
    int xwings = 0, tiefighters = 0, falcon = 0;
    if (rebels > 3) {
        rebels--;
        falcon = 1;
        xwings = rebels;
    }
    tiefighters = impery;
    for (int i = 0; i < xwings; ++i) {
        auto *xwing = new Object(XWing(), HIGH_SPEED);
        xwing->setPosX(i * 8 + 5 + gen() % 5);
        xwing->setPosy(10 + gen() % 10);
        this->addObject(xwing);
    }
    if (falcon > 0) {
        auto m_falcon = new Object(MilleniumFalcon(), MEDIUM_SPEED);
        m_falcon->setPosX(xwings * 4);
        m_falcon->setPosy(25 + gen() % 10);
        this->addObject(m_falcon);
    }
    for (int i = 0; i < tiefighters; ++i) {
        auto tie_fighter = new Object(TieFighter(), HIGH_SPEED);
        tie_fighter->setPosX(displayWidth - (i + 1) * 6);
        tie_fighter->setPosy(40 + gen() % 10);
        tie_fighter->setDirection(DOWN);
        this->addObject(tie_fighter);
    }
}

Scene::Scene(int sceneNumber) {
    this->prevCondition.resize(displayHeight);
    this->nextCondition.resize(displayHeight);
    this->prevConditionColor.resize(displayHeight);
    this->nextConditionColor.resize(displayHeight);
    for (int i = 0; i < displayHeight; ++i) {
        for (int j = 0; j < displayWidth; ++j) {
            this->prevCondition[i].push_back(display[i][j]);
            this->prevConditionColor[i].push_back(displayColor[i][j]);
            this->nextCondition[i].push_back(display[i][j]);
            this->nextConditionColor[i].push_back(displayColor[i][j]);
        }
    }
    if (sceneNumber == TEST) {
        this->scene_.framesCount = __s_test::framesCount;
        this->scene_.frames.push_back(__s_test::__s_test_1());
        this->scene_.frames.push_back(__s_test::__s_test_2());
        this->scene_.frames.push_back(__s_test::__s_test_3());
        this->scene_.frames.push_back(__s_test::__s_test_4());
    }

    if (sceneNumber == INTRO) {
        this->scene_.framesCount = __s_intro::framesCount;
        for (int i = 0; i < this->scene_.framesCount; ++i) {
            this->scene_.frames.push_back(__s_intro::__s_intro_());
        }
    }
    if (sceneNumber == LIGHTSABER) {
        this->scene_.framesCount = __s_light_saber::framesCount;
        for (int i = 0; i < this->scene_.framesCount; ++i) {
            this->scene_.frames.push_back(__s_light_saber::__s_light_saber_());
        }
    }
    if (sceneNumber == ALONGTIMEAGO) {
        this->scene_.framesCount = __s_far_far_away::framesCount;
        for (int i = 0; i < this->scene_.framesCount; ++i) {
            this->scene_.frames.push_back(__s_far_far_away::__s_far_far_away_());
        }
    }
    if (sceneNumber == STARWARSTITLE) {
        this->scene_.framesCount = __s_star_wars_title::framesCount;
        for (int i = 0; i < this->scene_.framesCount; ++i) {
            this->scene_.frames.push_back(__s_star_wars_title::__s_star_wars_title_());
        }
    }
    if (sceneNumber == STARTCREDITS) {
        this->scene_.framesCount = __s_start_credits::framesCount;
        for (int i = 0; i < this->scene_.framesCount; ++i) {
            this->scene_.frames.push_back(__s_start_credits::__s_start_credits_());
        }
    }
}

void Scene::rawRender() {
    for (int i = 0; i < this->scene_.framesCount; ++i) {
        if (i > 0) {
            for (int j = 0; j < this->scene_.frames[i - 1].sizeY; ++j) {
                for (int k = 0; k < this->scene_.frames[i - 1].sizeX; ++k) {
                    setCursorPosition(this->scene_.frames[i - 1].xPadding + k, this->scene_.frames[i - 1].yPadding + j);
                    setConsoleColour(cc(black, black));
                    std::cout << ' ';
                }
            }
        }
        for (int j = 0; j < this->scene_.frames[i].sizeY; ++j) {
            for (int k = 0; k < this->scene_.frames[i].sizeX; ++k) {
                setCursorPosition(this->scene_.frames[i].xPadding + k, this->scene_.frames[i].yPadding + j);
                setConsoleColour(this->scene_.frames[i].color[j][k]);
                if (this->scene_.frames[i].color[j][k] != -1)
                    std::cout << this->scene_.frames[i].image[j][k];
                Sleep(1);
            }
        }
        Sleep(1000);
    }
}

void Scene::render(int frequency, bool safe) {
    for (int i = 0; i < this->scene_.framesCount; ++i) {
        if (i > 0) {

            // TODO: оптимизировать затирание прошлой сцены (-+ сделал)

            // this->scene_.frames[i - 1].yPadding + j
            // this->scene_.frames[i - 1].xPadding + k
            // this->scene_.frames[i].yPadding + j
            // this->scene_.frames[i].xPadding + k

            for (int j = 0; j < this->scene_.frames[i - 1].sizeY; ++j) {
                for (int k = 0; k < this->scene_.frames[i - 1].sizeX; ++k) {
                    if (this->scene_.frames[i - 1].color[j][k] != -1 && this->scene_.frames[i].color[j][k] == -1) {
                        setCursorPosition(this->scene_.frames[i - 1].xPadding + k,
                                          this->scene_.frames[i - 1].yPadding + j);
                        setConsoleColour(
                            displayColor[this->scene_.frames[i - 1].yPadding + j][this->scene_.frames[i - 1].xPadding +
                                                                                  k]);
                        std::cout
                            << display[this->scene_.frames[i - 1].yPadding + j][this->scene_.frames[i - 1].xPadding +
                                                                                k];
                    }
                }
            }
        }
        for (int j = 0; j < this->scene_.frames[i].sizeY; ++j) {
            for (int k = 0; k < this->scene_.frames[i].sizeX; ++k) {
                nextCondition[this->scene_.frames[i].yPadding + j][this->scene_.frames[i].xPadding +
                                                                   k] = this->scene_.frames[i].image[j][k];
                nextConditionColor[this->scene_.frames[i].yPadding + j][this->scene_.frames[i].xPadding +
                                                                        k] = this->scene_.frames[i].color[j][k];
                if (nextCondition[this->scene_.frames[i].yPadding + j][this->scene_.frames[i].xPadding + k] !=
                    prevCondition[this->scene_.frames[i].yPadding + j][this->scene_.frames[i].xPadding + k] ||
                    nextConditionColor[this->scene_.frames[i].yPadding + j][this->scene_.frames[i].xPadding + k] !=
                    prevConditionColor[this->scene_.frames[i].yPadding + j][this->scene_.frames[i].xPadding + k]) {
                    setCursorPosition(this->scene_.frames[i].xPadding + k, this->scene_.frames[i].yPadding + j);
                    setConsoleColour(this->scene_.frames[i].color[j][k]);
                    if (this->scene_.frames[i].color[j][k] != -1) {
                        std::cout << this->scene_.frames[i].image[j][k];
                    }
                    prevCondition[this->scene_.frames[i].yPadding + j][this->scene_.frames[i].xPadding +
                                                                       k] = nextCondition[
                        this->scene_.frames[i].yPadding + j][this->scene_.frames[i].xPadding + k];
                    prevConditionColor[this->scene_.frames[i].yPadding + j][this->scene_.frames[i].xPadding +
                                                                            k] = nextConditionColor[
                        this->scene_.frames[i].yPadding + j][this->scene_.frames[i].xPadding + k];

                }
            }
        }
        Sleep(frequency);
    }
    if (!safe) {
        for (int j = 0; j < this->scene_.frames[this->scene_.framesCount - 1].sizeY; ++j) {
            for (int k = 0; k < this->scene_.frames[this->scene_.framesCount - 1].sizeX; ++k) {
                setCursorPosition(this->scene_.frames[this->scene_.framesCount - 1].xPadding + k,
                                  this->scene_.frames[this->scene_.framesCount - 1].yPadding + j);
                setConsoleColour(displayColor[this->scene_.frames[this->scene_.framesCount - 1].xPadding + k][
                                     this->scene_.frames[this->scene_.framesCount - 1].yPadding + j]);
                std::cout << display[this->scene_.frames[this->scene_.framesCount - 1].xPadding + k][
                    this->scene_.frames[this->scene_.framesCount - 1].yPadding + j];
            }
        }
    }
    // TODO: Вернуть вектора в стартовое положение
}

void Movie::setStartDisplayCondition() {
    for (auto &i : display) {
        for (int j = 0; j < displayWidth; ++j) {
            i[j] = ' ';
        }
    }
}

void Movie::setStartDisplayColors() {
    std::random_device gen;
    for (int i = 0; i < displayHeight; ++i) {
        for (int j = 0; j < displayWidth; ++j) {
            displayColor[i][j] = cc(black, black);
//            i[j] = 28;// static_cast<signed>(gen() % 256);
        }
    }
}

void Movie::renderStartDisplay() {
    std::random_device gen;
    for (int i = 0; i < displayHeight; ++i) {
        for (int j = 0; j < displayWidth; ++j) {
            setCursorPosition(j, i);
            setConsoleColour(displayColor[i][j]);
//            setConsoleColour(gen() % 256);
            std::cout << display[i][j];
        }
    }
}

void Movie::wait(float seconds) {
    Sleep((int) (seconds * 1000));
}

void Movie::setAreaToNormalCondition(int startX, int startY, int finishX, int finishY) {
    for (int i = startY; i < finishY; ++i) {
        for (int j = startX; j < finishX; ++j) {
            setCursorPosition(j % displayWidth, i % displayHeight);
            setConsoleColour(displayColor[i][j]);
            std::cout << display[i][j];
        }
    }
}

void Movie::setDisplayToSpace() {
    for (int i = 0; i < displayHeight; ++i) {
        for (int j = 0; j < displayWidth; ++j) {
            if (startSpacePicture[i][j] == '*') {
                displayColor[i][j] = cc(black, white);
                display[i][j] = '*';
            } else {
                displayColor[i][j] = cc(black, black);
                display[i][j] = ' ';
            }
        }
    }
}

void Movie::renderSpaceDisplay() {
    for (int i = 0; i < displayHeight; ++i) {
//        for (int j = 0; j < displayWidth; ++j) {
//            setConsoleColour(displayColor[i][j]);
//            setCursorPosition(j, i);
//            std::cout << display[i][j];
//        }
        setCursorPosition(0, i);
        setConsoleColour(cc(black, white));
        std::cout << display[i];
    }
}

void Movie::renderIntroduction() {
    int leftPadding = 65;
    for (int i = 0; i < 45; ++i) {
        int posY = 59 - i;
        for (int j = 0; j < 14; j++) {
            if (posY + j < 60 && posY + j > 29) {
                setCursorPosition(leftPadding, posY + j);
                setConsoleColour(cc(black, yellow));
                std::cout << __s_logo_back::introduction[j];
            }
        }
        Movie::wait(1);
        for (int j = 0; j < 14; ++j) {
            if (posY + j < 60 && posY + j > 29) {
                setCursorPosition(0, posY + j);
                setConsoleColour(cc(black, white));
                std::cout << display[posY + j];
            }
        }
    }
}

void Movie::renderImperyWin() {

}

void Movie::renderRebelsWin() {

}
