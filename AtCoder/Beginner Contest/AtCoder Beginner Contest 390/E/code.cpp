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

struct Food {
  int v, a, c;
};

int solution(int size, int limit, vector<Food> &foods) {
  vector<vector<int>> dp(3, vector<int>(limit + 1, 0));

  for (int i = 0; i < size; i++) {
    Food cur = foods[i];

    int type = cur.v - 1;
    for (int next = limit; next >= cur.c; next--) {
      int prev = next - cur.c;

      dp[type][next] = max(dp[type][next], dp[type][prev] + cur.a);
    }
  }

  int answer = 0;
  for (int first = 0; first < limit; first++) {
    for (int second = 0; first + second < limit; second++) {
      int third = limit - first - second;

      answer = max(answer, min({dp[0][first], dp[1][second], dp[2][third]}));
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

  int N, X;
  cin >> N >> X;

  vector<Food> foods(N);
  for (int i = 0; i < N; i++) {
    cin >> foods[i].v >> foods[i].a >> foods[i].c;
  }

  int answer = solution(N, X, foods);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}