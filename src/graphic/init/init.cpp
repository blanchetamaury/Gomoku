#include "init.hpp"

Init::Init() {
	if (SDL_Init(SDL_INIT_VIDEO | IMG_INIT_PNG | SDL_INIT_AUDIO) != 0)
		throw (std::invalid_argument("SDL_init Error"));
	this->window = SDL_CreateWindow("Gomoku", 0, 0, 0, 0,
			SDL_WINDOW_FULLSCREEN_DESKTOP);
	if (this->window == NULL)
		throw (std::invalid_argument("Window Error"));
	this->renderer = SDL_CreateRenderer(this->window, -1,
			SDL_RENDERER_ACCELERATED);
	if (this->renderer == NULL)
		throw (std::invalid_argument("Renderer Error"));
}

Init::~Init()
{
	SDL_DestroyRenderer(this->renderer);
	SDL_DestroyWindow(this->window);
	SDL_Quit();
}