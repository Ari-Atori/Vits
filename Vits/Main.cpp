#include <iostream>
#include "System.hpp"
#include "wingl/GLWindow.hpp"


int main(int c, char* v[]) {
	System::init();

	GLWindow glwin(360, 640, "Test GL Window");

	SDL_Delay(5000);

	return System::exit(0);
}