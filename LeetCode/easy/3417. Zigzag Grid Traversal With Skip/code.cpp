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
// time : O(R * C)
// space : O(R * C)
class Solution {
 public:
  vector<int> zigzagTraversal(vector<vector<int>>& grid) {
    vector<int> answer;

    int rows = grid.size();
    int cols = grid[0].size();

    bool startZero = true;
    for (int y = 0; y < rows; y++) {
      bool isRight = y % 2 == 0;

      if (isRight) {
        int x = 0 + !startZero;

        for (; x < cols; x += 2) {
          answer.push_back(grid[y][x]);
        }

        startZero = x == cols;
      } else {
        int x = cols - 1 - !startZero;

        for (; x >= 0; x -= 2) {
          answer.push_back(grid[y][x]);
        }

        startZero = x == -1;
      }
    }

    return answer;
  }
};