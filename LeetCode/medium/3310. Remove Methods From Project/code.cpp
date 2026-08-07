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

// BFS & inDegree
// time : O(N + M)
// space : O(N + M)
class Solution {
 public:
  vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
    vector<vector<int>> edges(n);
    vector<int> inDegree(n, 0);

    bool visited[100001] = {
        false,
    };

    for (vector<int>& e : invocations) {
      int a = e[0], b = e[1];
      edges[a].push_back(b);
      inDegree[b]++;
    }

    queue<int> q;
    q.push(k);
    visited[k] = true;

    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : edges[u]) {
        inDegree[v]--;

        if (!visited[v]) {
          q.push(v);
          visited[v] = true;
        }
      }
    }

    bool canRemoveAll = true;
    vector<int> answer;

    for (int i = 0; i < n; i++) {
      if (visited[i] && inDegree[i] > 0) {
        canRemoveAll = false;
        break;
      } else if (!visited[i]) {
        answer.push_back(i);
      }
    }

    if (!canRemoveAll) {
      vector<int> allNodes(n);
      iota(allNodes.begin(), allNodes.end(), 0);
      return allNodes;
    }

    return answer;
  }
};