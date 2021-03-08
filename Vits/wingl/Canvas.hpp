#ifndef VITS_CANVAS
#define VITS_CANVAS

#include <SDL2/SDL.h>

class Canvas {
public:
	Canvas(int width, int height);
	virtual ~Canvas();
private:
	SDL_Surface* surface;
};

#endif
