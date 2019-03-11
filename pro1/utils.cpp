#include "utils.h"
#include <iostream>

inline int abs(int a) { return a > 0 ? a : -a; }

void drawLine(int x1, int y1, int x2, int y2) {
  int dx = x2 - x1, dy = y2 - y1;
  int ux = dx > 0 ? 1 : -1, uy = dy > 0 ? 1 : -1;
  int dxAbs = abs(dx), dyAbs = abs(dy);
  int dxAbs2 = dxAbs << 1, dyAbs2 = dyAbs << 1;
  // std::cout << dxAbs2 << " " << dyAbs2 << std::endl;
  if (dxAbs > dyAbs) {
    int e = 0;
    for (int x = x1, y = y1; x != x2; x += ux) {
      glVertex2i(x, y);
      e += dyAbs2;
      if (e > dxAbs) {
        y += uy;
        e -= dxAbs2;
      }
      std::cout << x << " " << y << std::endl;
    }
  }
  else {
    int e = 0;
    for (int y = y1, x = x1; y != y2; y += uy) {
      glVertex2i(x, y);
      e += dxAbs2;
      if (e > dyAbs) {
        x += ux;
        e -= dyAbs2;
      }
    }
  }
  glVertex2i(x2, y2);
  std::cout << x2 << " " << y2 << std::endl;
}
