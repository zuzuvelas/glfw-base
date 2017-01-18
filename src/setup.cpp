#include <iostream>
#include "setup.hpp"

using namespace std;

GLFWwindow *window;
double nextFpsCheck;
long long frames;

void mainLoop();
void initGLDefault();

void error_callback(int error, const char *description) {
  fprintf(stderr, "Error: %d: %s\n", error, description);
}

int createAndRunWindow() {
  glfwSetErrorCallback(error_callback);
  if (!glfwInit()) {
    cerr << "Error initializing glfw" << endl;
    return 1;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  window = glfwCreateWindow(350, 350, "Polygon - The Adventure Begins", NULL, NULL);
  if (window == nullptr) {
    cerr << "Error creating window" << endl;
    glfwTerminate();
    return 1;
  }

  initGLDefault();
  initGL();
  mainLoop();

  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}

void initGLDefault() {
  glfwMakeContextCurrent(window);

  int width, height;
  glfwGetFramebufferSize(window, &width, &height);
  glViewport(0, 0, width, height);

  glfwSwapInterval(1);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

  glClearColor(1, 1, 1, 0);
}

void mainLoop() {
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();

    glfwMakeContextCurrent(window);
    double time = glfwGetTime();
    display(time);
    glfwSwapBuffers(window);

    if (time > nextFpsCheck) {
      nextFpsCheck = time + 1;
      cout << "FPS: " << frames << endl;
      frames = 0;
    }
    frames++;
  }
}