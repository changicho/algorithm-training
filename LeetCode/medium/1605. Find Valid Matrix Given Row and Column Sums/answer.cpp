#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use greedy
// time : O(R * C)
// space : O(R * C)
class Solution {
 public:
  vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
    int rows = rowSum.size(), cols = colSum.size();

    vector<vector<int>> matrix(rows, vector<int>(cols, 0));

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        int cur = min(rowSum[y], colSum[x]);

        rowSum[y] -= cur;
        colSum[x] -= cur;

        matrix[y][x] = cur;
      }
    }

    return matrix;
  }
};