#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

using ll = long long;
using pll = pair<ll, ll>;

bool check(int size, vector<pll>& cards) {
  vector<ll> diffs(size);
  vector<int> starts(size, 0);
  diffs[0] = cards[0].second - cards[0].first;

  for (int i = 1; i < size; i++) {
    ll diff = cards[i].second - cards[i].first;

    if (diffs[i - 1] < 0) {
      starts[i] = i;
      diffs[i] = diff;
    } else {
      starts[i] = starts[i - 1];
      diffs[i] = diffs[i - 1] + diff;
    }
  }

  long long beforeDiffSum = 0;
  int targetL = 0, targetR = -1;

  for (int i = 0; i < size; i++) {
    if (diffs[i] > beforeDiffSum) {
      beforeDiffSum = diffs[i];
      targetL = starts[i];
      targetR = i;
    }
  }

  if (targetR != -1) {
    for (int i = targetL; i <= targetR; i++) {
      swap(cards[i].first, cards[i].second);
    }

    return true;
  }
  return false;
}

ll solution(int size, vector<pll>& cards, int k) {
  ll answer = 0;

  for (pll& c : cards) {
    answer += c.first;
  }

  for (int i = 0; i < k; i++) {
    if (!check(size, cards)) break;

    ll newAnswer = 0;
    for (pll& c : cards) {
      newAnswer += c.first;
    }
    answer = newAnswer;
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, K;
  cin >> N >> K;

  vector<pll> cards(N);
  for (int i = 0; i < N; i++) {
    cin >> cards[i].first >> cards[i].second;
  }

  auto answer = solution(N, cards, K);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}