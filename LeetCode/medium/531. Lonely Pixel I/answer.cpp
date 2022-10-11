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

// use check row, col count (space optimized)
// time : O(R * C)
// space : O(1)
class Solution {
 public:
  bool isLonely(vector<vector<char>>& picture, int originY, int originX) {
    int rows = int(picture.size());
    int cols = int(picture.front().size());

    int count = 0;
    for (int y = 0; y < rows; y++) {
      count += (picture[y][originX] == 'B');
    }

    for (int x = 0; x < cols; x++) {
      if (x == originX) continue;
      count += (picture[originY][x] == 'B');
    }
    return picture[originY][originX] == 'B' && count == 1;
  }

  int findLonelyPixel(vector<vector<char>>& picture) {
    int rows = int(picture.size());
    int cols = int(picture[0].size());

    int answer = 0;
    for (int x = 0; x < cols; x++) {
      answer += isLonely(picture, 0, x);
    }
    for (int y = 1; y < rows; y++) {
      answer += isLonely(picture, y, 0);
    }

    for (int x = 0; x < cols; x++) {
      picture[0][x] = (picture[0][x] == 'B' ? '1' : '0');
    }
    for (int y = 0; y < rows; y++) {
      picture[y][0] = (picture[y][0] == 'B' ? '1' : '0');
    }

    for (int y = 1; y < rows; y++) {
      for (int x = 1; x < cols; x++) {
        if (picture[y][x] == 'B') {
          picture[y][0]++;
          picture[0][x]++;
        }
      }
    }

    for (int y = 1; y < rows; y++) {
      for (int x = 1; x < cols; x++) {
        if (picture[y][x] == 'B') {
          if (picture[0][x] == '1' && picture[y][0] == '1') {
            answer++;
          }
        }
      }
    }

    return answer;
  }
};
