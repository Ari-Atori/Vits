#ifndef VITS_GLWINDOW
#define VITS_GLWINDOW

#include <SDL2/SDL.h>
#include <string>

class GLWindow {
public:
	GLWindow(int, int, std::string);
	virtual ~GLWindow();
	void clear();
	void swap();

	int width() { return w; }
	int height() { return h; }

	void read(int*, int*, void*);
	void write(int, int, const void*);
private:
	SDL_Window* window;
	SDL_GLContext context;
	int w, h;
};

#endif