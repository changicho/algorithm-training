#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use dynamic programming

class Solution {
 public:
  int numSquares(int n) {
    vector<int> dp(n + 1, 0);

    for (int cur = 1; cur <= n; ++cur) {
      dp[cur] = cur;

      for (int part = 1; part * part <= cur; ++part) {
        dp[cur] = min(dp[cur], dp[cur - part * part] + 1);
      }
    }

    return dp[n];
  }
};

// use static dynamic programming

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