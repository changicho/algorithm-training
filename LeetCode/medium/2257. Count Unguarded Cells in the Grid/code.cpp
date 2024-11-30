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

// use brute force & backtracking
// time : O(G * R * C)
// space : O(R * C)
class Solution {
 private:
  vector<int> dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  const int WALL = 1, GUARD = 2, FILLED = 3;

  void fill(vector<vector<int>> &board, vector<int> g) {
    int rows = board.size(), cols = board[0].size();

    for (vector<int> &dir : dirs) {
      vector<int> cur = {g[0] + dir[0], g[1] + dir[1]};
      while (true) {
        if (cur[0] >= rows || cur[0] < 0 || cur[1] >= cols || cur[1] < 0) break;
        if (board[cur[0]][cur[1]] == WALL) break;
        if (board[cur[0]][cur[1]] == GUARD) break;

        board[cur[0]][cur[1]] = FILLED;

        cur = {cur[0] + dir[0], cur[1] + dir[1]};
      }
    }
  }

 public:
  int countUnguarded(int m, int n, vector<vector<int>> &guards,
                     vector<vector<int>> &walls) {
    vector<vector<int>> board(m, vector<int>(n, 0));

    for (vector<int> &g : guards) {
      board[g[0]][g[1]] = GUARD;
    }
    for (vector<int> &w : walls) {
      board[w[0]][w[1]] = WALL;
    }

    for (vector<int> &g : guards) {
      fill(board, g);
    }

    int answer = 0;
    for (int y = 0; y < m; y++) {
      for (int x = 0; x < n; x++) {
        if (board[y][x] == 0) answer++;
      }
    }
    return answer;
  }
};