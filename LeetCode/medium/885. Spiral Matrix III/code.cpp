#include <algorithm>
#include <climits>
#include <cmath>
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

// use simulation
// time : O(max(R,C)^2)
// space : O(R*C)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

  Axis dirs[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

 public:
  vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                      int cStart) {
    int limit = rows * cols;

    vector<vector<int>> path;
    int dir = 0;
    int temp = 0;
    int dirLimit = 1;
    int turnCount = 0;

    int val = 1;
    Axis cur = {rStart, cStart};

    while (val <= limit) {
      if (cur.y < 0 || cur.y >= rows || cur.x < 0 || cur.x >= cols) {
      } else {
        path.push_back({cur.y, cur.x});
        val++;
      }

      cur.y += dirs[dir].y;
      cur.x += dirs[dir].x;

      temp++;
      if (temp == dirLimit) {
        dir = (dir + 1) % 4;
        temp = 0;
        turnCount++;

        if (turnCount % 2 == 0) {
          dirLimit++;
        }
      }
    }

    return path;
  }
};