#ifndef INIT_TEXTURE_HPP
# define INIT_TEXTURE_HPP

# include "../../include/include.hpp"
#include <iostream>

class Texture {
	public:
		SDL_Texture	*data;

		Texture(std::string *path, SDL_Renderer *renderer);
		~Texture();

};

#endif