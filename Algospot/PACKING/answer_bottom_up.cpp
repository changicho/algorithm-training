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

struct Stuff {
  string name;
  int weight;
  int value;
};

struct Data {
  int totalValue;
  vector<string> stuffs;
};

Data solution(vector<Stuff> &stuffs, int totalWeight) {
  int size = stuffs.size();

  vector<vector<int>> dp(size + 1, vector<int>(totalWeight + 1, 0));

  for (int i = 1; i <= size; i++) {
    for (int w = 1; w <= totalWeight; w++) {
      Stuff stuff = stuffs[i - 1];

      if (w - stuff.weight >= 0) {
        int nextValue = dp[i - 1][w - stuff.weight] + stuff.value;
        dp[i][w] = max(dp[i - 1][w], nextValue);
        continue;
      }
      dp[i][w] = dp[i - 1][w];
    }
  }

  // reconstruct
  vector<string> answerStuffs;
  for (int i = size, w = totalWeight; i >= 1 && w >= 1; i--) {
    if (dp[i][w] == dp[i - 1][w]) continue;
    answerStuffs.push_back(stuffs[i - 1].name);

    w -= stuffs[i - 1].weight;
  }

  Data ret = {dp.back().back(), answerStuffs};
  return ret;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // // decimal point
  // cout << fixed;
  // cout.precision(8);

  freopen("./input.txt", "r", stdin);

  int C;
  cin >> C;

  for (int testCase = 1; testCase <= C; testCase++) {
    int N, W;
    cin >> N >> W;

    vector<Stuff> stuffs(N);

    for (int i = 0; i < N; i++) {
      cin >> stuffs[i].name >> stuffs[i].weight >> stuffs[i].value;
    }

    Data answer = solution(stuffs, W);

    cout << answer.totalValue << " " << answer.stuffs.size() << "\n";
    for (string &name : answer.stuffs) {
      cout << name << "\n";
    }
  }

  return 0;
}
