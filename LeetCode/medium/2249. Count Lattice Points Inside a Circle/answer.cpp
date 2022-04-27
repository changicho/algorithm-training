#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use hash set
// time : O(N * R^2)
// space : O(1)
class Solution {
 private:
  int convert(int &y, int &x) { return y * 1000 + x; }

  double getDistance(int &y1, int &x1, int &y2, int &x2) {
    int yDiff = y2 - y1, xDiff = x2 - x1;
    return sqrt(yDiff * yDiff + xDiff * xDiff);
  }

 public:
  int countLatticePoints(vector<vector<int>> &circles) {
    unordered_set<int> points;

    for (vector<int> &c : circles) {
      int y = c[1], x = c[0], r = c[2];

      for (int y2 = y - r; y2 <= y + r; y2++) {
        for (int x2 = x - r; x2 <= x + r; x2++) {
          double length = getDistance(y, x, y2, x2);

          if (r >= length) points.insert(convert(y2, x2));
        }
      }
    }

    return points.size();
  }
};

// use hash set
// time : O(N * R^2)
// space : O(1)
class Solution {
 private:
  int convert(int y, int x) { return y * 1000 + x; }

  int getDistance(int y1, int x1, int y2, int x2) {
    int yDiff = y2 - y1, xDiff = x2 - x1;
    return yDiff * yDiff + xDiff * xDiff;
  }

 public:
  int countLatticePoints(vector<vector<int>> &circles) {
    unordered_set<int> points;

    for (vector<int> &c : circles) {
      int y = c[1], x = c[0], r = c[2];

      for (int y2 = y - r; y2 <= y + r; y2++) {
        for (int x2 = x - r; x2 <= x + r; x2++) {
          int length = getDistance(y, x, y2, x2);

          if (r * r >= length) points.insert(convert(y2, x2));
        }
      }
    }

    return points.size();
  }
};