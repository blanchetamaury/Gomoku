#ifndef INIT_TEXTURE_HPP
# define INIT_TEXTURE_HPP

# include "../../include/include.hpp"
#include <iostream>
#include <map>

#define SIZE_X_CASE 48
#define SIZE_Y_CASE 48

typedef enum s_texture {
	PLAYER_ONE,
	PLAYER_TWO,
	CROSS,
	SQUARE,
	BACKGROUND,
} t_texture;

class Init_texture {
	public:
		SDL_Texture	*data;

		Init_texture(std::string path, SDL_Renderer *renderer);
		Init_texture();
		~Init_texture();

		void loadTexture(std::string path, SDL_Renderer *renderer);
};

class Lib_texture {
	public:
		std::map<int, SDL_Texture *> lib;
	
		Lib_texture();
		~Lib_texture();

		void add_texture(std::string path, SDL_Renderer *renderer, int value);
};

void init_texture_to_lib(SDL_Renderer *renderer);

extern Lib_texture texture;

#endif