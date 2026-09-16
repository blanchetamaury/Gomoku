#include "graphic/include/include.hpp"
#include "graphic/init/init.hpp"
#include "graphic/init/texture/init_texture.hpp"
#include "graphic/init/map/map.hpp"
#include "graphic/init/player/player.hpp"
#include "algo/rules/rules.hpp"

#define TARGET_FPS 60

Rules rules;

void	listenEvent(bool &running, SDL_Event *event, Player *grill, int *round)
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
					if (x > grill->x && x < grill->x + grill->w &&
						y > grill->y && y < grill->y + grill->h) {
						int value_x = x - grill->x;
						int value_y = y - grill->y;
						if (value_x != 0)
							value_x /= SIZE_X_CASE;
						if (value_y != 0)
							value_y /= SIZE_Y_CASE;
						if (grill->checkPosibility(value_x + value_y * (NB_CASE - 1)) == true && grill->grill[value_x + value_y * (NB_CASE - 1)].occupied_by == "0") {
							if (*round % 2 == 0)
								grill->grill[value_x + value_y * (NB_CASE - 1)].occupied_by = "1";
							else 
								grill->grill[value_x + value_y * (NB_CASE - 1)].occupied_by = "2";
                            if (rules.checkWin(value_x + value_y * (NB_CASE - 1), grill) == true) {
                                printf("winner is %d\n", *round % 2 + 1 );
                                running = false;
                            }
                            grill->last_pos = value_x + value_y * (NB_CASE - 1);
							(*round)++;
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
    Map map("./src/graphic/assets/square.png", "./src/graphic/assets/square.png", graph.renderer, graph.window);
    Player grill("./src/graphic/assets/player_one.png", "./src/graphic/assets/player_two.png", graph.renderer, graph.window);
    Init_texture bg("./src/graphic/assets/bg.png", graph.renderer);

    Uint32 frame_time;
    Uint32 frame_duration;
    Uint32 start_time;

    SDL_Event event;
    bool running = true;
    int round = 1;

    int screenW, screenH;
    SDL_GetWindowSize(graph.window, &screenW, &screenH);

    SDL_Rect	rectdst = {0, 0, screenW, screenH};

    frame_time = 1000 / TARGET_FPS;
    while (running)
    {
        listenEvent(running, &event, &grill, &round);
        start_time = SDL_GetTicks();


        SDL_RenderCopy(graph.renderer, bg.data, NULL, &rectdst);

        map.drawMap(graph.renderer);
        grill.drawGrill(graph.renderer);
        SDL_RenderPresent(graph.renderer);

        frame_duration = SDL_GetTicks() - start_time;
        if (frame_duration < frame_time)
            SDL_Delay(frame_time - frame_duration);
    }

    return 0;
}