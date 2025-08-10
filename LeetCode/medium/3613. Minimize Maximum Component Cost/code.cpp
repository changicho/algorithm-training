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

// use union find & sort
// time : O(N + M * log(M))
// space : O(N + M)
class Solution {
 public:
  int minCost(int n, vector<vector<int>> &edges, int k) {
    vector<int> parents(n);
    int components = n;
    for (int i = 0; i < n; i++) {
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
      components--;

      parents[b] = a;
    };

    sort(edges.begin(), edges.end(),
         [](vector<int> &a, vector<int> &b) { return a[2] < b[2]; });

    int answer = 0;
    for (vector<int> &e : edges) {
      if (components <= k) break;
      int a = e[0], b = e[1], cost = e[2];

      if (find(a) == find(b)) continue;
      merge(a, b);

      answer = max(answer, cost);
    }

    return answer;
  }
};