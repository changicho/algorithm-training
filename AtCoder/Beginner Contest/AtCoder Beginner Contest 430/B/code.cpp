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

auto solution(int size, int m, vector<string>& board) {
  unordered_set<string> patterns;

  for (int y = 0; y <= size - m; y++) {
    for (int x = 0; x <= size - m; x++) {
      string pattern = "";

      for (int yy = y; yy < y + m; yy++) {
        pattern += board[yy].substr(x, m);
        pattern += "$";
      }

      patterns.insert(pattern);
    }
  }

  return patterns.size();
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, M;
  cin >> N >> M;

  vector<string> board(N);
  for (int i = 0; i < N; i++) {
    cin >> board[i];
  }

  auto answer = solution(N, M, board);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}