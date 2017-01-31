#ifndef BASE_SETUP_H_HPP
#define BASE_SETUP_H_HPP


//Platform-specific stuff
#ifdef _WIN32

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>

#elif __APPLE__

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

#else

#include <GL/gl.h>
#include <GL/glu.h>

#endif

//GLFW (phew)
#include <GLFW/glfw3.h>

struct EngineState {
    double time;
    double deltaTime;
};

extern GLFWwindow *window;

// User-called
int createAndRunWindow();

// User-defined
void display(EngineState state);
void initGL();


#endif //PROJECT1_SETUP_H_HPP
