#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use counting
// time : O(R * C)
// space : O(R + C)
class Solution {
 public:
  int numSpecial(vector<vector<int>>& mat) {
    int rows = mat.size(), cols = mat[0].size();

    vector<int> rowCounts(rows, 0), colCounts(cols, 0);

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        rowCounts[y] += mat[y][x];
        colCounts[x] += mat[y][x];
      }
    }

    int answer = 0;
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (mat[y][x] == 1 && rowCounts[y] == 1 && colCounts[x] == 1) {
          answer++;
        }
      }
    }
    return answer;
  }
};