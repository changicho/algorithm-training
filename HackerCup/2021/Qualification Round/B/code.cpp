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

// time : 30min
pair<int, int> solution(int size, vector<string>& board) {
  vector<bool> flagRows(size, true), flagCols(size, true);

  for (int y = 0; y < size; y++) {
    for (int x = 0; x < size; x++) {
      if (board[y][x] == 'O') {
        flagCols[x] = false;
        flagRows[y] = false;
      }
    }
  }

  set<vector<pair<int, int>>> answerCase[size + 1];
  for (int y = 0; y < size; y++) {
    if (!flagRows[y]) continue;

    vector<pair<int, int>> axises;
    for (int x = 0; x < size; x++) {
      if (board[y][x] == '.') {
        axises.push_back({y, x});
      }
    }
    if (axises.size() == 0) continue;
    sort(axises.begin(), axises.end());
    answerCase[axises.size()].insert(axises);
  }
  for (int x = 0; x < size; x++) {
    if (!flagCols[x]) continue;

    vector<pair<int, int>> axises;
    for (int y = 0; y < size; y++) {
      if (board[y][x] == '.') {
        axises.push_back({y, x});
      }
    }
    if (axises.size() == 0) continue;
    sort(axises.begin(), axises.end());
    answerCase[axises.size()].insert(axises);
  }

  for (int i = 0; i <= size; i++) {
    if (answerCase[i].size() > 0) {
      return {i, answerCase[i].size()};
    }
  }

  return {0, 0};
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    int N;
    cin >> N;
    vector<string> board(N);
    for (int y = 0; y < N; y++) {
      cin >> board[y];
    }

    pair<int, int> answer = solution(N, board);

    cout << "Case #" << testCase << ": ";
    if (answer.first == 0) {
      cout << "Impossible";
    } else {
      cout << answer.first << " " << answer.second;
    }
    cout << "\n";
  }

  return 0;
}