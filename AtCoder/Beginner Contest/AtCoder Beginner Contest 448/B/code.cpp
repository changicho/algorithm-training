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

auto solution(int size, int cSize, vector<int>& c, vector<pair<int, int>>& ab) {
  int answer = 0;

  for (pair<int, int>& p : ab) {
    int a = p.first;
    int b = p.second;

    answer += min(c[a - 1], b);
    c[a - 1] -= min(c[a - 1], b);
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

  vector<int> C(M);
  for (int i = 0; i < M; i++) {
    cin >> C[i];
  }

  vector<pair<int, int>> AB(N);
  for (int i = 0; i < N; i++) {
    cin >> AB[i].first >> AB[i].second;
  }

  auto answer = solution(N, M, C, AB);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}