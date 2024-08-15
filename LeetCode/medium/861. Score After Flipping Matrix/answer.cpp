#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use greedy
// time : O(R * C)
// space : O(1)
class Solution {
 private:
  void flipRow(vector<int> &row) {
    for (int &n : row) {
      n = !n;
    }
  }

 public:
  int matrixScore(vector<vector<int>> &grid) {
    int rows = grid.size(), cols = grid[0].size();

    for (vector<int> &row : grid) {
      if (row[0] == 0) {
        flipRow(row);
      }
    }

    int answer = 0;
    for (int x = 0; x < cols; x++) {
      int bit = 1 << (cols - 1 - x);

      int oneCount = 0, zeroCount = 0;
      for (int y = 0; y < rows; y++) {
        if (grid[y][x] == 1) {
          oneCount++;
        } else {
          zeroCount++;
        }
      }

      answer += max(oneCount, zeroCount) * bit;
    }
    return answer;
  }
};