#include "rules.hpp"

Rules::Rules() {}

Rules::~Rules() {}

int checkDirection(int pos, std::string c, Player *p, int direction_one, int direction_two) {
	int count = 0;
	
	int i = 0;
	while (p->grill[pos + i].occupied_by == c) {
		i += direction_one + direction_two;
		
		if (pos + i > (NB_CASE - 1) * (NB_CASE - 1))
			break;
		if (pos + i % (NB_CASE - 1) == 0)
			break;
		count++;
	}
	return count;
}

bool Rules::checkWin(int pos, Player *p) {	
	std::string player = p->grill[pos].occupied_by;

	if (checkDirection(pos, player, p, 1, 0) + checkDirection(pos, player, p, -1, 0) - 1 >= 5)
		return true;
	if (checkDirection(pos, player, p, 0, (NB_CASE - 1)) + checkDirection(pos, player, p, 0, -(NB_CASE - 1)) - 1 >= 5)
		return true;
	if (checkDirection(pos, player, p, 1, (NB_CASE - 1)) + checkDirection(pos, player, p, -1, -(NB_CASE - 1)) - 1 >= 5)
		return true;
	if (checkDirection(pos, player, p, 1, -(NB_CASE - 1)) + checkDirection(pos, player, p, -1, (NB_CASE - 1)) - 1 >= 5)
		return true;
	return (false);
}


