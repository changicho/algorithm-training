#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// remove leafs
// time : O(E + V)
// space : O(E + V)
class Solution {
 public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) return {0};

    vector<unordered_set<int>> graph(n);

    for (vector<int>& e : edges) {
      int a = e[0], b = e[1];
      graph[a].insert(b);
      graph[b].insert(a);
    }

    vector<int> leaves;

    for (int node = 0; node < n; node++) {
      if (graph[node].size() == 1) {
        leaves.push_back(node);
      }
    }

    while (n > 2) {
      vector<int> newLeaves;

      n -= leaves.size();

      for (int leaf : leaves) {
        int next = *graph[leaf].begin();
        graph[next].erase(leaf);

        if (graph[next].size() == 1) {
          newLeaves.push_back(next);
        }
      }

      leaves = newLeaves;
    }

    return leaves;
  }
};

// use topology sort
// time : O(E + V)
// space : O(E + V)
class Solution {
 public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) {
      return {0};
    }
    vector<vector<int>> graph(n);
    vector<int> inDegrees(n);

    for (vector<int>& e : edges) {
      int a = e[0], b = e[1];
      graph[a].push_back(b);
      graph[b].push_back(a);

      inDegrees[a]++;
      inDegrees[b]++;
    }

    queue<int> q;
    queue<int> temp;
    for (int node = 0; node < n; node++) {
      if (inDegrees[node] == 1) {
        q.push(node);
        inDegrees[node] = 0;
      }
    }

    int step = 0;
    vector<int> answer;
    while (!q.empty()) {
      int size = q.size();
      temp = q;

      while (size--) {
        int cur = q.front();
        q.pop();

        for (int& next : graph[cur]) {
          inDegrees[next]--;

          if (inDegrees[next] == 1) {
            q.push(next);
          }
        }
      }
    }

    while (!temp.empty()) {
      answer.push_back(temp.front());
      temp.pop();
    }

    return answer;
  }
};