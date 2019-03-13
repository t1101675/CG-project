#include <list>
#include <cmath>
#include <vector>
#include <assert.h>
#include <iostream>

#include "utils.h"

const double PI = 3.14159265;
const int N = 100;
const double DEG_TO_PI = PI / 180.0;

// inline int abs(int a) { return a > 0 ? a : -a; }

void drawLine(int x1, int y1, int x2, int y2) {
  glBegin(GL_POINTS);
  int dx = x2 - x1, dy = y2 - y1;
  int ux = dx > 0 ? 1 : -1, uy = dy > 0 ? 1 : -1;
  int dxAbs = abs(dx), dyAbs = abs(dy);
  int dxAbs2 = dxAbs << 1, dyAbs2 = dyAbs << 1;
  if (dxAbs > dyAbs) {
    int e = -dxAbs;
    for (int x = x1, y = y1; x != x2;) {
      glVertex2i(x, y);
      e += dyAbs2;
      x += ux;
      if (e >= 0) {
        y += uy;
        e -= dxAbs2;
      }
    }
  }
  else {
    int e = -dyAbs;
    for (int y = y1, x = x1; y != y2; y += uy) {
      glVertex2i(x, y);
      e += dxAbs2;
      if (e >= 0) {
        x += ux;
        e -= dyAbs2;
      }
    }
  }
  glVertex2i(x2, y2);
  glEnd();
}

void fill(const std::vector<Point2>& vp) {
  glBegin(GL_POINTS);
  if (vp.size() <= 0) return;
  int yMin = 0x7fffffff;
  int yMax = yMin + 1;
  for (int i = 0; i < vp.size(); i++) {
    if (vp[i].y > yMax) yMax = vp[i].y;
    if (vp[i].y < yMin) yMin = vp[i].y;
  }

  std::list<ETNode>* NET = new std::list<ETNode>[yMax - yMin + 1];
  for (int y = yMin, k = 0; y <= yMax; y++, k++) {
    for (int i = 0; i < vp.size(); i++) {
      if (vp[i].y == y) {
        int prev = i > 0 ? i - 1 : (vp.size() - 1);
        if (vp[prev].y > y) {
          int dy = vp[prev].y - vp[i].y;
          NET[k].push_back(ETNode((double)vp[i].x, dy ? (vp[prev].x - vp[i].x) / (double)dy : 0, vp[prev].y));
        }
        int post = (i + 1) < vp.size() ? i + 1 : 0;
        if (vp[post].y > y) {
          int dy = vp[post].y - vp[i].y;
          NET[k].push_back(ETNode((double)vp[i].x, dy ? (vp[post].x - vp[i].x) / (double)dy : 0, vp[post].y));
        }
      }
    }
  }

  // for (int y = yMin, k = 0; y <= yMax; y++, k++) {
  //   if (NET[k].size() > 0) {
  //     std::list<ETNode>::iterator itNET = NET[k].begin();
  //     std::cout << "at y = " << y << std::endl;
  //     while (itNET != NET[k].end()) {
  //       std::cout << "(" << (*itNET).x << ", " << (*itNET).dx << ", " << (*itNET).yMax << ")" << std::endl;
  //       ++itNET;
  //     }
  //   }
  // }

  std::list<ETNode> AET;
  for (int y = yMin, k = 0; y <= yMax; y++, k++) {
    std::list<ETNode>::iterator itNET = NET[k].begin(), itAET = AET.begin();

    /*delete edges y > yMax*/
    while (itAET != AET.end()) {
      if ((*itAET).yMax <= y) itAET = AET.erase(itAET);
      else ++itAET;
    }

    /*insert new edges*/
    for (; itNET != NET[k].end(); ++itNET) {
      itAET = AET.begin();
      while (itAET != AET.end()) {
        if ((*itAET).x < (*itNET).x) ++itAET;
        else if (((*itAET).x == (*itNET).x) && ((*itAET).dx < (*itNET).dx)) itAET++;
        else break;
      }
      AET.insert(itAET, *itNET);
    }
    /*after insertion, number of nodes in AET should %2 = 0*/

    // std::list<ETNode>::iterator testIt = AET.begin();
    // std::cout << "y = " << y << std::endl;
    // while (testIt != AET.end()) {
    //   std::cout << "(" << (*testIt).x << ", " << (*testIt).dx << ", " << (*testIt).yMax << ")" << std::endl;
    //   ++testIt;
    // }
    // std::cout << std::endl;
    assert(AET.size() % 2 == 0);

    /*draw vertex in a line*/
    itAET = AET.begin();
    while (itAET != AET.end()) {
      int xMin = (int)(*itAET).x;
      itAET++;
      int xMax = (int)(*itAET).x;
      itAET++;
      for (int x = xMin; x <= xMax; x++) {
        glVertex2i(x, y);
      }
    }

    /*update x*/
    for (itAET = AET.begin(); itAET != AET.end(); ++itAET) {
      (*itAET).x += (*itAET).dx;
    }
  }
  glEnd();
  delete[] NET;
}

void drawCircle(int x, int y, int r, int ang1, int ang2) {
  glBegin(GL_LINE_STRIP);
  double start = ang1 * DEG_TO_PI, end = ang2 * DEG_TO_PI;
  double delta = (end - start) / N;
  for (int i = 0; i <= N; i++) {
    glVertex2i(x + int(r * cos(start + delta * i)), y + int(r * sin(start + delta * i)));
  }
  glEnd();
}
