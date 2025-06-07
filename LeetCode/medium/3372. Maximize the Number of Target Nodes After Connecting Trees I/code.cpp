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

// use dfs
// time : O(V * (V + E))
// space : O(V + E)
class Solution {
 private:
  int recursive(int node, int parent, vector<vector<int>>& graph, int k) {
    if (k < 0) {
      return 0;
    }
    int count = 1;
    for (int& next : graph[node]) {
      if (next == parent) {
        continue;
      }
      count += recursive(next, node, graph, k - 1);
    }
    return count;
  }

  vector<int> build(int size, vector<vector<int>>& edges, int k) {
    vector<vector<int>> graph(size);
    for (vector<int>& e : edges) {
      int a = e[0], b = e[1];

      graph[a].push_back(b);
      graph[b].push_back(a);
    }

    vector<int> count(size);
    for (int i = 0; i < size; i++) {
      count[i] = recursive(i, -1, graph, k);
    }
    return count;
  }

 public:
  vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                             vector<vector<int>>& edges2, int k) {
    int size1 = edges1.size() + 1;
    int size2 = edges2.size() + 1;

    vector<int> count1 = build(size1, edges1, k);
    vector<int> count2 = build(size2, edges2, k - 1);

    int maximum2 = *max_element(count2.begin(), count2.end());

    vector<int> answer(size1);

    for (int i = 0; i < size1; i++) {
      answer[i] = count1[i] + maximum2;
    }

    return answer;
  }
};