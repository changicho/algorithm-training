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

// brute force
// time : O(N^2)
// space : O(N^2)
class Solution {
  vector<vector<int>> rotate(vector<vector<int>>& mat) {
    int rows = mat.size(), cols = mat[0].size();

    vector<vector<int>> temp(rows, vector<int>(cols));

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        temp[x][rows - y - 1] = mat[y][x];
      }
    }

    return temp;
  }

 public:
  bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
    for (int d = 0; d < 4; d++) {
      if (mat == target) {
        return true;
      }
      mat = rotate(mat);
    }
    return false;
  }
};

// brute force (in place)
// time : O(N^2)
// space : O(1)
class Solution {
  pair<int, int> moveNext(pair<int, int> pos, int rows, int cols) {
    int y = pos.first, x = pos.second;
    return {x, rows - y - 1};
  }

  void rotate(vector<vector<int>>& mat) {
    int rows = mat.size(), cols = mat[0].size();

    for (int y = 0; y < rows; y++) {
      for (int x = y; x < cols - y - 1; x++) {
        int temp = mat[y][x];
        pair<int, int> pos = {y, x};

        for (int d = 0; d < 4; d++) {
          pair<int, int> next = moveNext(pos, rows, cols);
          int before = temp;
          temp = mat[next.first][next.second];
          mat[next.first][next.second] = before;
          pos = next;
        }
      }
    }
  }

 public:
  bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
    for (int d = 0; d < 4; d++) {
      if (mat == target) {
        return true;
      }
      rotate(mat);
    }
    return false;
  }
};