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

// . : white
// # : black
auto solution(int rows, int cols, vector<string> &board) {
  vector<int> bit(rows);
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (board[y][x] == '#') {
        bit[y] |= 1 << x;
      }
    }
  }

  vector<long long> dp(1 << cols, INT_MAX);
  dp[bit[0]] = 0;

  for (int y = 0; y < rows; y++) {
    vector<long long> newDp(1 << cols, INT_MAX);

    for (int before = 0; before < (1 << cols); before++) {
      for (int next = 0; next < (1 << cols); next++) {
        int common = (before & next);

        bool isValid = true;
        for (int x = 0; x < cols - 1; x++) {
          if (((common >> x) & 1) && ((common >> (x + 1) & 1))) {
            isValid = false;
            break;
          }
        }

        if (!isValid && y > 0) continue;
        int changeCount = 0;
        common = next ^ bit[y];

        for (int x = 0; x < cols; x++) {
          if ((common >> x) & 1) {
            changeCount++;
          }
        }
        newDp[next] = min(newDp[next], dp[before] + changeCount);
      }
    }

    swap(dp, newDp);
  }

  return *min_element(dp.begin(), dp.end());
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int tc = 1; tc <= T; tc++) {
    int H, W;
    cin >> H >> W;

    vector<string> board(H);
    for (int i = 0; i < H; i++) {
      cin >> board[i];
    }

    auto answer = solution(H, W, board);

    cout << answer << endl;
    // cout << (answer ? "Yes" : "No") << endl;
    // for (auto &line : answer) {
    //   cout << line << "\n";
    // }
    // cout << endl;
  }

  return 0;
}