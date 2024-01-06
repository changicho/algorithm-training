#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use count row col
// time : O(R * C)
// space : O(R + C)
class Solution {
 public:
  vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();

    vector<int> oneRows(rows, 0), oneCols(cols, 0);
    vector<int> zeroRows(rows, 0), zeroCols(cols, 0);

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (grid[y][x] == 1) {
          oneRows[y]++;
          oneCols[x]++;
        } else {
          zeroRows[y]++;
          zeroCols[x]++;
        }
      }
    }

    vector<vector<int>> answer(rows, vector<int>(cols));
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        answer[y][x] = oneRows[y] + oneCols[x] - zeroRows[y] - zeroCols[x];
      }
    }
    return answer;
  }
};