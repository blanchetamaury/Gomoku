#ifndef ALGO_HPP
#define ALGO_HPP

#include <iostream>
#include "../graphic/init/player/player.hpp"
#include "rules/rules.hpp"

const int values[] = {
    0,
    10,
    100,
    1000,
    10000,
    100000
};

int heuristique(Player *p);
    
#endif