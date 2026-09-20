#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;

// math (center compare)
// time : O(1)
// space : O(1)
class Solution {
 public:
  bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1,
                    int x2, int y2) {
    long long xDiff = 0;
    if (xCenter < x1 || xCenter > x2) {
      xDiff = min(abs(x1 - xCenter), abs(x2 - xCenter));
    }
    long long yDiff = 0;
    if (yCenter < y1 || yCenter > y2) {
      yDiff = min(abs(y1 - yCenter), abs(y2 - yCenter));
    }
    return pow(xDiff, 2) + pow(yDiff, 2) <= radius * radius;
  }
};