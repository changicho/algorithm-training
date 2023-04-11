#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// use erase leaf
// time : O(N + E)
// space : O(N + E)
class Solution {
 public:
  int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
    int size = coins.size();

    vector<vector<int>> graph(size);
    for (vector<int>& e : edges) {
      int from = e[0], to = e[1];

      graph[from].push_back(to);
      graph[to].push_back(from);
    }

    vector<int> neighbors(size), steps(size, INT_MAX);
    stack<int> stk;

    // find leaf nodes
    for (int node = 0; node < size; node++) {
      neighbors[node] = graph[node].size();

      if (neighbors[node] == 1) stk.push(node);
    }

    // erase leaf nodes 2 steps
    int remainNode = size;
    while (!stk.empty()) {
      int cur = stk.top();
      stk.pop();

      steps[cur]--;
      if (steps[cur] == 0) continue;
      remainNode--;

      for (int next : graph[cur]) {
        steps[next] =
            min({steps[next], steps[cur], coins[cur] == 1 ? 2 : INT_MAX});

        neighbors[next]--;
        if (neighbors[next] == 1) stk.push(next);
      }
    }

    return 2 * max(0, remainNode - 1);
  }
};