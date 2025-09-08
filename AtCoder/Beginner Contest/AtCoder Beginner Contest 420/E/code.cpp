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

vector<bool> solution(int n, int qSize, vector<vector<int>> &queries) {
  vector<int> parents(n + 1, -1);

  // 0 : white, 1 : black
  vector<int> colors(n + 1, 0);
  vector<int> blackCounts(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    parents[i] = i;
  }

  function<int(int)> find = [&](int node) {
    if (parents[node] == node) return node;

    return parents[node] = find(parents[node]);
  };

  function<void(int, int)> merge = [&](int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return;

    if (a > b) swap(a, b);
    parents[b] = a;
  };

  vector<bool> answer;

  for (vector<int> &query : queries) {
    int type = query[0];

    if (type == 1) {
      int a = query[1];
      int b = query[2];

      a = find(a);
      b = find(b);

      if (a == b) continue;

      merge(a, b);
      int newParent = find(a);

      blackCounts[newParent] = blackCounts[a] + blackCounts[b];
    } else if (type == 2) {
      int node = query[1];
      int parent = find(node);

      blackCounts[parent] -= colors[node];
      // toggle color
      colors[node] = 1 - colors[node];
      // colors[node] ^= 1;
      // colors[node] = colors[node] == 1 ? 0 : 1;
      blackCounts[parent] += colors[node];
    } else if (type == 3) {
      int node = query[1];
      int parent = find(node);

      answer.push_back(blackCounts[parent] > 0);
    }
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, Q;
  cin >> N >> Q;

  vector<vector<int>> queries(Q);

  for (int i = 0; i < Q; i++) {
    int T, X, Y;
    cin >> T;
    if (T == 1) {
      cin >> X >> Y;

      queries[i] = {T, X, Y};
    } else {
      cin >> X;

      queries[i] = {T, X};
    }
  }

  vector<bool> answer = solution(N, Q, queries);

  // cout << answer << endl;
  for (bool line : answer) {
    cout << (line ? "Yes" : "No") << endl;
    // cout << line << "\n";
  }
  // cout << endl;

  return 0;
}