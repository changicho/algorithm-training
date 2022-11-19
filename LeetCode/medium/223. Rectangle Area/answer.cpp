#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use overlapped checking
// time : O(1)
// space : O(1)
class Solution {
 private:
  bool isOverlapped(int a1, int a2, int b1, int b2) {
    return a2 > b1 && b2 > a1;
  }

  int getArea(int x1, int y1, int x2, int y2) {
    int yDiff = y2 - y1, xDiff = x2 - x1;

    return yDiff * xDiff;
  }

 public:
  int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2,
                  int by2) {
    int ret = 0;
    ret += getArea(ax1, ay1, ax2, ay2);
    ret += getArea(bx1, by1, bx2, by2);

    if (isOverlapped(ax1, ax2, bx1, bx2) && isOverlapped(ay1, ay2, by1, by2)) {
      int x1 = max(ax1, bx1), x2 = min(ax2, bx2);
      int y1 = max(ay1, by1), y2 = min(ay2, by2);

      ret -= getArea(x1, y1, x2, y2);
    }
    return ret;
  }
};