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

struct Gem {
  int color, value;
};

ll solution(int size, int k, int m, vector<int>& colors, vector<int>& values) {
  ll answer = 0;

  vector<Gem> arr;
  for (int i = 0; i < size; i++) {
    int c = colors[i], v = values[i];

    arr.push_back({c, v});
  }

  sort(arr.begin(), arr.end(),
       [](Gem& a, Gem& b) { return a.value > b.value; });

  unordered_set<int> used;
  vector<int> remains;
  for (Gem& cur : arr) {
    if (used.count(cur.color) == 0 && m > 0) {
      answer += cur.value;
      k--;
      m--;
      used.insert(cur.color);
    } else {
      remains.push_back(cur.value);
    }
  }

  for (int i = 0; i < k; i++) {
    answer += remains[i];
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, K, M;
  cin >> N >> K >> M;

  vector<int> C(N), V(N);

  for (int i = 0; i < N; i++) {
    cin >> C[i] >> V[i];
  }

  auto answer = solution(N, K, M, C, V);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}