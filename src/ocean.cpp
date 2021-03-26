// Copyright 2021 Bogomazov
#include <ctime>
#include <iostream>
#include <vector>

#include "../include/stone.h"
#include "../include/prey.h"
#include "../include/predator.h"
#include "../include/common.h"
#include "../include/cell.h"
#include "../include/ocean.h"
#include <SFML/Graphics.hpp>


Ocean::Ocean(int M, int N,
    int number_objects) {
    this->N = N;
    this->M = M;
    cells = new Cell*[M];
    for (int i = 0; i < M; i++) {
        cells[i] = new Cell[N];
        for (int j = 0; j < N; j++) {
            cells[i][j].init(Pair{i, j}, this);
        }
    }
    addObjects(number_objects);
}

Ocean::~Ocean() {
    for (int i = 0; i < N; i++) {
        delete[] cells[i];
    }
    delete[] cells;
    for (auto i = stuff.begin(); i != stuff.end(); i++) {
        delete* i;
    }
}


void Ocean::addObjects(int number_objects) {
    for (int i = 0; i < number_objects; i++) {
        unsigned int seed = time(nullptr);
        int x = rand_r(&seed) % M;
        int y = rand_r(&seed) % N;
        int type_probability = rand_r(&seed) % 100;
        if (this->cells[x][y].getObject()) {
            continue;
        }
        Object* obj = nullptr;
        if (type_probability > probability_border_up) {
            obj = new Predator(&cells[x][y]);
        } else if ((type_probability <= probability_border_up) &&
            (type_probability >= probability_border_down)) {
            obj = new Stone(&cells[x][y]);
        } else if (type_probability < probability_border_down) {
            obj = new Prey(&cells[x][y]);
        }
        this->cells[x][y].setObject(obj);
        this->stuff.push_back(obj);
    }
}

void Ocean::print(sf::RenderWindow *window) const {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (!cells[i][j].getObject()) {
                sf::RectangleShape blackSq(sf::Vector2f(5, 5));
                blackSq.setFillColor(sf::Color::Black);
                blackSq.setPosition(5 * j, 5 * i);
                window->draw(blackSq);
            } else {
                switch (cells[i][j].getObject()->getType()) {
                    case '#': {
                        sf::RectangleShape redSq(sf::Vector2f(5, 5));
                        redSq.setFillColor(sf::Color::Magenta);
                        redSq.setPosition(5 * j, 5 * i);
                        window->draw(redSq);
                        std::cout << "WTF1\n";
                        break;
                    }
                    case '*': {
                        sf::RectangleShape redSq(sf::Vector2f(5, 5));
                        redSq.setFillColor(sf::Color::Blue);
                        redSq.setPosition(5 * j, 5 * i);
                        window->draw(redSq);
                        std::cout << "WTF2\n";
                        break;
                    }
                    case 'f': {
                        sf::RectangleShape redSq(sf::Vector2f(5, 5));
                        redSq.setFillColor(sf::Color::Green);
                        redSq.setPosition(5 * j, 5 * i);
                        window->draw(redSq);
                        std::cout << "WTF3\n";
                        break;
                    }
                    case 'S': {
                        sf::RectangleShape redSq(sf::Vector2f(5, 5));
                        redSq.setFillColor(sf::Color::Red);
                        redSq.setPosition(5 * j, 5 * i);
                        window->draw(redSq);
                        std::cout << "WTF4\n";
                        break;
                    }
                }
            }
        }
        // std::cout << std::endl;
    }
    // std::cout << std::endl << std::endl << std::endl;
}


Cell* Ocean::seachEmptyPlace(Pair coordinate) {
    std::vector<Cell*> emptyCells;
    for (int i = coordinate.x - 1; i <= coordinate.x + 1; i++) {
        for (int j = coordinate.y - 1; j <= coordinate.y + 1; j++) {
            if (i >= 0 && i < M && j >= 0 && j < N) {
                if (!this->cells[i][j].getObject()) {
                    emptyCells.push_back(&cells[i][j]);
                }
            }
        }
    }
    if (!emptyCells.empty()) {
        return emptyCells[rand() % emptyCells.size()];
    } else {
        return nullptr;
    }
}


void Ocean::run() {
    sf::RenderWindow *window;
    window = new sf::RenderWindow(sf::VideoMode(300, 350), "SFML works!");
    this->print(window);
    window->display();

    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        while (!this->stuff.empty()) {
            for (auto& obj : this->stuff) {
                obj->live();
            }
            this->ClearListOfTheDead();
            window->clear(sf::Color::Black);
            this->print(window);
            window->display();
            sf::Time delayTime = sf::milliseconds(1000);
            sf::sleep(delayTime);
        }
    }
}


void Ocean::addObject(Object* object__) {
    stuff.push_back(object__);
}


void Ocean::AddListOfTheDead(Object* object__) {
    if (object__) {
        ListOfTheDead.push_back(object__);
    }
}


void Ocean::ClearListOfTheDead() {
    for (auto& i : this->ListOfTheDead) {
        this->stuff.remove(i);
        i->setCell(nullptr);
    }
    ListOfTheDead.clear();
}


Cell* Ocean::hunt(Pair coordinate) {
    std::vector<Cell*> preyCells;
    for (int i = coordinate.x - 1; i <= coordinate.x + 1; i++) {
        for (int j = coordinate.y- 1; j <= coordinate.y + 1; j++) {
            if (i >= 0 && i < M && j >= 0 && j < N) {
                if (this->cells[i][j].getObject()) {
                    if (cells[i][j].getObject()->getType() == PREY_N) {
                        preyCells.push_back(&this->cells[i][j]);
                    }
                }
            }
        }
    }
    if (!preyCells.empty()) {
        return preyCells[rand() % preyCells.size()];
    } else {
        return nullptr;
    }
}

