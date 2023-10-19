#include <algorithm>
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

int solution(vector<int> &arr) {
  int size = arr.size();

  int answer = arr.size();

  // until [i] minimum cost to make beautiful
  vector<int> dp(size);

  for (int i = 0; i < size; i++) {
    dp[i] = i + 1;
  }

  for (int i = 0; i < size; i++) {
    if (i - 1 >= 0) {
      dp[i] = min(dp[i], dp[i - 1] + 1);
    }
    int cur = arr[i];

    int beforeCost = i - 1 < 0 ? 0 : dp[i - 1];

    if (i + cur < size) {
      dp[i + cur] = min(dp[i + cur], beforeCost);
    }
  }

  return dp[size - 1];
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
      cin >> arr[i];
    }

    int answer = solution(arr);

    cout << answer << "\n";
  }

  return 0;
}