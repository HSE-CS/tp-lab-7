// Copyright dmitrycvetkov 2021
#ifndef _COMMON_H_
#define _COMMON_H_

#include <cstdint>
#include <memory>
#include <random>
#include <iterator>


template<typename Iter, typename RandomGenerator>
Iter select_randomly(Iter start, Iter end, RandomGenerator& g) {  // NOLINT
    std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
    std::advance(start, dis(g));
    return start;
}

template<typename Iter>
Iter select_randomly(Iter start, Iter end) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return select_randomly(start, end, gen);
}

class Object;

typedef size_t coord_t;

struct Pair {
    coord_t x;  // 0..M-1
    coord_t y;  // 0..N-1
};

const size_t N = 20;
const size_t M = 50;

constexpr char STONE_N = '#';
constexpr char PREY_N = 'f';
constexpr char PREDATOR_N = 'S';

constexpr size_t MAX_PREY_AGE = 3;
constexpr size_t MAX_PREDATOR_HEALTH = 2;
constexpr unsigned REPRODUCTION_TIMER = 2;

enum class ObjType {
    STONE,
    PREY,
    PREDATOR
};

char toChar(const std::shared_ptr<Object> obj);

#endif
