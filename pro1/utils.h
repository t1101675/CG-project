#include <vector>
#include <GL/glut.h>

struct Point2 {
  int x, y;
  Point(int xx = 0, int yy = 0): x(xx), y(yy) {}
};

struct ETNode {
  int x;
  int dx;
  int dy;
  int yMax;

  ETNode(int xx = 0, int ddx = 0, int ddy = 0, int yyMax = 0): x(xx), dx(ddx), dy(ddy), yMax(yyMax) {}
};

void drawLine(int x1, int y1, int x2, int y2);

void fill(const std::vector<Point2>& vp);
