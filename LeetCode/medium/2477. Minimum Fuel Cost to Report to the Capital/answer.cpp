#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use DFS
// time : O(N)
// space : O(N)
class Solution {
 private:
  vector<vector<int>> graph;
  vector<bool> visited;

  long long answer = 0;

  int recursive(int node, int seats) {
    visited[node] = true;

    int children = 1;
    for (int &next : graph[node]) {
      if (visited[next]) continue;

      children += recursive(next, seats);
    }

    if (node != 0) {
      answer += ceil((double)children / seats);
    }
    return children;
  }

 public:
  long long minimumFuelCost(vector<vector<int>> &roads, int seats) {
    int size = roads.size();

    graph.resize(size + 1);
    visited.resize(size + 1, false);

    for (vector<int> &r : roads) {
      int a = r[0], b = r[1];

      graph[a].push_back(b);
      graph[b].push_back(a);
    }

    recursive(0, seats);

    return answer;
  }
};