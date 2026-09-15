#ifndef RULES_HPP
# define RULES_HPP

# include <iostream>
# include "../../graphic/init/player/player.hpp"

class Rules {
	public:
		Rules();
		~Rules();

		bool checkWin(int pos, Player *p);
};

#endif