#include "player.hpp"
#include "../../include/include.hpp"
#include "../texture/init_texture.hpp"

Player::Player(std::string path_one, std::string path_two, SDL_Renderer *renderer, SDL_Window *window) {
	this->Player_one.loadTexture(path_one, renderer);
	this->Player_two.loadTexture(path_two, renderer);

	int windowWidth, windowHeight;
	SDL_GetWindowSize(window, &windowWidth, &windowHeight);

	int nb_case = (NB_CASE - 1);
	int start_x = (windowWidth - nb_case * SIZE_X_CASE) / 2;
	int start_y = (windowHeight - nb_case * SIZE_Y_CASE) / 2;
	x = start_x;
	y = start_y;
	w = nb_case * SIZE_X_CASE;
	h = nb_case * SIZE_Y_CASE;
	for (int i = 0; i < nb_case * nb_case; i++, start_x += SIZE_X_CASE) {
		if (i != 0 && i % nb_case == 0) {
			start_x = (windowWidth - nb_case * SIZE_X_CASE) / 2;
			start_y += SIZE_Y_CASE;
		}
		grill[i].occupied_by = '0';
		grill[i].pos_x = start_x;
		grill[i].pos_y = start_y;
	}
}

Player::~Player() {}

void HSVtoRGB(float h, float s, float v, Uint8 &r, Uint8 &g, Uint8 &b) {
    float c = v * s;
    float x = c * (1 - fabs(fmod(h / 60.0, 2) - 1));
    float m = v - c;
    float r1, g1, b1;

    if (h < 60)      { r1 = c; g1 = x; b1 = 0; }
    else if (h < 120) { r1 = x; g1 = c; b1 = 0; }
    else if (h < 180) { r1 = 0; g1 = c; b1 = x; }
    else if (h < 240) { r1 = 0; g1 = x; b1 = c; }
    else if (h < 300) { r1 = x; g1 = 0; b1 = c; }
    else              { r1 = c; g1 = 0; b1 = x; }

    r = (Uint8)((r1 + m) * 255);
    g = (Uint8)((g1 + m) * 255);
    b = (Uint8)((b1 + m) * 255);
}

void Player::drawGrill(SDL_Renderer *renderer) {
    SDL_Rect	rectdst = {0, 0, SIZE_X_CASE, SIZE_Y_CASE};
    Uint32 time = SDL_GetTicks();

    for (int i = 0; i < (NB_CASE - 1) * (NB_CASE - 1); i++) {
        rectdst.x = this->grill[i].pos_x;
        rectdst.y = this->grill[i].pos_y;

        if (grill[i].occupied_by == "0") {
            float hue = fmod((time / 10.0) + (i * 15), 360.0);
            
            Uint8 r, g, b;
            HSVtoRGB(hue, 1.0f, 1.0f, r, g, b);

            SDL_SetRenderDrawColor(renderer, r, g, b, 255);
            SDL_RenderDrawRect(renderer, &rectdst);
        }
        if (grill[i].occupied_by == "1")
            SDL_RenderCopy(renderer, this->Player_one.data, NULL, &rectdst);
        if (grill[i].occupied_by == "2")
            SDL_RenderCopy(renderer, this->Player_two.data, NULL, &rectdst);
    }
}