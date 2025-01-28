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

// use BFS
// time : O(Q * (V + E))
// space : O(V + E)
class Solution {
 private:
  bool check(int from, int to, vector<vector<int>>& graph) {
    unordered_set<int> visited;
    visited.insert(from);

    queue<int> q;
    q.push(from);

    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      if (cur == to) return true;

      for (int& next : graph[cur]) {
        if (visited.count(next)) continue;
        visited.insert(next);
        q.push(next);
      }
    }
    return false;
  }

 public:
  vector<bool> checkIfPrerequisite(int numCourses,
                                   vector<vector<int>>& prerequisites,
                                   vector<vector<int>>& queries) {
    vector<vector<int>> graph(numCourses);

    for (vector<int>& edge : prerequisites) {
      int from = edge[0], to = edge[1];

      graph[from].push_back(to);
    }

    vector<bool> answer;
    for (vector<int>& q : queries) {
      int from = q[0], to = q[1];

      answer.push_back(check(from, to, graph));
    }
    return answer;
  }
};

// use floyd warshall
// time : O(V^3 + E + Q)
// space : O(V^2)
class Solution {
 public:
  vector<bool> checkIfPrerequisite(int numCourses,
                                   vector<vector<int>>& prerequisites,
                                   vector<vector<int>>& queries) {
    vector<vector<int>> costs(numCourses, vector<int>(numCourses, 1));
    for (int i = 0; i < numCourses; i++) {
      costs[i][i] = 0;
    }
    for (vector<int>& edge : prerequisites) {
      int from = edge[0], to = edge[1];

      costs[from][to] = 0;
    }

    for (int through = 0; through < numCourses; through++) {
      for (int from = 0; from < numCourses; from++) {
        for (int to = 0; to < numCourses; to++) {
          costs[from][to] =
              min(costs[from][to], costs[from][through] + costs[through][to]);
        }
      }
    }

    vector<bool> answer;
    for (vector<int>& q : queries) {
      int from = q[0], to = q[1];

      answer.push_back(costs[from][to] == 0);
    }
    return answer;
  }
};