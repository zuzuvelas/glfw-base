#include "setup.hpp"

#include <iostream>
#include <glm/trigonometric.hpp>
#include <glm/gtc/constants.hpp>

using namespace std;
using namespace glm;

int main(int argc, char **argv) {
  createAndRunWindow();
  return 0;
}

void initGL() {
  glClearColor(1.0, 0.87, 0.678, 0.0);
}

void display(double time) {
  // write your display function here

  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0, 0.807, 1.0);

  glPushMatrix();
  glTranslatef(0.5, 0.5, 0);
  glRotated(degrees(quarter_pi<double>() + half_pi<double>()), 0, 0, -1);

  for (double offset = -half_pi<double>(); offset < half_pi<double>(); offset += half_pi<double>() / 16) {
    glPushMatrix();
    glRotated(degrees(time * offset * 2), 0, 0, -1);

    glBegin(GL_QUADS);
    {
      glVertex3f(0.15f, 0.15f, 0.0);
      glVertex3f(0.25f, 0.15f, 0.0);
      glVertex3f(0.25f, 0.25f, 0.0);
      glVertex3f(0.15f, 0.25f, 0.0);
    }
    glEnd();

    glPopMatrix();
  }

  glPopMatrix();
  glFlush();
}