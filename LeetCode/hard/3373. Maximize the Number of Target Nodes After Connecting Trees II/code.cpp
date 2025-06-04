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

// use DFS
// time : O(V + E)
// space : O(V + E)
class Solution {
 public:
  int recursive(int node, int parent, int depth, vector<vector<int>>& graph,
                vector<int>& color) {
    int redCount = 1 - depth % 2;
    color[node] = depth % 2;

    for (int& next : graph[node]) {
      if (next == parent) continue;

      redCount += recursive(next, node, depth + 1, graph, color);
    }
    return redCount;
  };

  // {red, black}
  vector<int> build(int size, vector<vector<int>>& edges, vector<int>& color) {
    vector<vector<int>> graph(size);
    for (vector<int>& e : edges) {
      int a = e[0], b = e[1];

      graph[a].push_back(b);
      graph[b].push_back(a);
    }

    int res = recursive(0, -1, 0, graph, color);
    return {res, size - res};
  }

  vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                             vector<vector<int>>& edges2) {
    int size1 = edges1.size() + 1, size2 = edges2.size() + 1;

    vector<int> color1(size1);
    vector<int> color2(size2);
    vector<int> count1 = build(size1, edges1, color1);
    vector<int> count2 = build(size2, edges2, color2);

    vector<int> res(size1);

    for (int i = 0; i < size1; i++) {
      res[i] = count1[color1[i]] + max(count2[0], count2[1]);
    }
    return res;
  }
};