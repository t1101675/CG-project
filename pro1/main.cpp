#include <iostream>
#include "utils.h"

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_POINTS);
  std::cout << "OK" << std::endl;
  // glVertex2i(700, 15);
  // glVertex2i(100, 555);
  drawLine(10, 10, 200, 100);
  // drawLine(10, 10, 200, 400);
  // drawLine(10, 10, -100, -200);
  // drawLine(10, 10, -100, -700);
  // drawLine(10, 10, 500, -300);
  // drawLine(10, 10, -100, 400);
  glEnd();
  glFlush();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(500, 500);
  glutCreateWindow("test");
  gluOrtho2D(-500.0, 800.0,-500.0, 800.0);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
