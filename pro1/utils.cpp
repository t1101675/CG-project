#include <list>
#include <assert.h>
#include <vector>
#include <iostream>


#include "utils.h"

inline int abs(int a) { return a > 0 ? a : -a; }

void drawLine(int x1, int y1, int x2, int y2) {
  int dx = x2 - x1, dy = y2 - y1;
  int ux = dx > 0 ? 1 : -1, uy = dy > 0 ? 1 : -1;
  int dxAbs = abs(dx), dyAbs = abs(dy);
  int dxAbs2 = dxAbs << 1, dyAbs2 = dyAbs << 1;
  if (dxAbs > dyAbs) {
    int e = 0;
    for (int x = x1, y = y1; x != x2; x += ux) {
      glVertex2i(x, y);
      e += dyAbs2;
      if (e > dxAbs) {
        y += uy;
        e -= dxAbs2;
      }
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
}

void fill(const std::vector<Point2>& vp) {
  if (vp.size() <= 0) return;
  int yMin = 0x7fffffff;
  int yMax = yMin + 1;
  for (int i = 0; i < vp.size(); i++) {
    if (vp[i].y > yMax) yMax = vp[i].y;
    if (vp[i].y < yMin) yMin = vp[i].y;
  }

  std::list<ETNode>* NET = new std::list<ETNode>[yMax - yMin + 1];
  for (int y = yMin; y <= yMax; y++) {
    for (int i = 0; i < vp.size(); i++) {
      if (vp[i].y == y) {
        int prev = i > 0 ? i - 1 : vp.size();
        if (vp[prev].y > y) {
          int dy = vp[prev].y - vp[i].y;
          NET[y].push_back(ETNode(vp[i].x * (dy ? dy : 1),
                              (vp[prev].x - vp[i].x),
                              dy,
                              vp[prev].y));
        }
        int post = i + 1 < vp.size() ? i + 1 : 0;
        if (vp[post].y > y) {
          int dy = vp[post].y - vp[i].y;
          NET[y].push_back(ETNode(vp[i].x * (dy ? dy : 1),
                              (vp[post].x - vp[i].x),
                              dy,
                              vp[post].y));
        }
      }
    }
  }

  std::list<ETNode> AET;
  for (int y = yMin; y <= yMax; y++) {
    std::list<ETNode>::iterator itNET = NET[y].begin(), itAET = AET.begin();
    for (; itNET != NET[y].end(); ++itNET) {
      while (itAET != AET.end() && (*itAET).x < (*itNET).x) {
        itAET++;
      }
      AET.insert(itAET, *itNET);
    }

    assert(AET.size() % 2 == 0);

    itAET = AET.begin();
    while (itAET != AET.end()) {
      int xMin = 0;
      if ((*itAET).dy == 0) xMin = (*itAET).x;
      else xMin = (*itAET).x / (*itAET).dy;
      itAET++;
      int xMax = 0;
      if ((*itAET).dy == 0) xMax = (*itAET).x;
      else xMax = (*itAET).x / (*itAET).dy;
      itAET++;
      for (int x = xMin; x <= xMax; x++) {
        glVertex2i(x, y);
      }
    }

    for (itAET = AET.begin(); itAET != AET.end(); ++itAET) {
      if ((*itAET).yMax <= y) AET.erase(itAET);
      else (*itAET).x += (*itAET).dy ? (*itAET).dx : 0;
    }
  }
}
