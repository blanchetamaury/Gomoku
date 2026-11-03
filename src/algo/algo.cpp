#include "algo.hpp"

int checkFutureMove(int pos, Player *p, int direction_one, int direction_two) {
	int count = 0;
	int i = direction_one + direction_two;

	while (p->grill[pos + i].occupied_by == "1") {
		i += direction_one + direction_two;
		
		if (pos + i > (NB_CASE - 1) * (NB_CASE - 1) || pos + i < 0)
			break;
		if (pos + i % (NB_CASE - 1) == 0)
			break;
		count++;
	}
	return count;
}

int check_comb(Player *p, int pos) {

    int bestScore = -1;
    
    int count = checkFutureMove(pos, p, 1, 0) + checkFutureMove(pos, p, -1, 0);
    if (count > bestScore)
        bestScore = count;
    count = checkFutureMove(pos, p, 0, (NB_CASE - 1)) + checkFutureMove(pos, p, 0, -(NB_CASE - 1));
    if (count > bestScore)
        bestScore = count;
    count = checkFutureMove(pos, p, 1, (NB_CASE - 1)) + checkFutureMove(pos, p, -1, -(NB_CASE - 1));
    if (count > bestScore)
        bestScore = count;
    count = checkFutureMove(pos, p, 1, -(NB_CASE - 1)) + checkFutureMove(pos, p, -1, (NB_CASE - 1));
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
