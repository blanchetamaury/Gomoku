#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "../../include/include.hpp"
# include "../texture/init_texture.hpp"
# include "../map/map.hpp" 
# include <iostream>

class Player {
	public:
		typedef struct s_map {
			std::string  occupied_by;

			int			 pos_x;
			int			 pos_y;
		} t_map;

		t_map			grill[(NB_CASE - 1) * (NB_CASE - 1)];
		int				x;
		int				y;
		int				w;
		int				h;

		Init_texture Player_one;
		Init_texture Player_two;

		Player(std::string path_texture_one, std::string path_texture_second, SDL_Renderer *renderer, SDL_Window *window);
		~Player();

		void drawGrill(SDL_Renderer *renderer);
};

void HSVtoRGB(float h, float s, float v, Uint8 &r, Uint8 &g, Uint8 &b);

#endif