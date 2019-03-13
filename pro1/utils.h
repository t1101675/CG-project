#include <vector>
#include <GL/glut.h>

struct Point2 {
  int x, y;
  Point2(int xx = 0, int yy = 0): x(xx), y(yy) {}
};

struct ETNode {
  double x;
  double dx;
  int yMax;

  ETNode(double xx = 0, double ddx = 0, int yyMax = 0): x(xx), dx(ddx), yMax(yyMax) {}
};

void drawLine(int x1, int y1, int x2, int y2);

void fill(const std::vector<Point2>& vp);

void drawCircle(int x, int y, int r, int ang1, int ang2);
