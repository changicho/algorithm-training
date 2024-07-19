#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use two pass
// time : O(R * C)
// space : (R * C)
class Solution {
 public:
  vector<int> luckyNumbers(vector<vector<int>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size();

    vector<int> rowMins(rows, INT_MAX);
    vector<int> colMaxs(cols, INT_MIN);

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        rowMins[y] = min(rowMins[y], matrix[y][x]);
        colMaxs[x] = max(colMaxs[x], matrix[y][x]);
      }
    }

    vector<int> answer;
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        int cur = matrix[y][x];

        if (rowMins[y] == cur && colMaxs[x] == cur) {
          answer.push_back(cur);
        }
      }
    }
    return answer;
  }
};