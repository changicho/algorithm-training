#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use union find

class Solution {
 private:
  vector<int> parents;
  int find(int node) {
    if (parents[node] == node) return node;

    return parents[node] = find(parents[node]);
  }

  void merge(int a, int b) {
    int parentA = find(a), parentB = find(b);

    if (parentA > parentB) swap(parentA, parentB);
    parents[parentB] = parentA;
  }

 public:
  int countComponents(int n, vector<vector<int>>& edges) {
    parents.resize(n);
    for (int i = 0; i < n; i++) {
      parents[i] = i;
    }

    for (vector<int>& edge : edges) {
      merge(edge[0], edge[1]);
    }

    unordered_set<int> us;
    for (int parent : parents) {
      int target = find(parent);
      us.insert(target);
    }

    return us.size();
  }
};

// use BFS

class Solution {
 public:
  int countComponents(int n, vector<vector<int>>& edges) {
    vector<bool> visited(n, false);

    vector<vector<int>> graph(n);
    for (vector<int>& edge : edges) {
      int from = edge[0], to = edge[1];

      graph[from].emplace_back(to);
      graph[to].emplace_back(from);
    }

    int answer = 0;
    for (int node = 0; node < n; node++) {
      if (visited[node]) continue;
      answer += 1;

      queue<int> q;
      q.push(node);
      while (!q.empty()) {
        int cur = q.front();
        q.pop();

        visited[cur] = true;

        for (int& next : graph[cur]) {
          if (visited[next]) continue;
          q.push(next);
        }
      }
    }

    return answer;
  }
};