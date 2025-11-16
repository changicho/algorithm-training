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

// use 2D diff
// time : O(Q + N^2)
// space : O(N^2)
class Solution {
 public:
  vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
    int rows = n, cols = n;

    vector<vector<int>> diffs(rows + 1, vector<int>(cols + 1, 0));

    for (vector<int>& q : queries) {
      int row1 = q[0], col1 = q[1], row2 = q[2], col2 = q[3];

      diffs[row1][col1]++;
      diffs[row2 + 1][col1]--;
      diffs[row1][col2 + 1]--;
      diffs[row2 + 1][col2 + 1]++;
    }

    vector<vector<int>> answer(rows, vector<int>(cols, 0));
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        int diff = diffs[y][x];
        int fromTop = (y == 0) ? 0 : answer[y - 1][x];
        int fromLeft = (x == 0) ? 0 : answer[y][x - 1];
        int fromTopLeft = (y == 0 || x == 0) ? 0 : answer[y - 1][x - 1];

        answer[y][x] = diff + fromTop + fromLeft - fromTopLeft;
      }
    }
    return answer;
  }
};

// use 1D diff
// time : O((Q + N) * N)
// space : O(N^2)
class Solution {
 public:
  vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
    int rows = n, cols = n;

    vector<vector<int>> diffs(rows, vector<int>(cols + 1, 0));

    for (vector<int>& q : queries) {
      int row1 = q[0], col1 = q[1], row2 = q[2], col2 = q[3];

      for (int y = row1; y <= row2; y++) {
        diffs[y][col1]++;
        diffs[y][col2 + 1]--;
      }
    }

    vector<vector<int>> answer(rows, vector<int>(cols, 0));
    for (int y = 0; y < rows; y++) {
      int diff = 0;
      for (int x = 0; x < cols; x++) {
        diff += diffs[y][x];
        answer[y][x] = diff;
      }
    }
    return answer;
  }
};