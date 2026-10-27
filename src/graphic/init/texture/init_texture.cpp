#include "../../include/include.hpp"
#include "init_texture.hpp"

void Init_texture::loadTexture(std::string path, SDL_Renderer *renderer) {
	SDL_Surface	*surface;

	surface = IMG_Load(path.c_str());
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

Init_texture::Init_texture(std::string path, SDL_Renderer *renderer) {
	this->loadTexture(path, renderer);
}

Init_texture::Init_texture() {
	this->data = NULL;
}

Init_texture::~Init_texture() {
	if (this->data)
		SDL_DestroyTexture(this->data);
	this->data = NULL;
}

Lib_texture::Lib_texture() {}
Lib_texture::~Lib_texture() {}

void Lib_texture::add_texture(std:: string path, SDL_Renderer *renderer, int value) {
	Init_texture texture(path, renderer);

	lib[value] = texture.data;
	texture.data = NULL;
}

void init_texture_to_lib(SDL_Renderer *renderer) {
	texture.add_texture("./src/graphic/assets/bg.png", renderer, BACKGROUND);
	texture.add_texture("./src/graphic/assets/player_one.png", renderer, PLAYER_ONE);
	texture.add_texture("./src/graphic/assets/player_two.png", renderer, PLAYER_TWO);
	texture.add_texture("./src/graphic/assets/cross.png", renderer, CROSS);
	texture.add_texture("./src/graphic/assets/square.png", renderer, SQUARE);
}