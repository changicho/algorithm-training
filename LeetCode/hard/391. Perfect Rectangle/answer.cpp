#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use checking corner (BST map)
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  bool isRectangleCover(vector<vector<int>>& rectangles) {
    map<pair<int, int>, int> corners;

    for (vector<int>& r : rectangles) {
      int x1 = r[0], y1 = r[1], x2 = r[2], y2 = r[3];

      corners[{x1, y1}]++;  // bottomLeft
      corners[{x1, y2}]--;  // upLeft
      corners[{x2, y1}]--;  // bottomRight
      corners[{x2, y2}]++;  // upRight
    }

    int cornerCount = 0;
    for (auto& ptr : corners) {
      if (ptr.second == 0) continue;
      if (abs(ptr.second) != 1) return false;

      cornerCount++;
    }

    return cornerCount == 4;
  }
};

// use checking corner (hash map)
// time : O(N)
// space : O(N)
class Solution {
 public:
  bool isRectangleCover(vector<vector<int>>& rectangles) {
    unordered_map<int, unordered_map<int, int>> corners;

    for (vector<int>& r : rectangles) {
      int x1 = r[0], y1 = r[1], x2 = r[2], y2 = r[3];
      corners[x1][y1]++;  // bottomLeft
      corners[x1][y2]--;  // upLeft
      corners[x2][y1]--;  // bottomRight
      corners[x2][y2]++;  // upRight
    }

    int cornerCount = 0;
    for (auto& it : corners) {
      for (auto& it2 : it.second) {
        if (it2.second == 0) continue;
        if (abs(it2.second) != 1) return false;

        cornerCount++;
      }
    }
    return cornerCount == 4;
  }
};
