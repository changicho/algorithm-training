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

auto solution(int size, string &s) {
  int oneCount = 0;

  // [even,odd length][one count odd even]
  long long dp[2][2] = {0};
  dp[0][0] = 1;

  long long answer = 0;

  for (int i = 0; i < size; i++) {
    int length = i + 1;

    if (s[i] == '1') {
      oneCount++;
    }

    if (length % 2 == 0) {
      if (oneCount % 2 == 0) {
        // length even, oneCount even
        answer += dp[0][0];
        answer += dp[1][1];
      } else {
        // length even, oneCount odd
        answer += dp[0][1];
        answer += dp[1][0];
      }
    } else {
      if (oneCount % 2 == 0) {
        // length odd, oneCount even
        answer += dp[1][0];
        answer += dp[0][1];
      } else {
        // length odd, oneCount odd
        answer += dp[1][1];
        answer += dp[0][0];
      }
    }

    dp[length % 2][oneCount % 2]++;
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

  string T;
  cin >> T;

  auto answer = solution(N, T);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}