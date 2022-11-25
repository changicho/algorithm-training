#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use DFS
// time : O(R * C * 3^L)
// space : O(R * C + L)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  bool recursive(vector<vector<char>>& board, vector<vector<bool>>& visited,
                 Axis axis, string& word, int index) {
    if (index == word.length()) return true;
    int rows = board.size(), cols = board.front().size();

    visited[axis.y][axis.x] = true;

    for (Axis dir : dirs) {
      Axis next = axis;
      next.y += dir.y;
      next.x += dir.x;

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
        continue;
      if (visited[next.y][next.x]) continue;
      if (board[next.y][next.x] != word[index]) continue;

      bool ret = recursive(board, visited, next, word, index + 1);

      if (ret) return true;
    }
    visited[axis.y][axis.x] = false;
    return false;
  }

 public:
  bool exist(vector<vector<char>>& board, string word) {
    int rows = board.size(), cols = board.front().size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (board[y][x] != word.front()) continue;
        bool ret = recursive(board, visited, {y, x}, word, 1);

        if (ret) return true;
      }
    }

    return false;
  }
};
