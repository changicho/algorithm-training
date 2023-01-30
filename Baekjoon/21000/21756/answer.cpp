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

const int MAX = 1e9 + 1;

long long solution(int n) {
  int answer = 0;

  vector<int> before;
  for (int i = 1; i <= n; i++) {
    before.push_back(i);
  }

  while (before.size() > 1) {
    vector<int> cur;
    for (int i = 1; i < before.size(); i += 2) {
      cur.push_back(before[i]);
    }
    before = cur;
  }

  return before.front();
}

void init() {}

void clear() {}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // // decimal point
  // cout << fixed;
  // cout.precision(8);

  init();

  // freopen("./input.txt", "r", stdin);

  int N;
  cin >> N;

  long long answer = solution(N);

  cout << answer << "\n";

  return 0;
}
