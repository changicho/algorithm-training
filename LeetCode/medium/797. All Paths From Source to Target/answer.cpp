#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use DFS with backtracking

class Solution {
 private:
  void recursive(int node, vector<int> &path, vector<bool> &visited,
                 vector<vector<int>> &graph, vector<vector<int>> &answer) {
    int size = visited.size();

    path.push_back(node);

    if (visited[node]) return;
    visited[node] = true;

    if (node == size - 1) {
      answer.push_back(path);

      path.pop_back();
      visited[node] = false;
      return;
    }

    for (int next : graph[node]) {
      if (visited[next]) continue;

      recursive(next, path, visited, graph, answer);
    }

    visited[node] = false;
    path.pop_back();
  }

 public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    int size = graph.size();

    vector<vector<int>> answer;
    vector<bool> visited(size, false);
    vector<int> path;

    recursive(0, path, visited, graph, answer);

    return answer;
  }
};

// use BFS

class Solution {
 private:
  struct Status {
    int node;
    vector<int> path;
  };

 public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    vector<vector<int>> answer;

    queue<Status> q;

    int size = graph.size();
    int from = 0, to = size - 1;
    q.push({from, {from}});

    while (!q.empty()) {
      Status cur = q.front();
      q.pop();

      if (cur.node == to) {
        answer.emplace_back(cur.path);
        continue;
      }

      for (int next : graph[cur.node]) {
        cur.path.emplace_back(next);
        q.push({next, cur.path});
        cur.path.pop_back();
      }
    }

    return answer;
  }
};

// use DFS with explain

class Solution {
 private:
  // void DFS(graph, node, path, answer)
  void DFS(vector<vector<int>> &graph, int node, vector<int> &path,
           vector<vector<int>> &answer) {
    // if node is goal
    if (node == graph.size() - 1) {
      // push path to answer
      answer.push_back(path);
      // return
      return;
    }
    // iterate graph[node]
    for (int &next : graph[node]) {
      // we use next node
      // insert next node to path
      path.push_back(next);
      // call DFS function
      DFS(graph, next, path, answer);
      // DFS
      // pop last node of path
      path.pop_back();
    }

    // return
  }

 public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    vector<vector<int>> answer;
    vector<int> path = {0};

    DFS(graph, 0, path, answer);

    return answer;
  }
};