#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use one pass
// time : O(R * C)
// space : O(1)
class Solution {
 public:
  vector<vector<int>> findFarmland(vector<vector<int>>& land) {
    int rows = land.size(), cols = land[0].size();
    vector<vector<int>> answer;

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (land[y][x]) {
          int ny = y, nx = x;

          for (ny = y; ny < rows && land[ny][x]; ny++) {
            for (nx = x; nx < cols && land[ny][nx]; nx++) {
              land[ny][nx] = 0;
            }
          }

          answer.push_back({y, x, ny - 1, nx - 1});
        }
      }
    }
    return answer;
  }
};