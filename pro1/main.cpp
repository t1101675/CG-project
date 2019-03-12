#include <vector>
#include <iostream>

#include "utils.h"

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_POINTS);
  // drawLine(10, 10, 200, 100);
  std::vector<Point2> vp;
  vp.push_back(Point2(10, 10));
  vp.push_back(Point2(100, 100));
  vp.push_back(Point2(50, 0));
  fill(vp);
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
