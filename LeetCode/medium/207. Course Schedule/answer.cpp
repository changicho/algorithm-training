#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use topological sort (BFS)

class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    int size = numCourses;
    vector<vector<int>> graph(size);
    vector<int> inDegrees(size, 0);
    vector<int> path;

    for (vector<int>& prerequisite : prerequisites) {
      int from = prerequisite[1], to = prerequisite[0];

      graph[from].emplace_back(to);
      inDegrees[to] += 1;
    }

    queue<int> q;
    for (int node = 0; node < size; node++) {
      if (inDegrees[node] == 0) q.push(node);
    }

    for (int index = 0; index < size; index++) {
      if (q.empty()) return false;
      int node = q.front();
      q.pop();

      path.emplace_back(node);
      for (int next : graph[node]) {
        inDegrees[next] -= 1;
        if (inDegrees[next] == 0) q.push(next);
      }
    }

    return true;
  }
};

// use topological sort (DFS)

class Solution {
 public:
  // w : unvisited, g : visiting, b : visited
  bool recursive(int node, vector<vector<int>>& graph, vector<char>& color, vector<int>& answer) {
    if (color[node] == 'g') return false;
    color[node] = 'g';

    for (int next : graph[node]) {
      if (color[next] == 'w') {
        if (!recursive(next, graph, color, answer))
          return false;
      }

      if (color[next] == 'g') return false;
    }

    color[node] = 'b';
    answer.emplace_back(node);
    return true;
  }

  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    int size = numCourses;
    vector<vector<int>> graph(size);
    vector<int> answer;
    vector<char> color(size, 'w');

    for (vector<int>& cur : prerequisites) {
      int from = cur[1], to = cur[0];
      graph[to].emplace_back(from);
    }

    for (int node = 0; node < numCourses; ++node) {
      if (color[node] == 'w') {
        bool isFine = recursive(node, graph, color, answer);

        if (!isFine) return false;
      }
    }
    return true;
  }
};