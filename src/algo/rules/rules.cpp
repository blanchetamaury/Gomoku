#include "rules.hpp"

Rules::Rules() {}

Rules::~Rules() {}

int checkDirection(int pos, Player *p, int direction_one, int direction_two) {
	int count = 0;
	int i = 0;

	while (p->grill[pos + i].occupied_by == p->grill[pos].occupied_by) {
		i += direction_one + direction_two;
		
		if (pos + i > (NB_CASE - 1) * (NB_CASE - 1) || pos + i < 0)
			break;
		if (pos + i % (NB_CASE - 1) == 0)
			break;
		count++;
	}
	return count;
}

bool Rules::checkWin(int pos, Player *p) {	
	if (checkDirection(pos, p, 1, 0) + checkDirection(pos, p, -1, 0) - 1 >= 5)
		return true;
	if (checkDirection(pos, p, 0, (NB_CASE - 1)) + checkDirection(pos, p, 0, -(NB_CASE - 1)) - 1 >= 5)
		return true;
	if (checkDirection(pos, p, 1, (NB_CASE - 1)) + checkDirection(pos, p, -1, -(NB_CASE - 1)) - 1 >= 5)
		return true;
	if (checkDirection(pos, p, 1, -(NB_CASE - 1)) + checkDirection(pos, p, -1, (NB_CASE - 1)) - 1 >= 5)
		return true;
	return (false);
}


void checkDirectionPair(int pos, Player *p, int direction_one, int direction_two) {	
	int i = 0;

	for (int count = 0; count < 3; count++) {
		i += direction_one + direction_two;
		
		if (pos + i > (NB_CASE - 1) * (NB_CASE - 1) || pos + i < 0)
			return ;
		if (pos + i % (NB_CASE - 1) == 0)
			return ;
		if (count == 2) {
			if (p->grill[pos + i].occupied_by != p->grill[pos].occupied_by)
				return ;
		}
		else if (p->grill[pos + i].occupied_by == "0" || p->grill[pos + i].occupied_by == p->grill[pos].occupied_by) {
			return ;
		}
	}
	p->grill[pos + (direction_one + direction_two)].occupied_by = '0';
	p->grill[pos + (direction_one + direction_two) * 2].occupied_by = '0';
	return ;
}

void Rules::CaptureSPair(int pos, Player *p) {
	checkDirectionPair(pos, p, 1, 0);
	checkDirectionPair(pos, p, 0, (NB_CASE - 1));
	checkDirectionPair(pos, p, 1, (NB_CASE - 1));
	checkDirectionPair(pos, p, 1, -(NB_CASE - 1));
	checkDirectionPair(pos, p, -1, 0);
	checkDirectionPair(pos, p, 0, -(NB_CASE - 1));
	checkDirectionPair(pos, p, -1, -(NB_CASE - 1));
	checkDirectionPair(pos, p, -1, (NB_CASE - 1));
}

