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

using pii = pair<int, int>;
using ll = long long;

auto solution(int n, int size, vector<pii>& operations) {
  vector<bool> rows(n + 1, false);
  vector<bool> cols(n + 1, false);

  int answer = 0;
  for (int i = size - 1; i >= 0; i--) {
    pii& cur = operations[i];
    int y = cur.first, x = cur.second;

    if (!rows[y] && !cols[x]) answer++;

    rows[y] = cols[x] = true;
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, M;
  cin >> N >> M;

  vector<pii> operations(M);
  for (int i = 0; i < M; i++) {
    cin >> operations[i].first >> operations[i].second;
  }

  auto answer = solution(N, M, operations);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}