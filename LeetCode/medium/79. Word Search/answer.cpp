#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

// use recursive

class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    int rows = board.size();
    int cols = board.front().size();

    int index = 0;

    vector<Axis> starts;

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (board[y][x] == word.front()) starts.push_back({y, x});
      }
    }

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    for (Axis start : starts) {
      visited[start.y][start.x] = true;
      bool ret = recursive(board, visited, start, word, 1);
      visited[start.y][start.x] = false;

      if (ret) return true;
    }

    return false;
  }

  bool recursive(vector<vector<char>>& board, vector<vector<bool>>& visited, Axis start, string word, int index) {
    if (index == word.length()) return true;

    int rows = board.size();
    int cols = board.front().size();

    for (Axis dir : dirs) {
      Axis next = start;
      next.y += dir.y;
      next.x += dir.x;

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols) continue;
      if (visited[next.y][next.x]) continue;
      if (board[next.y][next.x] != word[index]) continue;

      visited[next.y][next.x] = true;
      bool ret = recursive(board, visited, next, word, index + 1);
      visited[next.y][next.x] = false;

      if (ret) return true;
    }
    return false;
  }
};

// not use Axis

class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    rows = board.size();
    cols = board.front().size();

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (adjacentSearch(board, word, y, x, 0))
          return true;
      }
    }
    return false;
  }

  int rows;
  int cols;
  bool adjacentSearch(vector<vector<char>>& board, const string& word, int y, int x, int index) {
    if (index == word.size()) return true;
    if (y < 0 || x < 0 || y >= rows || x >= cols) return false;
    if (board[y][x] != word[index]) return false;

    board[y][x] = '*';
    bool furtherSearch = adjacentSearch(board, word, y + 1, x, index + 1) ||  // up
                         adjacentSearch(board, word, y - 1, x, index + 1) ||  // down
                         adjacentSearch(board, word, y, x - 1, index + 1) ||  // left
                         adjacentSearch(board, word, y, x + 1, index + 1);    // right

    board[y][x] = word[index];
    return furtherSearch;
  }
};