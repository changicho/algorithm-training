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

const int MOD = 1e9 + 7;

long long solution(int size) {
  int dp[101] = {
      0,
  };
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 3;

  for (int i = 4; i <= 100; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
    dp[i] %= MOD;
  }

  long long answer = dp[size];
  int mid = (size / 2);
  answer -= dp[mid];
  if (size % 2 == 0 && mid - 1 >= 0) {
    answer -= dp[mid - 1];
  }

  while (answer < 0) {
    answer += MOD;
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./input.txt", "r", stdin);

  int C;
  cin >> C;

  for (int testCase = 1; testCase <= C; testCase++) {
    int N;
    cin >> N;

    long long answer = solution(N);

    cout << answer << "\n";
  }

  return 0;
}
