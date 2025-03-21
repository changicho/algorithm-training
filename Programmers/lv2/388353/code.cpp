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

struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int convertAxis(Axis &a) { return a.y * 100 + a.x; }

vector<vector<char>> getBoard(vector<string> &storage) {
  int rows = storage.size(), cols = storage[0].size();

  vector<vector<char>> board(rows + 2, vector<char>(cols + 2, '0'));
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      board[y + 1][x + 1] = storage[y][x];
    }
  }
  return board;
}

unordered_map<char, unordered_set<int>> getEdges(vector<vector<char>> &board) {
  int rows = board.size(), cols = board[0].size();

  unordered_map<char, unordered_set<int>> um;

  queue<Axis> q;
  bool visited[55][55] = {
      false,
  };
  visited[0][0] = true;
  q.push({0, 0});

  while (!q.empty()) {
    Axis cur = q.front();
    q.pop();

    for (Axis &d : dirs) {
      Axis next = {cur.y + d.y, cur.x + d.x};

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
        continue;
      if (visited[next.y][next.x]) continue;
      visited[next.y][next.x] = true;

      if (board[cur.y][cur.x] == '0' && board[next.y][next.x] != '0') {
        int converted = next.y * 100 + next.x;

        um[board[next.y][next.x]].insert(converted);
      }

      if (board[next.y][next.x] == '0') q.push(next);
    }
  }

  return um;
}

int solution(vector<string> storage, vector<string> requests) {
  vector<vector<char>> board = getBoard(storage);
  int rows = board.size(), cols = board[0].size();

  unordered_map<char, unordered_set<int>> alls;
  unordered_map<char, unordered_set<int>> edges = getEdges(board);

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (board[y][x] == '0') continue;

      char key = board[y][x];

      alls[key].insert(y * 100 + x);
    }
  }

  for (string &r : requests) {
    char key = r[0];

    if (r.size() == 1) {
      for (int e : edges[key]) {
        int y = e / 100, x = e % 100;

        board[y][x] = '0';
      }
    } else {
      for (int e : alls[key]) {
        int y = e / 100, x = e % 100;

        board[y][x] = '0';
      }
      alls[key].clear();
    }

    edges = getEdges(board);
  }

  int answer = 0;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (board[y][x] == '0') continue;
      answer++;
    }
  }

  return answer;
}