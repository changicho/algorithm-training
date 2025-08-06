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

struct Present {
  int p, a, b;
};

vector<long long> solution(int size, vector<Present> &presents, int qSize,
                           vector<int> &queries) {
  vector<vector<long long>> dp(size, vector<long long>(1000 + 1));

  for (int i = size - 1; i >= 0; i--) {
    Present &present = presents[i];

    for (int score = 0; score <= 1000; score++) {
      if (score <= present.p) {
        int next = score + present.a;

        dp[i][score] = i == size - 1 ? next : dp[i + 1][next];
      } else {
        int next = max(score - present.b, 0);

        dp[i][score] = i == size - 1 ? next : dp[i + 1][next];
      }
    }
  }

  vector<long long> prefixSums(size);
  prefixSums[0] = presents[0].b;
  for (int i = 1; i < size; i++) {
    prefixSums[i] = prefixSums[i - 1] + presents[i].b;
  }

  vector<long long> answer;
  for (int query : queries) {
    if (query > 1000) {
      int idx = lower_bound(prefixSums.begin(), prefixSums.end(), query - 500) -
                prefixSums.begin();

      if (idx >= size - 1) {
        answer.push_back(query - prefixSums[size - 1]);
        continue;
      }

      query -= prefixSums[idx];
      answer.push_back(dp[idx + 1][query]);
    } else {
      answer.push_back(dp[0][query]);
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

  int N;
  cin >> N;

  vector<Present> presents(N);
  for (int i = 0; i < N; i++) {
    cin >> presents[i].p >> presents[i].a >> presents[i].b;
  }

  int Q;
  cin >> Q;

  vector<int> queries(Q);
  for (int i = 0; i < Q; i++) {
    cin >> queries[i];
  }

  auto answer = solution(N, presents, Q, queries);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto &line : answer) {
    cout << line << "\n";
  }
  // cout << endl;

  return 0;
}