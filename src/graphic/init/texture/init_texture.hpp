#ifndef INIT_TEXTURE_HPP
# define INIT_TEXTURE_HPP

# include "../../include/include.hpp"
#include <iostream>

class Init_texture {
	public:
		SDL_Texture	*data;

		Init_texture(std::string path, SDL_Renderer *renderer);
		~Init_texture();

};

#endif