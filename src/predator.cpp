#include "predator.h"
#include "cell.h"
#include "ocean.h"
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

#define default_progenty 10;

Predator::Predator(Cell *_cell) {
    cell = _cell;
    type = ObjType::PREDATOR;
    life = 3;
    progeny_time = default_progenty;
}

void Predator::live() {
    std::vector<int> step = {1, 2, 3, 4, 5, 6, 7, 8};
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(step.begin(), step.end(), std::default_random_engine(seed));
    auto ocean = this->cell->getOcean();
    --life;
    --progeny_time;
    for (auto opt: step) {
        int i = this->cell->getX();
        int j = this->cell->getY();
        if (life < 0) {
            ocean->cells[i][j].killMe();
            break;
        }
        if (opt == 1) {
            if (i - 1 < 0 || j + 1 >= M) {
                continue;
            }
            if (ocean->getNear(i - 1, j + 1) == ObjType::CORAL ||
                ocean->getNear(i - 1, j + 1) == ObjType::PREY) {
                if (ocean->getNear(i - 1, j + 1) == ObjType::PREY) {
                    life += 5;
                }
                this->setCell(&ocean->cells[i - 1][j + 1]);
                ocean->cells[i][j].killMe();
                ocean->cells[i - 1][j + 1].setObject(this);
                if (progeny_time < 0) {
                    progeny_time = default_progenty;
                    auto* new_predator = new Predator(&ocean->cells[i][j]);
                    ocean->cells[i][j].setObject(new_predator);
                }
                break;
            }
        }
        if (opt == 2) {
            if (j + 1 >= M) {
                continue;
            }
            if (ocean->getNear(i, j + 1) == ObjType::CORAL ||
                ocean->getNear(i, j + 1) == ObjType::PREY) {
                if (ocean->getNear(i, j + 1) == ObjType::PREY) {
                    life += 5;
                }
                this->setCell(&ocean->cells[i][j + 1]);
                ocean->cells[i][j].killMe();
                ocean->cells[i][j + 1].setObject(this);
                if (progeny_time < 0) {
                    progeny_time = default_progenty;
                    auto* new_predator = new Predator(&ocean->cells[i][j]);
                    ocean->cells[i][j].setObject(new_predator);
                }
                break;
            }
        }
        if (opt == 3) {
            if (i + 1 >= N || j + 1 >= M) {
                continue;
            }
            if (ocean->getNear(i + 1, j + 1) == ObjType::CORAL ||
                ocean->getNear(i + 1, j + 1) == ObjType::PREY) {
                if (ocean->getNear(i + 1, j + 1) == ObjType::PREY) {
                    life += 5;
                }
                this->setCell(&ocean->cells[i + 1][j + 1]);
                ocean->cells[i][j].killMe();
                ocean->cells[i + 1][j + 1].setObject(this);
                if (progeny_time < 0) {
                    progeny_time = default_progenty;
                    auto* new_predator = new Predator(&ocean->cells[i][j]);
                    ocean->cells[i][j].setObject(new_predator);
                }
                break;
            }
        }
        if (opt == 4) {
            if (i + 1 >= N) {
                continue;
            }
            if (ocean->getNear(i + 1, j) == ObjType::CORAL ||
                ocean->getNear(i + 1, j) == ObjType::PREY) {
                if (ocean->getNear(i + 1, j) == ObjType::PREY) {
                    life += 5;
                }
                this->setCell(&ocean->cells[i + 1][j]);
                ocean->cells[i][j].killMe();
                ocean->cells[i + 1][j].setObject(this);
                if (progeny_time < 0) {
                    progeny_time = default_progenty;
                    auto* new_predator = new Predator(&ocean->cells[i][j]);
                    ocean->cells[i][j].setObject(new_predator);
                }
                break;
            }
        }
        if (opt == 5) {
            if (i + 1 >= N || j - 1 < 0) {
                continue;
            }
            if (ocean->getNear(i + 1, j - 1) == ObjType::CORAL ||
                ocean->getNear(i + 1, j - 1) == ObjType::PREY) {
                if (ocean->getNear(i + 1, j - 1) == ObjType::PREY) {
                    life += 5;
                }
                this->setCell(&ocean->cells[i + 1][j - 1]);
                ocean->cells[i][j].killMe();
                ocean->cells[i + 1][j - 1].setObject(this);
                if (progeny_time < 0) {
                    progeny_time = default_progenty;
                    auto* new_predator = new Predator(&ocean->cells[i][j]);
                    ocean->cells[i][j].setObject(new_predator);
                }
                break;
            }
        }
        if (opt == 6) {
            if (j - 1 < 0) {
                continue;
            }
            if (ocean->getNear(i, j - 1) == ObjType::CORAL ||
                ocean->getNear(i, j - 1) == ObjType::PREY) {
                if (ocean->getNear(i, j - 1) == ObjType::PREY) {
                    life += 5;
                }
                this->setCell(&ocean->cells[i][j - 1]);
                ocean->cells[i][j].killMe();
                ocean->cells[i][j - 1].setObject(this);
                if (progeny_time < 0) {
                    progeny_time = default_progenty;
                    auto* new_predator = new Predator(&ocean->cells[i][j]);
                    ocean->cells[i][j].setObject(new_predator);
                }
                break;
            }
        }
        if (opt == 7) {
            if (i - 1 < 0 || j - 1 < 0) {
                continue;
            }
            if (ocean->getNear(i - 1, j - 1) == ObjType::CORAL ||
                ocean->getNear(i - 1, j - 1) == ObjType::PREY) {
                if (ocean->getNear(i - 1, j - 1) == ObjType::PREY) {
                    life += 5;
                }
                this->setCell(&ocean->cells[i - 1][j - 1]);
                ocean->cells[i][j].killMe();
                ocean->cells[i - 1][j - 1].setObject(this);
                if (progeny_time < 0) {
                    progeny_time = default_progenty;
                    auto* new_predator = new Predator(&ocean->cells[i][j]);
                    ocean->cells[i][j].setObject(new_predator);
                }
                break;
            }
        }
        if (opt == 8) {
            if (i - 1 < 0) {
                continue;
            }
            if (ocean->getNear(i - 1, j) == ObjType::CORAL ||
                ocean->getNear(i - 1, j) == ObjType::PREY) {
                if (ocean->getNear(i - 1, j) == ObjType::PREY) {
                    life += 5;
                }
                this->setCell(&ocean->cells[i - 1][j]);
                ocean->cells[i][j].killMe();
                ocean->cells[i - 1][j].setObject(this);
                if (progeny_time < 0) {
                    progeny_time = default_progenty;
                    auto* new_predator = new Predator(&ocean->cells[i][j]);
                    ocean->cells[i][j].setObject(new_predator);
                }
                break;
            }
        }
    }
}