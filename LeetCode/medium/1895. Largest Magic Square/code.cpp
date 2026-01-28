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

// use prefix sum & brute force
// time : O(R * C * min(R, C)^2)
// space : O(R * C)
class Solution {
 public:
  int largestMagicSquare(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();
    int maxLength = min(rows, cols);

    vector<vector<int>> rowPrefixes(rows + 1, vector<int>(cols + 1, 0));
    vector<vector<int>> colPrefixes(rows + 1, vector<int>(cols + 1, 0));

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        rowPrefixes[y + 1][x + 1] = rowPrefixes[y + 1][x] + grid[y][x];
        colPrefixes[y + 1][x + 1] = colPrefixes[y][x + 1] + grid[y][x];
      }
    }

    function<bool(int, int, int)> check = [&](int y, int x, int length) {
      int sum = rowPrefixes[y + 1][x + length] - rowPrefixes[y + 1][x];

      for (int i = 0; i < length; i++) {
        int rowSum =
            rowPrefixes[y + 1 + i][x + length] - rowPrefixes[y + 1 + i][x];
        int colSum =
            colPrefixes[y + length][x + 1 + i] - colPrefixes[y][x + 1 + i];
        if (rowSum != sum) return false;
        if (colSum != sum) return false;
      }

      int diagonal1 = 0, diagonal2 = 0;
      for (int i = 0; i < length; i++) {
        diagonal1 += grid[y + i][x + i];
        diagonal2 += grid[y + length - 1 - i][x + i];
      }
      if (diagonal1 != sum || diagonal2 != sum) return false;
      return true;
    };

    int answer = 1;
    for (int length = 2; length <= maxLength; length++) {
      for (int y = 0; y <= rows - length; y++) {
        for (int x = 0; x <= cols - length; x++) {
          bool result = check(y, x, length);
          if (result) {
            answer = length;
          }
        }
      }
    }

    return answer;
  }
};