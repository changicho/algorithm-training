#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use brute force with move pointer
// time : O(R * C)
// space : O(R * C)
class Solution {
 public:
  vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
    int rows = box.size(), cols = box[0].size();

    vector<vector<char>> answer(cols, vector<char>(rows, '.'));
    for (int y = 0; y < rows; y++) {
      int count = 0;

      int lastI = cols - 1;
      while (lastI > 0 && box[y][lastI] == '*') {
        lastI--;
      }
      for (int x = cols - 1; x >= 0; x--) {
        if (box[y][x] != '#') {
          if (box[y][x] == '*') {
            lastI = x - 1;
            while (lastI > 0 && box[y][lastI] == '*') {
              lastI--;
            }
          }
          continue;
        }

        box[y][x] = '.';
        box[y][lastI] = '#';

        lastI--;
        while (lastI > 0 && box[y][lastI] == '*') {
          lastI--;
        }
      }

      for (int x = 0; x < cols; x++) {
        answer[x][rows - 1 - y] = box[y][x];
      }
    }

    return answer;
  }
};