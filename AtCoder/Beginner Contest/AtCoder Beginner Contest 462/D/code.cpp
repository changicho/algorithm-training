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

ll solution(int size, int d, vector<pair<int, int>>& times) {
  const int LIMIT = 1e6 + 1;
  ll answer = 0;

  sort(times.begin(), times.end());
  int i = 0;

  priority_queue<int, vector<int>, greater<int>> pq;
  for (int t = 0; t + d <= LIMIT; t++) {
    while (i < size && times[i].first == t) {
      pq.push(times[i].second);
      i++;
    }

    while (!pq.empty() && pq.top() < t + d) {
      pq.pop();
    }

    int c = pq.size();
    answer += ll(c) * (c - 1) / 2;

    if (i == size && pq.empty()) break;
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, D;
  cin >> N >> D;

  vector<pair<int, int>> times(N);
  for (int i = 0; i < N; i++) {
    cin >> times[i].first >> times[i].second;
  }

  ll answer = solution(N, D, times);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}