#ifndef INIT_TEXTURE_HPP
# define INIT_TEXTURE_HPP

# include "../../include/include.hpp"
#include <iostream>

#define SIZE_X_CASE 48
#define SIZE_Y_CASE 48

class Init_texture {
	public:
		SDL_Texture	*data;

		Init_texture(std::string path, SDL_Renderer *renderer);
		Init_texture();
		~Init_texture();

		void loadTexture(std::string path, SDL_Renderer *renderer);
};

#endif