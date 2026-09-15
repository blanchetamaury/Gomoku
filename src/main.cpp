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
						if (grill->grill[value_x + value_y * (NB_CASE - 1)].occupied_by == "0") {
							if (*round % 2 == 0)
								grill->grill[value_x + value_y * (NB_CASE - 1)].occupied_by = "1";
							else 
								grill->grill[value_x + value_y * (NB_CASE - 1)].occupied_by = "2";
                            if (rules.checkWin(value_x + value_y * (NB_CASE - 1), grill) == true) {
                                printf("winner is %d\n", *round % 2 + 1 );
                                running = false;
                            }
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

SDL_Texture* createGradientTexture(SDL_Renderer *renderer, int w, int h) {
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
                                              SDL_TEXTUREACCESS_STREAMING, w, h);
    return texture;
}

void updateRainbowTexture(SDL_Texture *texture, int w, int h, Uint32 time) {
    void *pixels;
    int pitch;
    SDL_LockTexture(texture, NULL, &pixels, &pitch);
    Uint32 *pix = (Uint32*)pixels;

    for (int y = 0; y < h; y++) {
        float hue = fmod((time / 20.0) + (y * 0.5), 360.0);
        Uint8 r, g, b;
        HSVtoRGB(hue, 1.0f, 1.0f, r, g, b);
        Uint32 color = (r << 24) | (g << 16) | (b << 8) | 255;

        for (int x = 0; x < w; x++) {
            pix[y * (pitch / 4) + x] = color;
        }
    }

    SDL_UnlockTexture(texture);
}

int main() {
    Init graph;
    Map map("./src/graphic/assets/black.png", "./src/graphic/assets/white.png", graph.renderer, graph.window);
    Player grill("./src/graphic/assets/player_one.png", "./src/graphic/assets/player_two.png", graph.renderer, graph.window);

    Uint32 frame_time;
    Uint32 frame_duration;
    Uint32 start_time;

    SDL_Event event;
    bool running = true;
    int round = 0;

    int screenW, screenH;
    SDL_GetWindowSize(graph.window, &screenW, &screenH);
    SDL_Texture *bgTexture = createGradientTexture(graph.renderer, screenW, screenH);

    frame_time = 1000 / TARGET_FPS;
    while (running)
    {
        listenEvent(running, &event, &grill, &round);
        start_time = SDL_GetTicks();

        updateRainbowTexture(bgTexture, screenW, screenH, start_time);
        SDL_RenderCopy(graph.renderer, bgTexture, NULL, NULL);

        map.drawMap(graph.renderer);
        grill.drawGrill(graph.renderer);
        SDL_RenderPresent(graph.renderer);

        frame_duration = SDL_GetTicks() - start_time;
        if (frame_duration < frame_time)
            SDL_Delay(frame_time - frame_duration);
    }

    SDL_DestroyTexture(bgTexture);
    return 0;
}