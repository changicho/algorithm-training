#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(R * C)
// space : O(1)
class Solution {
 public:
  vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size();

    for (int x = 0; x < cols; x++) {
      int maximum = 0;
      for (int y = 0; y < rows; y++) {
        maximum = max(maximum, matrix[y][x]);
      }

      for (int y = 0; y < rows; y++) {
        if (matrix[y][x] == -1) {
          matrix[y][x] = maximum;
        }
      }
    }
    return matrix;
  }
};