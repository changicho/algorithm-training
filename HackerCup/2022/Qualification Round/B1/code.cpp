#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

vector<vector<char>> solution(int rows, int cols, vector<vector<char>> &board) {
  int treeCount = 0;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (board[y][x] == '^') treeCount++;
    }
  }

  if (treeCount == 0) return board;
  if ((rows < 2 || cols < 2)) {
    return {};
  }

  vector<vector<char>> answer(rows, vector<char>(cols, '^'));

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    int R, C;
    cin >> R >> C;
    vector<vector<char>> board(R, vector<char>(C));

    for (int y = 0; y < R; y++) {
      for (int x = 0; x < C; x++) {
        cin >> board[y][x];
      }
    }

    vector<vector<char>> answer = solution(R, C, board);

    cout << "Case #" << testCase << ": ";

    if (answer.size() == 0) {
      cout << "Impossible\n";
    } else {
      cout << "Possible\n";

      for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
          cout << answer[y][x];
        }
        cout << "\n";
      }
    }
  }

  return 0;
}