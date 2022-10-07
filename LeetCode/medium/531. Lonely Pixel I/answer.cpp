#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use check row, col count
// time : O(R * C)
// space : O(R + C)
class Solution {
 public:
  int findLonelyPixel(vector<vector<char>>& picture) {
    int rows = picture.size();
    int cols = picture.front().size();

    vector<int> rowCounts(rows, 0), colCounts(cols, 0);

    int answer = 0;
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (picture[y][x] != 'B') continue;

        rowCounts[y]++;
        colCounts[x]++;
      }
    }

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (picture[y][x] != 'B') continue;

        if (rowCounts[y] == 1 && colCounts[x] == 1) answer++;
      }
    }
    return answer;
  }
};