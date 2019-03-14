#include <vector>
#include <iostream>

#include "utils.h"

int main(int argc, char** argv) {
  cv::Mat image(2560, 1440, CV_8UC3, cv::Scalar(0, 0, 0));
  /*hat*/
  drawLine(image, 800, 1280, 1130, 1335);
  drawLine(image, 800, 1280, 863, 900);
  drawLine(image, 1130, 1335, 1193, 955);
  drawLine(image, 663, 867, 1393, 988);
  drawLine(image, 850, 980, 1180, 1035);

  /*face*/
  drawLine(image, 1193, 955, 1210, 855);
  drawCircle(image, 928, 880, 102, 170, 388);
  drawLine(image, 1210, 855, 1020, 926);
  Point2 p[3] = {Point2(1210, 855), Point2(1020, 926), Point2(1193, 955)};
  std::vector<Point2> vp(p, p + 3);
  fill(image, vp);

  /*mouth*/
  drawCircle(image, 1044, 824, 168, 192, 373);
  drawLine(image, 932, 700, 1190, 743);
  drawLine(image, 954, 703, 960, 679);
  drawLine(image, 1004, 712, 1012, 661);
  drawLine(image, 1054, 721, 1064, 659);
  drawLine(image, 1104, 729, 1114, 674);
  drawLine(image, 1154, 737, 1160, 706);

  /*triangle*/
  drawLine(image, 750, 880, 750, 690);
  Point2 pTriangle[3] = {Point2(750, 690), Point2(730, 670), Point2(770, 670)};
  std::vector<Point2> vpTriangle(pTriangle, pTriangle + 3);
  fill(image, vpTriangle);

  cv::Mat temp_image;
  cv::transpose(image, temp_image);
  cv::flip(temp_image, image, 0);
  // cv::imshow("kid", image);
  cv::imwrite("kid.jpg", image);
  // cv::waitKey(0);
  return 0;
}
