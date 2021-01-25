#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Edge {
  int length, from;
};

Edge dp[1000001];

void solution() {
  int N;
  cin >> N;

  for (int i = 2; i <= N; i++) {
    dp[i] = {dp[i - 1].length + 1, i - 1};
    if (i % 2 == 0 && dp[i].length > dp[i / 2].length + 1) {
      dp[i] = {dp[i / 2].length + 1, i / 2};
    }
    if (i % 3 == 0 && dp[i].length > dp[i / 3].length + 1) {
      dp[i] = {dp[i / 3].length + 1, i / 3};
    }
  }

  cout << dp[N].length << "\n";
  int index = N;
  cout << index << " ";
  while (dp[index].from != 0) {
    cout << dp[index].from << " ";
    index = dp[index].from;
  }
  cout << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}