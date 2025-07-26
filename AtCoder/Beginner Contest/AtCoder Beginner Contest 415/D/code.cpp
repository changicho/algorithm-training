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

struct Action {
  long long give;
  long long receive;
};

long long solution(long long n, int actionSize, vector<Action> &actions) {
  long long answer = 0;

  sort(actions.begin(), actions.end(), [](const Action &a, const Action &b) {
    if (a.give == b.give) {
      return a.receive > b.receive;
    }
    return a.give < b.give;
  });

  vector<int> optimalGive(actionSize);
  optimalGive[0] = 0;
  for (int i = 1; i < actionSize; i++) {
    long long diff = actions[i].give - actions[i].receive;
    long long beforeDiff =
        actions[optimalGive[i - 1]].give - actions[optimalGive[i - 1]].receive;

    if (diff < beforeDiff) {
      optimalGive[i] = i;
    } else {
      optimalGive[i] = optimalGive[i - 1];
    }
  }

  for (int targetIndex = actionSize - 1; targetIndex >= 0; targetIndex--) {
    if (actions[targetIndex].give > n) {
      continue;
    }

    int choose = optimalGive[targetIndex];
    long long targetGive = actions[choose].give;
    long long targetReceive = actions[choose].receive;

    long long diff = targetGive - targetReceive;

    long long count = 1 + (n - targetGive) / diff;
    answer += count;

    n -= count * diff;
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);
  long long N;
  int M;
  cin >> N >> M;

  vector<Action> actions(M);

  for (int i = 0; i < M; i++) {
    cin >> actions[i].give >> actions[i].receive;
  }

  long long answer = solution(N, M, actions);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}