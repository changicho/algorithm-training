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

vector<int> solution(int n, int m, vector<pair<int, int>>& ab) {
  vector<int> answer;

  vector<int> first(m);
  vector<int> second(m);
  for (int i = 0; i < n; i++) {
    first[ab[i].first - 1]++;
    second[ab[i].second - 1]++;
  }

  for (int i = 0; i < m; i++) {
    answer.push_back(second[i] - first[i]);
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

  vector<pair<int, int>> AB(N);
  for (int i = 0; i < N; i++) {
    cin >> AB[i].first >> AB[i].second;
  }

  auto answer = solution(N, M, AB);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto& line : answer) {
    cout << line << "\n";
  }
  cout << endl;

  return 0;
}