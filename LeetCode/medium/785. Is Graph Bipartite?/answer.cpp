#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use BFS with color
// time : O(V + E)
// space : O(V + E)
class Solution {
 public:
  bool isBipartite(vector<vector<int>>& graph) {
    bool answer = true;
    int size = graph.size();

    vector<int> colors(size, -1);
    for (int i = 0; i < size; i++) {
      if (colors[i] != -1) continue;

      queue<int> q;
      int color = 0;
      q.push(i);

      while (!q.empty()) {
        int curSize = q.size();

        while (curSize--) {
          int cur = q.front();
          q.pop();

          if (colors[cur] != -1) {
            if (colors[cur] != color) answer = false;
            continue;
          }

          colors[cur] = color;

          for (int& next : graph[cur]) {
            q.push(next);
          }
        }

        color = color == 0 ? 1 : 0;
      }
    }

    return answer;
  }
};