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

// use union find
// time : O(N + E + Q)
// space : O(N + Q)
class Solution {
 private:
  vector<int> parents;

  int find(int node) {
    if (parents[node] == node) return node;
    return parents[node] = find(parents[node]);
  }

  void merge(int a, int b) {
    a = find(a), b = find(b);

    if (a > b) swap(a, b);
    parents[b] = a;
  }

 public:
  vector<int> minimumCost(int n, vector<vector<int>> &edges,
                          vector<vector<int>> &query) {
    parents.resize(n + 1);
    for (int i = 0; i < n; i++) {
      parents[i] = i;
    }

    // all bit mask
    vector<int> costs(n, INT_MAX);
    for (vector<int> &e : edges) {
      int a = e[0], b = e[1], c = e[2];

      merge(a, b);
    }
    for (vector<int> &e : edges) {
      int a = e[0], b = e[1], c = e[2];

      costs[find(a)] &= c;
    }

    vector<int> answer;
    for (vector<int> &q : query) {
      int a = q[0], b = q[1];

      if (find(a) != find(b)) {
        answer.push_back(-1);
      } else {
        answer.push_back(costs[find(a)]);
      }
    }
    return answer;
  }
};