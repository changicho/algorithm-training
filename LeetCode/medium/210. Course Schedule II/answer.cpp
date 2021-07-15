#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use topological sort (BFS)

class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    int size = numCourses;
    vector<vector<int>> graph(size);
    vector<int> inDegree(size, 0);
    vector<int> result;

    for (vector<int>& cur : prerequisites) {
      int from = cur[1], to = cur[0];

      graph[from].emplace_back(to);
      inDegree[to] += 1;
    }

    queue<int> q;
    for (int node = 0; node < size; node++) {
      if (inDegree[node] == 0) {
        q.push(node);
      }
    }

    for (int index = 0; index < size; index++) {
      if (q.empty()) break;

      int cur = q.front();
      q.pop();
      result.emplace_back(cur);

      for (int next : graph[cur]) {
        inDegree[next]--;

        if (inDegree[next] == 0) {
          q.push(next);
        }
      }
    }

    if (result.size() == size) return result;
    return {};
  }
};

// use topological sort (DFS)

class Solution {
 public:
  // 0 : white or unvisited, 1 : gray or visiting, 2 : black or visited
  bool recursive(int node, vector<vector<int>>& graph, vector<int>& color, vector<int>& answer) {
    if (color[node] == 1) return false;
    color[node] = 1;

    for (int next : graph[node]) {
      if (color[next] == 0) {
        if (!recursive(next, graph, color, answer))
          return false;
      }

      if (color[next] == 1) return false;
    }

    color[node] = 2;
    answer.emplace_back(node);
    return true;
  }

  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    int size = numCourses;
    int n = prerequisites.size();
    vector<vector<int>> graph(size);
    vector<int> answer;
    vector<int> color(size, 0);

    for (vector<int>& cur : prerequisites) {
      int from = cur[1], to = cur[0];
      graph[to].emplace_back(from);
    }

    for (int node = 0; node < numCourses; ++node) {
      if (color[node] == 0) {
        if (!recursive(node, graph, color, answer)) return {};
      }
    }
    return answer;
  }
};