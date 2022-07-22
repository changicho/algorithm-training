#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use cross product
// time : O(N)
// space : O(1)
class Solution {
 private:
  long getDet(vector<int> &a, vector<int> &b, vector<int> &c) {
    return (b[0] - a[0]) * (c[1] - a[1]) - (b[1] - a[1]) * (c[0] - a[0]);
  }

 public:
  bool isConvex(vector<vector<int>> &points) {
    int size = points.size();

    bool isPositive = 0, isNegative = 0;
    for (int i = 0; i < size; i++) {
      int i1 = i;
      int i2 = (i + 1) % size;
      int i3 = (i + 2) % size;

      long det = getDet(points[i1], points[i2], points[i3]);
      isPositive |= (det > 0);
      isNegative |= (det < 0);
      if (isPositive && isNegative) return false;
    }

    return true;
  }
};