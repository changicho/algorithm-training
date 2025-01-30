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

// use disjoint set
// time : O(V + E * a(V))
// space : O(V)
class Solution {
 private:
 public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int size = edges.size();
    vector<int> parents(size + 1);
    for (int i = 1; i <= size; i++) {
      parents[i] = i;
    }

    function<int(int)> find = [&](int node) {
      if (parents[node] == node) return node;
      return parents[node] = find(parents[node]);
    };

    function<void(int, int)> merge = [&](int a, int b) {
      a = find(a), b = find(b);

      if (a == b) return;
      if (a > b) swap(a, b);
      parents[b] = a;
    };

    for (vector<int>& e : edges) {
      int a = e[0], b = e[1];

      if (find(a) == find(b)) return e;
      merge(a, b);
    }
    return {};
  }
};