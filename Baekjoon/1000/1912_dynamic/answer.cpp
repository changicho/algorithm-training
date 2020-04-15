#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dp[100001];

void solution() {
  int N, answer;
  cin >> N;

  vector<int> arr(N);

  cin >> arr[0];
  dp[0] = arr[0];
  answer = arr[0];

  for (int i = 1; i < N; i++) {
    cin >> arr[i];

    dp[i] = max(dp[i - 1] + arr[i], arr[i]);
    answer = max(answer, dp[i]);
  }

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}