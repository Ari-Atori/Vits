#include "GLWindow.hpp"
#include <GL/glew.h>
#include <iostream>

GLWindow::GLWindow(int width, int height, std::string title) {
	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_HIDDEN | SDL_WINDOW_BORDERLESS);
	context = SDL_GL_CreateContext(window);
	w = width; h = height;
}

GLWindow::~GLWindow() {
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
}

void GLWindow::clear() {
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
}

void GLWindow::swap() {
	SDL_GL_SwapWindow(window);
}

void GLWindow::read(int* w, int* h, void* data) {
	SDL_GetWindowSize(window, w, h);
	glReadPixels(0, 0, *w, *h, GL_RGBA, GL_UNSIGNED_BYTE, data);
}

void GLWindow::write(int w, int h, const void* data) {
	glDrawPixels(0, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
}