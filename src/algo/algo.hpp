#ifndef ALGO_HPP
#define ALGO_HPP

#include <iostream>
#include "../graphic/init/player/player.hpp"

const int values[] = {
    0,
    10,
    100,
    1000,
    10000,
    100000
};

class algo {
    public:

        algo();
        ~algo();

        int heuristique(Player *p);
};

#endif