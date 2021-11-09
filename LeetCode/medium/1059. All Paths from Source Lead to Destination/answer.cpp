#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use DFS with color

class Solution {
 private:
  enum Color {
    WHITE,  // never visited
    GRAY,   // there are white neighber
    BLACK   // there are no white neighber
  };
  vector<Color> colors;
  vector<vector<int>> graph;

  bool isAcyclic(int from, int to) {
    if (colors[from] == Color::BLACK) return true;
    if (colors[from] == Color::GRAY) return false;
    if (graph[from].empty()) return from == to;

    colors[from] = Color::GRAY;

    for (const int &next : graph[from]) {
      bool hasCycle = !isAcyclic(next, to);
      if (hasCycle) return false;
    }

    colors[from] = Color::BLACK;
    return true;
  }

 public:
  bool leadsToDestination(int n, vector<vector<int>> &edges, int source,
                          int destination) {
    colors.resize(n, Color::WHITE);

    graph.assign(n, vector<int>());
    for (const vector<int> &edge : edges) {
      graph[edge[0]].push_back(edge[1]);
    }

    return isAcyclic(source, destination);
  }
};