#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

using ll = long long;

ll solution(int rows, int cols, int k, vector<string>& board) {
  ll answer = 0;

  int prefixs[502][502] = {
      0,
  };
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      prefixs[y + 1][x + 1] = prefixs[y + 1][x] + board[y][x] - '0';
    }
  }

  int counts[250001] = {
      0,
  };
  for (int x = 0; x < cols; x++) {
    for (int xx = x; xx < cols; xx++) {
      counts[0] = 1;
      int sum = 0;

      for (int y = 0; y < rows; y++) {
        int curLine = prefixs[y + 1][xx + 1] - prefixs[y + 1][x];

        sum += curLine;

        if (sum - k >= 0) {
          answer += counts[sum - k];
        }

        counts[sum]++;
      }

      memset(counts, 0, sizeof(counts));
    }
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int H, W, K;
  cin >> H >> W >> K;

  vector<string> board(H);
  for (int i = 0; i < H; i++) {
    cin >> board[i];
  }

  auto answer = solution(H, W, K, board);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}