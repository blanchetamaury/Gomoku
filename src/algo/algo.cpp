#include "algo.hpp"

algo::algo() {}
algo::~algo() {}

int get_score(Player *p, int pos, int hori, int verti) {

    int count = 0;
    for (int i = 0; i < 5; i++) {
        if ()
    }
}

int check_comb(Player *p, int pos) {

    int best_val = values[0];

    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            int new_val = get_score(p, pos, i, j);
            if (new_val > best_val)
                best_val = new_val;
        }
    }
    return best_val;
}

int algo::heuristique(Player *p) {
    
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
