#include "graphic/include/include.hpp"
#include "graphic/init/init.hpp"
#include "graphic/init/texture/init_texture.hpp"
#include "graphic/init/map/map.hpp"
#include "graphic/init/player/player.hpp"
#include "algo/rules/rules.hpp"
#include "algo/algo.hpp"

#define TARGET_FPS 60

Rules rules;
Lib_texture texture;

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
                            if (*round % 2 != 0)
								grill->grill[value_x + value_y * (NB_CASE - 1)].occupied_by = "-1";
							// else
							// 	grill->grill[value_x + value_y * (NB_CASE - 1)].occupied_by = "1";
                            rules.CaptureSPair(value_x + value_y * (NB_CASE - 1), grill);
                            if (rules.checkWin(value_x + value_y * (NB_CASE - 1), grill) == true) {
                                printf("Winner is %d\n", *round % 2 + 1 );
                                running = false;
                            } else if ( *round + 1 == (NB_CASE - 1) * (NB_CASE - 1)) {
                                printf("Null game\n");
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

    init_texture_to_lib(graph.renderer);

    Map map(graph.renderer, graph.window);
    Player grill(graph.renderer, graph.window);

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
        if (round % 2 != 0)
            listenEvent(running, &event, &grill, &round);
        else {
            int move_ia = heuristique(&grill);
            std::cout << move_ia << std::endl;
            std::cout << grill.grill[move_ia].pos_x << " " << grill.grill[move_ia].pos_y << std::endl;
            grill.grill[move_ia].occupied_by = "1";
            round++;
        }
        start_time = SDL_GetTicks();

        SDL_RenderCopy(graph.renderer, texture.lib[BACKGROUND], NULL, &rectdst);

        map.drawMap(graph.renderer);
        grill.drawGrill(graph.renderer);
        SDL_RenderPresent(graph.renderer);

        frame_duration = SDL_GetTicks() - start_time;
        if (frame_duration < frame_time)
            SDL_Delay(frame_time - frame_duration);
    }

    return 0;
}