#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use subtree sum and count
// time : O(N)
// space : O(N)
class Solution {
 private:
  vector<int> ans, count;
  vector<vector<int>> graph;
  int size;

  void dfs(int node, int parent) {
    for (int &child : graph[node])
      if (child != parent) {
        dfs(child, node);
        count[node] += count[child];
        ans[node] += ans[child] + count[child];
      }
  }

  void dfs2(int node, int parent) {
    for (int &child : graph[node])
      if (child != parent) {
        ans[child] = ans[node] - count[child] + size - count[child];
        dfs2(child, node);
      }
  }

 public:
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
    this->size = n;
    graph.resize(n);
    ans.resize(n, 0);
    count.resize(n, 1);

    for (vector<int> &edge : edges) {
      int a = edge.front(), b = edge.back();
      graph[a].push_back(b);
      graph[b].push_back(a);
    }

    dfs(0, -1);
    dfs2(0, -1);
    return ans;
  }
};

// use subtree sum and count
// time : O(N)
// space : O(N)
class Solution {
 private:
  vector<int> answer;
  vector<int> childrenCounts;
  vector<vector<int>> graph;
  int size;
  int distancesFromRoot = 0;

  void preProcess(int node, int parent, int depth) {
    for (int &child : graph[node]) {
      if (child == parent) continue;

      preProcess(child, node, depth + 1);
      childrenCounts[node] += childrenCounts[child];
    }
    distancesFromRoot += depth;
  }

  void recursive(int node, int parent, int curCost) {
    answer[node] = curCost;

    for (int &child : graph[node]) {
      if (child == parent) continue;

      int curPartSum = childrenCounts[child];
      int otherPartSum = size - childrenCounts[child];

      int nextCost = curCost - curPartSum + otherPartSum;

      recursive(child, node, nextCost);
    }
  }

 public:
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
    this->size = n;
    graph.resize(n);
    answer.resize(n, 0);
    childrenCounts.resize(n, 1);

    for (vector<int> &edge : edges) {
      int a = edge.front(), b = edge.back();
      graph[a].push_back(b);
      graph[b].push_back(a);
    }

    preProcess(0, -1, 0);
    recursive(0, -1, distancesFromRoot);

    return answer;
  }
};