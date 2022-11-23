#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N * sqrt(N))
// space : O(N)
class Solution {
 public:
  int numSquares(int n) {
    vector<int> perfectSquares;

    for (int i = 1; i * i <= n; i++) {
      perfectSquares.push_back(i * i);
    }

    vector<long> dp(n + 1, INT_MAX);
    for (int& sq : perfectSquares) {
      dp[sq] = 1;
    }

    for (int i = 1; i <= n; i++) {
      long cur = dp[i - 1] + 1;

      for (int& sq : perfectSquares) {
        if (i - sq < 0) break;
        cur = min(cur, dp[i - sq] + 1);
      }

      dp[i] = min(dp[i], cur);
    }

    return dp[n];
  }
};

// use static dynamic programming
// time : O(N * sqrt(N))
// space : O(N)
class Solution {
 public:
  int numSquares(int n) {
    static vector<int> dp(1, 0);

    while (dp.size() <= n) {
      int cur = dp.size();
      int value = cur;

      for (int part = 1; part * part <= cur; ++part) {
        value = min(value, dp[cur - part * part] + 1);
      }

      dp.emplace_back(value);
    }

    return dp[n];
  }
};

// use BFS
// time : O(N * sqrt(N))
// space : O(N)
class Solution {
 public:
  int numSquares(int n) {
    vector<int> squares;
    vector<int> dp(n + 1, 0);

    // init
    for (int cur = 1; cur * cur <= n; cur++) {
      squares.push_back(cur * cur);
      dp[cur * cur] = 1;
    }

    if (squares.back() == n) {
      return 1;
    }

    queue<int> q;
    for (int& i : squares) {
      q.push(i);
    }

    int step = 1;
    int answer = -1;
    while (!q.empty() && answer == -1) {
      step++;

      int size = q.size();

      while (answer == -1 && size--) {
        int cur = q.front();

        for (int& part : squares) {
          if (cur + part == n) {
            answer = step;
            break;
          }

          if (cur + part > n) {
            break;
          }

          if (dp[cur + part] == 0) {
            dp[cur + part] = step;

            q.push(cur + part);
          }
        }

        q.pop();
      }
    }

    return answer;
  }
};