#ifndef MAP_HPP
# define MAP_HPP

# include "../../include/include.hpp"
# include "../texture/init_texture.hpp"
# include <iostream>

# define NB_CASE 18

class Map {
	public:
		typedef struct s_map {
			std::string  occupied_by;

			int			 pos_x;
			int			 pos_y;
		} t_map;

		t_map			map[NB_CASE * NB_CASE];
		int				x;
		int				y;
		int				w;
		int				h;

		Map(SDL_Renderer *renderer, SDL_Window *window);
		~Map();

		void drawMap(SDL_Renderer *renderer);
};

#endif