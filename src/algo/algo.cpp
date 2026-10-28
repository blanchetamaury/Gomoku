#include "algo.hpp"

int check_comb(Player *p, int pos) {

    int bestScore = -1;
    
    int count = checkDirection(pos, p, 1, 0) + checkDirection(pos, p, -1, 0) - 1;
    if (count > bestScore)
        bestScore = count;
    count = checkDirection(pos, p, 0, (NB_CASE - 1)) + checkDirection(pos, p, 0, -(NB_CASE - 1)) - 1;
    if (count > bestScore)
        bestScore = count;
    count = checkDirection(pos, p, 1, (NB_CASE - 1)) + checkDirection(pos, p, -1, -(NB_CASE - 1)) - 1;
    if (count > bestScore)
        bestScore = count;
    count = checkDirection(pos, p, 1, -(NB_CASE - 1)) + checkDirection(pos, p, -1, (NB_CASE - 1)) - 1;
    if (count > bestScore)
        bestScore = count;

    return values[bestScore];
}

int heuristique(Player *p) {
    
    int best_pos = -1;

    for (int i = 0; i < (NB_CASE - 1) * (NB_CASE - 1); i++) {
        if (p->grill[i].occupied_by == "0") {
            int val = check_comb(p, i);
            if (val > check_comb(p, best_pos))
                best_pos = i;
        }
    }
    return best_pos;
}
