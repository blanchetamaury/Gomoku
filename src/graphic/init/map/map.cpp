#include "map.hpp"
#include "../../include/include.hpp"
#include "../texture/init_texture.hpp"

Map::Map(std::string path_one, std::string path_two, SDL_Renderer *renderer, SDL_Window *window) {
	int windowWidth, windowHeight;
	SDL_GetWindowSize(window, &windowWidth, &windowHeight);

	int start_x = (windowWidth - NB_CASE * SIZE_X_CASE) / 2;
	int start_y = (windowHeight - NB_CASE * SIZE_Y_CASE) / 2;
	x = start_x;
	y = start_y;
	w = NB_CASE * SIZE_X_CASE;
	h = NB_CASE * SIZE_Y_CASE;
	for (int i = 0; i < NB_CASE * NB_CASE; i++, start_x += SIZE_X_CASE) {
		if (i != 0 && i % NB_CASE == 0) {
			start_x = (windowWidth - NB_CASE * SIZE_X_CASE) / 2;
			start_y += SIZE_Y_CASE;
			if (NB_CASE % 2 == 0)
				std::swap(path_one, path_two);
		}
		if (i % 2 == 0)
			map[i].texture.loadTexture(path_one, renderer);
		else
			map[i].texture.loadTexture(path_two, renderer);
		map[i].occupied_by = '0';
		map[i].pos_x = start_x;
		map[i].pos_y = start_y;
	}
}

Map::~Map() {}


void Map::drawMap(SDL_Renderer *renderer) {
	SDL_Rect	rectdst = {0, 0, SIZE_X_CASE, SIZE_Y_CASE};

	for (int i = 0; i < NB_CASE * NB_CASE; i++) {
		rectdst.x = this->map[i].pos_x;
		rectdst.y = this->map[i].pos_y;

		SDL_RenderCopy(renderer, this->map[i].texture.data, NULL, &rectdst);
	}
}