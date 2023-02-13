#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use BFS
// time : O(N + E)
// space : O(N + E)
class Solution {
 public:
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges,
                                       vector<vector<int>> &blueEdges) {
    vector<vector<int>> graphRed(n), graphBlue(n);

    for (vector<int> &e : redEdges) {
      int from = e[0], to = e[1];
      graphRed[from].push_back(to);
    }
    for (vector<int> &e : blueEdges) {
      int from = e[0], to = e[1];
      graphBlue[from].push_back(to);
    }

    vector<vector<int>> dists(2, vector<int>(n, INT_MAX));
    queue<pair<int, int>> q;  // node, color
    q.push({0, 0});           // 0 : red
    q.push({0, 1});           // 1 : blue

    int step = 0;
    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        pair<int, int> cur = q.front();

        int node = cur.first, color = cur.second;
        q.pop();
        if (dists[color][node] < step) continue;
        dists[color][node] = step;

        if (color % 2 == 0) {
          // pick blue
          for (int &next : graphBlue[node]) {
            q.push({next, 1});
          }
        } else {
          // pick red
          for (int &next : graphRed[node]) {
            q.push({next, 0});
          }
        }
      }
      step++;
    }

    vector<int> answer(n);
    for (int i = 0; i < n; i++) {
      answer[i] = min(dists[0][i], dists[1][i]);
      if (answer[i] == INT_MAX) answer[i] = -1;
    }
    return answer;
  }
};