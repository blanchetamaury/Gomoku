#include "graphic/include/include.hpp"
#include "graphic/init/init.hpp"
#include "graphic/init/texture/init_texture.hpp"

#define TARGET_FPS 60

void	listenEvent(bool &running, SDL_Event *event)
{
	while (SDL_PollEvent(event))
	{
		if (event->type == SDL_QUIT)
			running = 0;
		if (event->type == SDL_KEYDOWN)
		{
			if (event->key.keysym.sym == SDLK_ESCAPE)
				running = 0;
		}
	}
}

int main() {
	Init graph;
	Init_texture black("./src/graphic/assets/black.png", graph.renderer);
	Init_texture White("./src/graphic/assets/white.png", graph.renderer);
	Uint32	frame_time;
	Uint32	frame_duration;
	Uint32	start_time;
	SDL_Event		event;
	bool	running = true;

	frame_time = 1000 / TARGET_FPS;
	while (running)
	{
		listenEvent(running, &event);
		start_time = SDL_GetTicks();
		SDL_SetRenderDrawColor(graph.renderer, 0, 0, 0, 255);
		SDL_RenderClear(graph.renderer);
		SDL_RenderPresent(graph.renderer);
		frame_duration = SDL_GetTicks() - start_time;
		if (frame_duration < frame_time)
			SDL_Delay(frame_time - frame_duration);
	}
}