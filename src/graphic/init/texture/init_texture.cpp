#include "../../include/include.hpp"
#include "init_texture.hpp"

Texture::Texture(std::string *path, SDL_Renderer *renderer) {
	SDL_Surface	*surface;

	surface = IMG_Load(path->c_str());
	if (!surface)
	{
		SDL_Log("Error, Loading image : %s", IMG_GetError());
		throw (std::invalid_argument("Error, Loading image"));
	}
	data = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	if (!data)
	{
		SDL_Log("Error, Create Texture : %s", SDL_GetError());
		throw (std::invalid_argument("Error, Create Texture"));
	}
}

Texture::~Texture() {
	SDL_DestroyTexture(this->data);
}