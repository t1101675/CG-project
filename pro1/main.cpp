#include <vector>
#include <iostream>

#include "utils.h"

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_POINTS);
  // drawLine(100, 100, 1000, 1000);
  // drawLine(100, 100, 500, 0);
  // drawLine(500, 0, 1000, 1000);
  std::vector<Point2> vp;
  vp.push_back(Point2(1000, 1400));
  vp.push_back(Point2(1000, 1400));
  vp.push_back(Point2(1340, 200));
  vp.push_back(Point2(-356, -1567));
  vp.push_back(Point2(-1336, -967));
  vp.push_back(Point2(-1006, 1567));
  // vp.push_back(Point2(-356, -1567));
  fill(vp);
  glEnd();

  // glBegin(GL_LINES);
  // glVertex2i(100, 100);
  // glVertex2i(300, 200);
  // glVertex2i(500, 300);
  // glEnd();
  glFlush();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(1000, 1000);
  glutCreateWindow("test");
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(-2000, 2000, -2000, 2000);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
