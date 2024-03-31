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

long long solution(string &s, vector<long long> &costs) {
  int size = s.size();

  // 010101
  vector<long long> dp0(size);
  // 101010
  vector<long long> dp1(size);

  dp0[0] = (s[0] == '0') ? 0 : costs[0];
  dp1[0] = (s[0] == '1') ? 0 : costs[0];

  for (int i = 1; i < size; i++) {
    char cur0 = i % 2 == 0 ? '0' : '1';
    char cur1 = i % 2 == 0 ? '1' : '0';

    dp0[i] = dp0[i - 1] + ((s[i] == cur0) ? 0 : costs[i]);
    dp1[i] = dp1[i - 1] + ((s[i] == cur1) ? 0 : costs[i]);
  }

  long long answer = LLONG_MAX;

  for (int i = 0; i < size; i++) {
    long long leftCost = 0, rightCost = 0;

    long long zeroCost = s[i] == '0' ? 0 : costs[i];
    long long oneCost = s[i] == '1' ? 0 : costs[i];

    if (i == 0) {
      // cur 0 case
      answer = min(answer, dp1[size - 1] - dp1[0] + zeroCost);

      // cur 1 case
      answer = min(answer, dp0[size - 1] - dp0[0] + oneCost);

      continue;
    }

    if (i == size - 1) {
      // dp0 : odd 1, even 0
      // dp1 : odd 0, even 1

      // cur 0 case
      answer =
          min(answer, ((i - 1) % 2 == 1 ? dp1[i - 1] : dp0[i - 1]) + zeroCost);

      // cur 1 case
      answer =
          min(answer, ((i - 1) % 2 == 1 ? dp0[i - 1] : dp1[i - 1]) + oneCost);
      continue;
    }

    // left 0 case
    leftCost = 0;
    rightCost = 0;
    if (i > 0) {
      leftCost = dp0[i - 1];
    }
    if (i < size - 1) {
      rightCost = dp1[size - 1] - dp1[i];
    }
    answer = min(answer, leftCost + rightCost);

    // left 1 case
    leftCost = 0;
    rightCost = 0;
    if (i > 0) {
      leftCost = dp1[i - 1];
    }
    if (i < size - 1) {
      rightCost = dp0[size - 1] - dp0[i];
    }
    answer = min(answer, leftCost + rightCost);
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

  string S;
  cin >> S;

  vector<long long> C(N);
  for (int i = 0; i < N; i++) {
    cin >> C[i];
  }

  long long answer = solution(S, C);

  cout << answer << endl;

  return 0;
}