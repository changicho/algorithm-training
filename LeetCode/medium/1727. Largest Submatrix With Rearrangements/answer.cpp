#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort
// time : O(R * C * log_2(C))
// space : O(C)
class Solution {
 public:
  int largestSubmatrix(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int answer = 0;

    for (int y = 0; y < rows; y++) {
      if (y > 0) {
        for (int x = 0; x < cols; x++) {
          if (matrix[y][x] == 0) continue;

          matrix[y][x] += matrix[y - 1][x];
        }
      }

      vector<int> curRow = matrix[y];
      sort(curRow.begin(), curRow.end(), greater());
      for (int x = 0; x < cols; x++) {
        answer = max(answer, curRow[x] * (x + 1));
      }
    }

    return answer;
  }
};