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
using pii = pair<int, int>;

vector<int> solution(int x, int size, vector<pii>& queries) {
  vector<int> answer;

  priority_queue<int> left;
  priority_queue<int, vector<int>, greater<int>> right;
  left.push(x);
  left.push(INT_MIN);
  right.push(INT_MAX);

  for (pii& q : queries) {
    int a = q.first, b = q.second;

    for (int cur : {a, b}) {
      if (cur <= left.top()) {
        left.push(cur);
      } else {
        right.push(cur);
      }
    }

    while (left.size() > right.size() + 1) {
      right.push(left.top());
      left.pop();
    }
    while (right.size() + 1 > left.size()) {
      left.push(right.top());
      right.pop();
    }

    answer.push_back(left.top());
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int X;
  cin >> X;

  int Q;
  cin >> Q;

  vector<pii> queries(Q);
  for (int i = 0; i < Q; i++) {
    cin >> queries[i].first >> queries[i].second;
  }

  auto answer = solution(X, Q, queries);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto& line : answer) {
    cout << line << "\n";
  }
  // cout << endl;

  return 0;
}