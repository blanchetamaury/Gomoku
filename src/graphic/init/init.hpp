#ifndef INIT_HPP
# define INIT_HPP

# include "../include/include.hpp"
#include <iostream>

class Init  {
	public:
		SDL_Renderer	*renderer;
		SDL_Window		*window;

		Init();
		~Init();
};

#endif