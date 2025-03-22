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

// use dynamic programming
// time : O(L * N * M)
// space : O(N * M)
int solution(vector<vector<int>> info, int n, int m) {
  int size = info.size();

  bool dp[121][121] = {
      false,
  };

  dp[0][0] = true;
  for (int i = 1; i <= size; i++) {
    bool curDp[121][121] = {
        false,
    };
    int aCost = info[i - 1][0], bCost = info[i - 1][1];

    for (int a = 0; a < n; a++) {
      for (int b = 0; b < m; b++) {
        if (!dp[a][b]) continue;

        if (a + aCost < n) {
          curDp[a + aCost][b] = true;
        }
        if (b + bCost < m) {
          curDp[a][b + bCost] = true;
        }
      }
    }

    swap(dp, curDp);
  }

  for (int a = 0; a < n; a++) {
    for (int b = 0; b < m; b++) {
      if (dp[a][b]) return a;
    }
  }

  return -1;
}