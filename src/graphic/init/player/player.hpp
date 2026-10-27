#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "../../include/include.hpp"
# include "../texture/init_texture.hpp"
# include "../map/map.hpp" 
# include <iostream>

# define POSIBILITY_SIZE 100

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

		int				last_pos;

		Player(SDL_Renderer *renderer, SDL_Window *window);
		~Player();

		void drawGrill(SDL_Renderer *renderer);
		bool checkPosibility(int pos);
};

void HSVtoRGB(float h, float s, float v, Uint8 &r, Uint8 &g, Uint8 &b);

#endif