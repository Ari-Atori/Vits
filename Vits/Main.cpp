#include <iostream>
#include "System.hpp"
#include "wingl/GLWindow.hpp"
#include "wingl/Window.hpp"

int main(int c, char** v) {
	System::init();
	GLWindow glwin(640, 360, "Test GL Window");
	Window window(1280, 720, "Color Blind Window");

	
	while (Window::windows() > 0) {
		Window::update();
	}
	return System::exit(0);
}