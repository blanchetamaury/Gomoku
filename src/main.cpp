#include "graphic/include/include.hpp"
#include "graphic/init/init.hpp"
#include "graphic/init/texture/init_texture.hpp"
#include "graphic/init/map/map.hpp"

#define TARGET_FPS 60

void	listenEvent(bool &running, SDL_Event *event, Map *map, int *round)
{
	while (SDL_PollEvent(event)) {
        switch (event->type) {
            case SDL_QUIT: {
                running = 0;
                break;
			}
                
            case SDL_MOUSEBUTTONDOWN: {
                int x = event->button.x;
                int y = event->button.y;
                
                if (event->button.button == SDL_BUTTON_LEFT || event->button.button == SDL_BUTTON_RIGHT) {
					if (x > map->x && x < map->x + map->w &&
						y > map->y && y < map->y + map->h) {
						int value_x = x - map->x;
						int value_y = y - map->y;
						if (value_x != 0)
							value_x /= SIZE_X_CASE;
						if (value_y != 0)
							value_y /= SIZE_Y_CASE;
						if (map->map[value_x + value_y * NB_CASE].occupied_by == "0") {
							if (*round % 2 == 0)
								map->map[value_x + value_y * NB_CASE].occupied_by = "1";
							else 
								map->map[value_x + value_y * NB_CASE].occupied_by = "2";
							(*round)++;
							printf("number of turns : %d\n", *round);
						}
					}
				}
                break;
			}
                
            case SDL_MOUSEBUTTONUP: {
                break;
			}

			case SDL_KEYDOWN: {
				if (event->key.keysym.sym == SDLK_ESCAPE)
					running = 0;
				break;
			}
        }
		if (event->type == SDL_QUIT)
			running = 0;
    }
}

int main() {
	Init graph;
	Map	 map("./src/graphic/assets/black.png", "./src/graphic/assets/white.png", graph.renderer, graph.window);
	
	Uint32	frame_time;
	Uint32	frame_duration;
	Uint32	start_time;
	
	SDL_Event		event;
	bool			running = true;
	int				round = 0;

	map.texturePlayer("./src/graphic/assets/player_one.png", "./src/graphic/assets/player_two.png", graph.renderer);
	frame_time = 1000 / TARGET_FPS;
	while (running)
	{
		listenEvent(running, &event, &map, &round);
		start_time = SDL_GetTicks();
		SDL_SetRenderDrawColor(graph.renderer, 50, 0, 50, 255);
		SDL_RenderClear(graph.renderer);
		map.drawMap(graph.renderer);
		SDL_RenderPresent(graph.renderer);
		frame_duration = SDL_GetTicks() - start_time;
		if (frame_duration < frame_time)
			SDL_Delay(frame_time - frame_duration);
	}
}