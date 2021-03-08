#ifndef VITS_RECTANGLE
#define VITS_RECTANGLE

#include <GL/glew.h>

class Rectangle {
public:
    Rectangle();
    virtual ~Rectangle();

    static void init(unsigned int n);
    void bind();
    void draw();
    void free();
private:
    GLuint vao;
    GLuint vbo[3];
};

#endif
