#include <iostream>
#include "utils.h"

void display() {
  glCLear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0, 1.0, 0.0);
  glBegin(GL_POINTS);
  drawLine(10, 10, 50, 50);
  glEnd();
  glFlush();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(500, 500);
  glutCreateWindow("test");
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
