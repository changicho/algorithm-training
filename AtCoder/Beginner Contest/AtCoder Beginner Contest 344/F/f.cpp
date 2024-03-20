#include <algorithm>
#include <climits>
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

struct Status {
  long long step, money;
};

long long solution(vector<vector<int>> &powers, vector<vector<int>> &rights,
                   vector<vector<int>> &downs) {
  int size = powers.size();

  vector<vector<Status>> dp(size, vector<Status>(size, {LLONG_MAX, 0}));

  dp[0][0] = {0, 0};

  for (int curY = 0; curY < size; ++curY) {
    for (int curX = 0; curX < size; ++curX) {
      vector<vector<long long>> costs(curY + 1,
                                      vector<long long>(curX + 1, LLONG_MAX));

      costs[curY][curX] = 0;

      for (int y = curY; y >= 0; y--) {
        for (int x = curX; x >= 0; x--) {
          if (y < curY) {
            costs[y][x] = min(costs[y][x], downs[y][x] + costs[y + 1][x]);
          }
          if (x < curX) {
            costs[y][x] = min(costs[y][x], rights[y][x] + costs[y][x + 1]);
          }

          long long stay =
              max(0LL, (long long)ceil((double)(costs[y][x] - dp[y][x].money) /
                                       powers[y][x]));

          int distance = curY - y + curX - x;
          long long step = dp[y][x].step + stay + distance;
          long long money = dp[y][x].money + stay * powers[y][x] - costs[y][x];

          if (step < dp[curY][curX].step ||
              (step == dp[curY][curX].step && money > dp[curY][curX].money)) {
            dp[curY][curX] = {step, money};
          }
        }
      }
    }
  }

  long long answer = dp[size - 1][size - 1].step;

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N;
  cin >> N;

  vector<vector<int>> P(N, vector<int>(N, 0)), R(N, vector<int>(N, 0)),
      D(N, vector<int>(N, 0));

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      cin >> P[y][x];
    }
  }

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N - 1; x++) {
      cin >> R[y][x];
    }
  }

  for (int y = 0; y < N - 1; y++) {
    for (int x = 0; x < N; x++) {
      cin >> D[y][x];
    }
  }

  long long answer = solution(P, R, D);

  cout << answer << endl;

  return 0;
}