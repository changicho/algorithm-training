#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(N^2)
// space : O(N^2)
class Solution {
 public:
  vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
    int size = grid.size();

    vector<vector<int>> answer(size - 2, vector<int>(size - 2));

    for (int y = 0; y < size - 2; y++) {
      for (int x = 0; x < size - 2; x++) {
        answer[y][x] = grid[y][x];

        for (int i = 0; i < 3; i++) {
          for (int j = 0; j < 3; j++) {
            answer[y][x] = max(answer[y][x], grid[y + i][x + j]);
          }
        }
      }
    }
    return answer;
  }
};