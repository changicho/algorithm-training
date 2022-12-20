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

int pack(int leftWeight, int index, vector<vector<int>> &dp,
         vector<Stuff> &stuffs) {
  int size = stuffs.size();

  if (index == size + 1) return 0;
  int &res = dp[leftWeight][index];
  if (res != -1) return res;

  res = pack(leftWeight, index + 1, dp, stuffs);

  if (leftWeight >= stuffs[index].weight) {
    int next = pack(leftWeight - stuffs[index].weight, index + 1, dp, stuffs) +
               stuffs[index].value;
    res = max(res, next);
  }
  return res;
}

void reconstruct(int leftWeight, int index, vector<vector<int>> &dp,
                 vector<Stuff> &stuffs, vector<string> &answerStuffs) {
  int size = stuffs.size();
  if (index == size) return;

  if (dp[leftWeight][index] == dp[leftWeight][index + 1]) {
    reconstruct(leftWeight, index + 1, dp, stuffs, answerStuffs);
  } else {
    answerStuffs.push_back(stuffs[index].name);
    reconstruct(leftWeight - stuffs[index].weight, index + 1, dp, stuffs,
                answerStuffs);
  }
}

Data solution(vector<Stuff> &stuffs, int totalWeight) {
  int size = stuffs.size();
  int answer = 0;
  vector<string> answerStuffs;
  vector<vector<int>> dp(totalWeight + 1, vector<int>(size + 1, -1));

  pack(totalWeight, 1, dp, stuffs);
  reconstruct(totalWeight, 1, dp, stuffs, answerStuffs);

  Data ret = {dp[totalWeight][1], answerStuffs};

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

    vector<Stuff> stuffs(N + 1);

    for (int i = 1; i <= N; i++) {
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
