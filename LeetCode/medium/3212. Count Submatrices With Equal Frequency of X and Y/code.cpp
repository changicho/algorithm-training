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

// 2D prefix sum
// time : O(RC)
// space : O(RC)
class Solution {
 public:
  int numberOfSubmatrices(vector<vector<char>>& grid) {
    int rows = grid.size(), cols = grid[0].size();

    int xDp[1001][1001] = {
        0,
    };
    int yDp[1001][1001] = {
        0,
    };

    int answer = 0;
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        xDp[y][x] = (grid[y][x] == 'X');
        yDp[y][x] = (grid[y][x] == 'Y');

        if (x > 0) {
          xDp[y][x] += xDp[y][x - 1];
          yDp[y][x] += yDp[y][x - 1];
        }

        if (y > 0) {
          xDp[y][x] += xDp[y - 1][x];
          yDp[y][x] += yDp[y - 1][x];
        }

        if (x > 0 && y > 0) {
          xDp[y][x] -= xDp[y - 1][x - 1];
          yDp[y][x] -= yDp[y - 1][x - 1];
        }

        int xCount = xDp[y][x];
        int yCount = yDp[y][x];

        if (xCount > 0 && (xCount == yCount)) {
          answer++;
        }
      }
    }

    return answer;
  }
};