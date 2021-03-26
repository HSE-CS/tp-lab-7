//  Copyright 2021 GHA created by Klykov Anton

#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_

#include "Object.h"
#include "Prey.h"
#include "Predator.h"
#include "Stone.h"
#include <map>
#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <random>
#include "json.hpp"
class Prey;

using json = nlohmann::json;
class Factory {
 private:
  Object* temp_obj;
  std::vector<Object* > temporary_objects;
  std::map<std::string, std::string> parametrsInfo;

 public:
  void readFile() {
    std::ifstream fin("img/parametrs.json");
    int amountParametrs{3};
    std::string temp_cont;
    json j = json::parse(fin);
    for (int i = 0; i < 3; ++i) {
      temp_cont = "Creature";
      temp_cont += std::to_string(i+1);
      j[temp_cont].get_to<std::map<std::string,
                    std::string>>(this->parametrsInfo);
      for (int k = 0; k < std::stoi(parametrsInfo["amount"]);
          ++k) {
        if (parametrsInfo["name"] == "prey") {
          int life = std::stoi(parametrsInfo["life"]);
          int reproduce = std::stoi(parametrsInfo["reproduce"]);
          temp_obj = new Prey("Prey", life,
                              reproduce, nullptr);
          temporary_objects.push_back(temp_obj);
        } else if (parametrsInfo["name"] == "predator") {
          int life = std::stoi(parametrsInfo["life"]);
          int reproduce = std::stoi(parametrsInfo["reproduce"]);
          int eat = std::stoi(parametrsInfo["eat"]);
          temp_obj = new Predator("Predator", "Prey",
                                  eat, life, reproduce, nullptr);
          temporary_objects.push_back(temp_obj);
        } else if (parametrsInfo["name"] == "stone") {
          temp_obj = new Stone("Stone", nullptr);
          temporary_objects.push_back(temp_obj);
        }
      }
    }
    temp_obj = nullptr;
    fin.close();
  }
  std::vector<Object* > getObjects() {
    std::random_device rd;
    std::mt19937 randomPosition(rd());
    for (int i = static_cast<int>(temporary_objects.size() - 1);
        i >= 1 ; i--) {
      int random = static_cast<int>(randomPosition() % (i + 1));
      Object* temp = temporary_objects[random];
      temporary_objects[random] = temporary_objects[i];
      temporary_objects[i] = temp;
    }
    return temporary_objects;
  }
};

#endif 
